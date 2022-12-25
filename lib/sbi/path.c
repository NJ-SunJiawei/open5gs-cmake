/*
 * Copyright (C) 2019,2020 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "ogs-sbi.h"
#include "ogs-app.h"

void ogs_sbi_send(ogs_sbi_nf_instance_t *nf_instance,
        ogs_sbi_client_cb_f client_cb, ogs_sbi_xact_t *xact)
{
    ogs_sbi_request_t *request = NULL;
    ogs_sbi_client_t *client = NULL;
    ogs_sbi_object_t *sbi_object = NULL;

    ogs_assert(xact);
    sbi_object = xact->sbi_object;
    ogs_assert(sbi_object);
    request = xact->request;
    ogs_assert(request);

    ogs_assert(nf_instance);

    if (request->h.uri == NULL) {
        client = ogs_sbi_client_find_by_service_name(nf_instance,
                request->h.service.name, request->h.api.version);
        if (!client) {
            ogs_error("[%s] Cannot find client [%s:%s]",
                    nf_instance->id,
                    request->h.service.name, request->h.api.version);
            return;
        }
    } else {
        ogs_sockaddr_t *addr = NULL;
        char buf[OGS_ADDRSTRLEN];

        addr = ogs_sbi_getaddr_from_uri(request->h.uri);
        if (!addr) {
            ogs_error("[%s] Invalid URL [%s]", nf_instance->id, request->h.uri);
            return;
        }
        client = ogs_sbi_client_find(addr);
        if (!client) {
            ogs_error("[%s] Cannot find client [%s:%d]", nf_instance->id,
                    OGS_ADDR(addr, buf), OGS_PORT(addr));
            ogs_freeaddrinfo(addr);
            return;
        }
        ogs_freeaddrinfo(addr);
    }

    ogs_sbi_client_send_request(
            client, client_cb, request, xact);

    /* Prevent ogs_sbi_request_free() in ogs_sbi_xact_remove() */
    xact->request = NULL;
}

bool ogs_sbi_discover_and_send(ogs_sbi_xact_t *xact,
        ogs_fsm_handler_t nf_state_registered, ogs_sbi_client_cb_f client_cb)
{
    ogs_sbi_nf_instance_t *nf_instance = NULL;

    ogs_assert(xact);
    ogs_assert(xact->sbi_object);
    ogs_assert(xact->target_nf_type);
    ogs_assert(nf_state_registered);
    ogs_assert(client_cb);

    /* Target NF-Instance */
    nf_instance = OGS_SBI_NF_INSTANCE(xact->sbi_object, xact->target_nf_type);
    if (!nf_instance) {
        ogs_assert(xact->target_nf_type != OpenAPI_nf_type_NRF);
        ogs_sbi_select_first_nf(
                xact->sbi_object, xact->target_nf_type, nf_state_registered);
        nf_instance = OGS_SBI_NF_INSTANCE(
                xact->sbi_object, xact->target_nf_type);
    }

    if (nf_instance) {
        ogs_sbi_send(nf_instance, client_cb, xact);
        return true;
    }

    /* NRF NF-Instance */
    nf_instance = OGS_SBI_NF_INSTANCE(xact->sbi_object, OpenAPI_nf_type_NRF);
    if (!nf_instance) {
        ogs_sbi_select_nrf(xact->sbi_object, nf_state_registered);
        nf_instance = OGS_SBI_NF_INSTANCE(
                xact->sbi_object, OpenAPI_nf_type_NRF);
    }

    if (nf_instance) {
        ogs_warn("Try to discover [%s]",
                    OpenAPI_nf_type_ToString(xact->target_nf_type));
        ogs_nnrf_disc_send_nf_discover(nf_instance, xact->target_nf_type, xact);

        return true;
    }

    ogs_error("Cannot discover [%s]",
                OpenAPI_nf_type_ToString(xact->target_nf_type));

    return false;
}

void ogs_nnrf_nfm_send_nf_update(ogs_sbi_nf_instance_t *nf_instance)
{
    ogs_sbi_request_t *request = NULL;
    ogs_sbi_client_t *client = NULL;

    ogs_assert(nf_instance);
    client = nf_instance->client;
    ogs_assert(client);

    request = ogs_nnrf_nfm_build_update(nf_instance);
    if (!request) {
        ogs_error("ogs_nnrf_nfm_send_nf_update() failed");
        return;
    }
    ogs_sbi_client_send_request(client, client->cb, request, nf_instance);
}

void ogs_nnrf_nfm_send_nf_de_register(ogs_sbi_nf_instance_t *nf_instance)
{
    ogs_sbi_request_t *request = NULL;
    ogs_sbi_client_t *client = NULL;

    ogs_assert(nf_instance);
    client = nf_instance->client;
    ogs_assert(client);

    request = ogs_nnrf_nfm_build_de_register(nf_instance);
    if (!request) {
        ogs_error("ogs_nnrf_nfm_send_nf_de_register() failed");
        return;
    }
    ogs_sbi_client_send_request(client, client->cb, request, nf_instance);
}

void ogs_nnrf_nfm_send_nf_status_subscribe(ogs_sbi_client_t *client,
        OpenAPI_nf_type_e req_nf_type, char *req_nf_instance_id,
        OpenAPI_nf_type_e subscr_cond_nf_type)
{
    ogs_sbi_request_t *request = NULL;
    ogs_sbi_subscription_t *subscription = NULL;

    ogs_assert(client);

    subscription = ogs_sbi_subscription_add();
    ogs_assert(subscription);

    OGS_SETUP_SBI_CLIENT(subscription, client);
    subscription->req_nf_type = req_nf_type;
    if (req_nf_instance_id)
        subscription->req_nf_instance_id = ogs_strdup(req_nf_instance_id);
    subscription->subscr_cond.nf_type = subscr_cond_nf_type;

    request = ogs_nnrf_nfm_build_status_subscribe(subscription);
    if (!request) {
        ogs_error("ogs_nnrf_nfm_send_nf_status_subscribe() failed");
        ogs_sbi_subscription_remove(subscription);
        return;
    }
    ogs_sbi_client_send_request(client, client->cb, request, subscription);
}

void ogs_nnrf_nfm_send_nf_status_unsubscribe(
        ogs_sbi_subscription_t *subscription)
{
    ogs_sbi_request_t *request = NULL;
    ogs_sbi_client_t *client = NULL;

    ogs_assert(subscription);
    client = subscription->client;
    ogs_assert(client);

    request = ogs_nnrf_nfm_build_status_unsubscribe(subscription);
    if (!request) {
        ogs_error("ogs_nnrf_nfm_send_nf_status_unsubscribe() failed");
        return;
    }
    ogs_sbi_client_send_request(client, client->cb, request, subscription);
}

void ogs_nnrf_disc_send_nf_discover(ogs_sbi_nf_instance_t *nf_instance,
        OpenAPI_nf_type_e target_nf_type, void *data)
{
    ogs_sbi_client_t *client = NULL;
    ogs_sbi_request_t *request = NULL;

    ogs_assert(nf_instance);
    ogs_assert(nf_instance->nf_type);
    client = nf_instance->client;
    ogs_assert(client);

    request = ogs_nnrf_disc_build_discover(
            target_nf_type, nf_instance->nf_type);
    ogs_assert(request);
    ogs_sbi_client_send_request(client, client->cb, request, data);
}
