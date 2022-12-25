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

#include "ogs-nas-5gs.h"

void ogs_nas_5gs_tai_list_build(
        ogs_nas_5gs_tracking_area_identity_list_t *target,
        ogs_5gs_tai0_list_t *source0, ogs_5gs_tai2_list_t *source2)
{
    int i = 0, j = 0, size = 0;

    ogs_5gs_tai0_list_t target0;
    ogs_5gs_tai2_list_t target2;
    ogs_nas_plmn_id_t ogs_nas_plmn_id;

    ogs_assert(target);
    ogs_assert(source0);
    ogs_assert(source2);

    memset(target, 0, sizeof(ogs_nas_5gs_tracking_area_identity_list_t));
    memset(&target0, 0, sizeof(ogs_5gs_tai0_list_t));
    memset(&target2, 0, sizeof(ogs_5gs_tai2_list_t));

    for (i = 0; source0->tai[i].num; i++) {
        ogs_assert(source0->tai[i].type == OGS_TAI0_TYPE);
        target0.tai[i].type = source0->tai[i].type;

        /* <Spec> target->num = source->num - 1 */
        ogs_assert(source0->tai[i].num < OGS_MAX_NUM_OF_TAI);
        target0.tai[i].num = source0->tai[i].num - 1;
        memcpy(&target0.tai[i].plmn_id,
            ogs_nas_from_plmn_id(&ogs_nas_plmn_id, &source0->tai[i].plmn_id),
            OGS_PLMN_ID_LEN);

        for (j = 0; j < source0->tai[i].num; j++) {
            target0.tai[i].tac[j] = ogs_htobe24(source0->tai[i].tac[j]);
        }

        size = (1 + 3 + 3 * source0->tai[i].num);
        if ((target->length + size) > OGS_NAS_5GS_MAX_TAI_LIST_LEN) {
            ogs_warn("Overflow: Ignore remained TAI LIST(length:%d, size:%d)",
                    target->length, size);
            return;
        }
        memcpy(target->buffer + target->length, &target0.tai[i], size);
        target->length += size;
    }

    if (source2->num) {
        memset(&target2, 0, sizeof(target2));

        ogs_assert(source2->type == OGS_TAI1_TYPE ||
                    source2->type == OGS_TAI2_TYPE);
        target2.type = source2->type;

        /* <Spec> target->num = source->num - 1 */
        ogs_assert(source2->num < OGS_MAX_NUM_OF_TAI);
        target2.num = source2->num - 1;

        size = (1 + (3 + 3) * source2->num);
        if ((target->length + size) > OGS_NAS_5GS_MAX_TAI_LIST_LEN) {
            ogs_warn("Overflow: Ignore remained TAI LIST(length:%d, size:%d)",
                    target->length, size);
            return;
        }
        for (i = 0; i < source2->num; i++) {
            memcpy(&target2.tai[i].plmn_id,
                    ogs_nas_from_plmn_id(&ogs_nas_plmn_id,
                        &source2->tai[i].plmn_id),
                    OGS_PLMN_ID_LEN);
            target2.tai[i].tac = ogs_htobe24(source2->tai[i].tac);
        }
        memcpy(target->buffer + target->length, &target2, size);
        target->length += size;
    }
}

void ogs_nas_build_s_nssai(
        ogs_nas_s_nssai_t *nas_s_nssai, ogs_nas_s_nssai_ie_t *nas_s_nssai_ie)
{
    int pos;
    ogs_uint24_t v;

    ogs_assert(nas_s_nssai);
    ogs_assert(nas_s_nssai_ie);

    pos = 0;

    if (nas_s_nssai_ie->sst)
        nas_s_nssai->buffer[pos++] = nas_s_nssai_ie->sst;

    if (nas_s_nssai_ie->sd.v != OGS_S_NSSAI_NO_SD_VALUE ||

        /*
         * If the SST encoded in octet 3 is not associated
         * with a valid SD value, and the sender needs to include
         * a mapped HPLMN SST (octet 7) and a mapped HPLMN SD (octets 8 to 10),
         * then the sender shall set the SD value (octets 4 to 6) to
         * "no SD value associated with the SST".
         */
        (nas_s_nssai_ie->sd.v == OGS_S_NSSAI_NO_SD_VALUE &&
         nas_s_nssai_ie->mapped_hplmn_sst &&
         nas_s_nssai_ie->mapped_hplmn_sd.v != OGS_S_NSSAI_NO_SD_VALUE)) {

        v = ogs_htobe24(nas_s_nssai_ie->sd);
        memcpy(nas_s_nssai->buffer+pos, &v, 3);
        pos += 3;
    }

    if (nas_s_nssai_ie->mapped_hplmn_sst)
        nas_s_nssai->buffer[pos++] = nas_s_nssai_ie->mapped_hplmn_sst;

    if (nas_s_nssai_ie->mapped_hplmn_sd.v != OGS_S_NSSAI_NO_SD_VALUE) {
        v = ogs_htobe24(nas_s_nssai_ie->mapped_hplmn_sd);
        memcpy(nas_s_nssai->buffer+pos, &v, 3);
        pos += 3;
    }

    nas_s_nssai->length = pos;
}

void ogs_nas_build_s_nssai2(
        ogs_nas_s_nssai_t *nas_s_nssai,
        ogs_s_nssai_t *s_nssai, ogs_s_nssai_t *mapped_hplmn)
{
    ogs_nas_s_nssai_ie_t ie;

    ogs_assert(nas_s_nssai);
    ogs_assert(s_nssai);
    ogs_assert(mapped_hplmn);

    memset(&ie, 0, sizeof(ie));

    ie.sst = s_nssai->sst;
    ie.sd.v = s_nssai->sd.v;
    ie.mapped_hplmn_sst = mapped_hplmn->sst;
    ie.mapped_hplmn_sd.v = mapped_hplmn->sd.v;

    ogs_nas_build_s_nssai(nas_s_nssai, &ie);
}

int ogs_nas_parse_s_nssai(
        ogs_nas_s_nssai_ie_t *nas_s_nssai_ie, ogs_nas_s_nssai_t *nas_s_nssai)
{
    ogs_uint24_t v;
    int pos = 0;
    bool sst, sd, mapped_hplmn_sst, mapped_hplmn_sd;

    ogs_assert(nas_s_nssai);
    ogs_assert(nas_s_nssai_ie);

    memset(nas_s_nssai_ie, 0, sizeof(*nas_s_nssai_ie));
    nas_s_nssai_ie->sd.v = OGS_S_NSSAI_NO_SD_VALUE;
    nas_s_nssai_ie->mapped_hplmn_sd.v = OGS_S_NSSAI_NO_SD_VALUE;

    if (nas_s_nssai->length == OGS_NAS_S_NSSAI_SST_LEN) {
        sst = true;
        sd = false;
        mapped_hplmn_sst = false;
        mapped_hplmn_sd = false;
    } else if (nas_s_nssai->length ==
            OGS_NAS_S_NSSAI_SST_AND_MAPPED_HPLMN_SST_LEN) {
        sst = true;
        sd = false;
        mapped_hplmn_sst = true;
        mapped_hplmn_sd = false;
    } else if (nas_s_nssai->length == OGS_NAS_S_NSSAI_SST_AND_SD) {
        sst = true;
        sd = true;
        mapped_hplmn_sst = false;
        mapped_hplmn_sd = false;
    } else if (nas_s_nssai->length ==
            OGS_NAS_S_NSSAI_SST_SD_AND_MAPPED_HPLMN_SST_LEN) {
        sst = true;
        sd = true;
        mapped_hplmn_sst = true;
        mapped_hplmn_sd = false;
    } else if (nas_s_nssai->length ==
            OGS_NAS_S_NSSAI_SST_SD_AND_MAPPED_HPLMN_SST_SD_LEN) {
        sst = true;
        sd = true;
        mapped_hplmn_sst = true;
        mapped_hplmn_sd = true;
    } else {
        ogs_error("Cannot parse S-NSSAI [%d]", nas_s_nssai->length);
        ogs_log_hexdump(OGS_ERROR, nas_s_nssai->buffer, nas_s_nssai->length);
        return 0;
    }

    pos = 0;

    if (sst)
        nas_s_nssai_ie->sst = nas_s_nssai->buffer[pos++];

    if (sd) {
        memcpy(&v, nas_s_nssai->buffer+pos, 3);
        nas_s_nssai_ie->sd = ogs_htobe24(v);
        pos += 3;
    }

    if (mapped_hplmn_sst)
        nas_s_nssai_ie->mapped_hplmn_sst = nas_s_nssai->buffer[pos++];

    if (mapped_hplmn_sd) {
        memcpy(&v, nas_s_nssai->buffer+pos, 3);
        nas_s_nssai_ie->mapped_hplmn_sd = ogs_htobe24(v);
        pos += 3;
    }

    return nas_s_nssai->length + 1;
}

void ogs_nas_build_nssai(ogs_nas_nssai_t *nas_nssai,
        ogs_nas_s_nssai_ie_t *nas_s_nssai_ie, int num_of_nas_s_nssai_ie)
{
    int i;
    ogs_nas_s_nssai_t nas_s_nssai;

    ogs_assert(nas_nssai);
    ogs_assert(nas_s_nssai_ie);
    ogs_assert(num_of_nas_s_nssai_ie);

    for (i = 0; i < num_of_nas_s_nssai_ie; i++) {
        if (nas_nssai->length < OGS_NAS_MAX_NSSAI_LEN) {
            ogs_nas_build_s_nssai(&nas_s_nssai, nas_s_nssai_ie + i);
            memcpy(nas_nssai->buffer + nas_nssai->length, &nas_s_nssai,
                    sizeof(nas_s_nssai.length) + nas_s_nssai.length);
            nas_nssai->length += 
                    (sizeof(nas_s_nssai.length) + nas_s_nssai.length);
        }
    }
}

int ogs_nas_parse_nssai(
        ogs_nas_s_nssai_ie_t *nas_s_nssai_ie, ogs_nas_nssai_t *nas_nssai)
{
    int num_of_nas_s_nssai_ie = 0;
    int pos = 0, len;

    ogs_assert(nas_nssai);
    ogs_assert(nas_s_nssai_ie);

    if (!nas_nssai->length) {
        ogs_error("No NSSAI [%p:%d]", nas_nssai->buffer, nas_nssai->length);
        return 0;
    }

    while (pos < nas_nssai->length &&
            num_of_nas_s_nssai_ie < OGS_MAX_NUM_OF_SLICE) {

        len = ogs_nas_parse_s_nssai(nas_s_nssai_ie + num_of_nas_s_nssai_ie,
                (ogs_nas_s_nssai_t *)(nas_nssai->buffer + pos));
        if (len == 0) {
            ogs_error("Cannot parse NSSAI [%d]", nas_nssai->length);
            ogs_log_hexdump(OGS_ERROR, nas_nssai->buffer, nas_nssai->length);
        }

        pos += len;

        num_of_nas_s_nssai_ie++;
    }

    return num_of_nas_s_nssai_ie;
}

void ogs_nas_build_rejected_nssai(
        ogs_nas_rejected_nssai_t *rejected_nssai,
        ogs_nas_rejected_s_nssai_t *rejected_s_nssai,
        int num_of_rejected_s_nssai)
{
    int i;

    ogs_assert(rejected_nssai);
    ogs_assert(rejected_s_nssai);
    ogs_assert(num_of_rejected_s_nssai);

    for (i = 0; i < num_of_rejected_s_nssai; i++) {
        if (rejected_nssai->length < OGS_NAS_MAX_REJECTED_NSSAI_LEN) {
            memcpy(rejected_nssai->buffer + rejected_nssai->length,
                    rejected_s_nssai + i, 1);
            rejected_nssai->length += 1;

            ogs_assert(
                rejected_s_nssai[i].length_of_rejected_s_nssai == 1 ||
                rejected_s_nssai[i].length_of_rejected_s_nssai == 4);

            if (rejected_s_nssai[i].length_of_rejected_s_nssai == 1 ||
                rejected_s_nssai[i].length_of_rejected_s_nssai == 4) {
                rejected_nssai->buffer[rejected_nssai->length] =
                        rejected_s_nssai[i].sst;
                rejected_nssai->length += 1;
            }

            if (rejected_s_nssai[i].length_of_rejected_s_nssai == 4) {
                ogs_uint24_t v;
                v = ogs_htobe24(rejected_s_nssai[i].sd);
                memcpy(rejected_nssai->buffer + rejected_nssai->length, &v, 3);
                rejected_nssai->length += 3;
            }
        }
    }
}

int ogs_nas_parse_rejected_nssai(
        ogs_nas_rejected_s_nssai_t *rejected_s_nssai,
        ogs_nas_rejected_nssai_t *rejected_nssai)
{
    int i, pos;

    ogs_assert(rejected_nssai);
    ogs_assert(rejected_s_nssai);

    if (!rejected_nssai->length) {
        ogs_error("No NSSAI [%p:%d]",
                rejected_nssai->buffer, rejected_nssai->length);
        return OGS_ERROR;
    }

    i = 0;
    pos = 0;
    while (pos < rejected_nssai->length && i < OGS_MAX_NUM_OF_SLICE) {

        ogs_assert((pos + 1) <= rejected_nssai->length);
        memcpy(rejected_s_nssai + i, rejected_nssai->buffer + pos, 1);
        pos += 1;

        ogs_assert(
            rejected_s_nssai[i].length_of_rejected_s_nssai == 1 ||
            rejected_s_nssai[i].length_of_rejected_s_nssai == 4);

        if (rejected_s_nssai[i].length_of_rejected_s_nssai == 1 ||
            rejected_s_nssai[i].length_of_rejected_s_nssai == 4) {
            ogs_assert((pos + 1) <= rejected_nssai->length);
            rejected_s_nssai[i].sst = rejected_nssai->buffer[pos];
            pos += 1;
        }

        if (rejected_s_nssai[i].length_of_rejected_s_nssai == 4) {
            ogs_uint24_t v;

            ogs_assert((pos + 3) <= rejected_nssai->length);
            memcpy(&v, rejected_nssai->buffer + pos, 3);
            rejected_s_nssai[i].sd = ogs_be24toh(v);
            pos += 3;
        }

        i++;
    }

    return i;
}

void ogs_nas_build_qos_flow_descriptions(
    ogs_nas_qos_flow_descriptions_t *flow_descriptions,
    ogs_nas_qos_flow_description_t *flow_description,
    int num_of_flow_description)
{
    int i, j;
    char *buffer;
    uint16_t length;
    ogs_nas_qos_flow_description_t target;

    ogs_assert(flow_descriptions);
    ogs_assert(flow_description);
    ogs_assert(num_of_flow_description);

    buffer = ogs_calloc(1, OGS_NAS_MAX_QOS_FLOW_DESCRIPTIONS_LEN);
    ogs_assert(buffer);
    length = 0;

    for (i = 0; i < num_of_flow_description; i++) {
        memcpy(&target, flow_description + i,
                sizeof(ogs_nas_qos_flow_description_t));

        ogs_assert(length + 3 <= OGS_NAS_MAX_QOS_FLOW_DESCRIPTIONS_LEN);
        memcpy(buffer + length, &target, 3);
        length += 3;

        for (j = 0; j < target.num_of_parameter; j++) {
            ogs_assert(length + sizeof(target.param[j].identifier) <=
                    OGS_NAS_MAX_QOS_FLOW_DESCRIPTIONS_LEN);
            memcpy(buffer + length, &target.param[j].identifier,
                    sizeof(target.param[j].identifier));
            length += sizeof(target.param[j].identifier);

            ogs_assert(length + sizeof(target.param[j].len) <=
                    OGS_NAS_MAX_QOS_FLOW_DESCRIPTIONS_LEN);
            memcpy(buffer + length, &target.param[j].len,
                    sizeof(target.param[j].len));
            length += sizeof(target.param[j].len);

            switch(target.param[j].identifier) {
            case OGS_NAX_QOS_FLOW_PARAMETER_ID_5QI:
                ogs_assert(target.param[j].len == 1);
                ogs_assert(length + target.param[j].len <=
                        OGS_NAS_MAX_QOS_FLOW_DESCRIPTIONS_LEN);
                memcpy(buffer + length, &target.param[j].qos_index,
                        target.param[j].len);
                length += target.param[j].len;
                break;

            case OGS_NAX_QOS_FLOW_PARAMETER_ID_GFBR_UPLINK:
            case OGS_NAX_QOS_FLOW_PARAMETER_ID_GFBR_DOWNLINK:
            case OGS_NAX_QOS_FLOW_PARAMETER_ID_MFBR_UPLINK:
            case OGS_NAX_QOS_FLOW_PARAMETER_ID_MFBR_DOWNLINK:
                ogs_assert(target.param[j].len == 3);
                ogs_assert(length + target.param[j].len <=
                        OGS_NAS_MAX_QOS_FLOW_DESCRIPTIONS_LEN);
                target.param[j].br.value =
                    htobe16(target.param[j].br.value);
                memcpy(buffer + length, &target.param[j].br,
                        target.param[j].len);
                length += target.param[j].len;
                break;
            default:
                ogs_fatal("Unknown qos_flow parameter identifier [%d]",
                        target.param[j].identifier);
                ogs_assert_if_reached();
            }
        }
    }

    flow_descriptions->buffer = buffer;
    flow_descriptions->length = length;
}

void ogs_nas_build_qos_rules(ogs_nas_qos_rules_t *rules,
        ogs_nas_qos_rule_t *rule, int num_of_rule)
{
    int i, j, k;
    char *buffer;
    uint16_t length;
    ogs_nas_qos_rule_t target;

    ogs_assert(rules);
    ogs_assert(rule);
    ogs_assert(num_of_rule);

    buffer = ogs_calloc(1, OGS_NAS_MAX_QOS_RULES_LEN);
    ogs_assert(buffer);
    length = 0;

    for (i = 0; i < num_of_rule; i++) {
        char *rule_length = NULL;

        memcpy(&target, rule + i, sizeof(ogs_nas_qos_rule_t));

        ogs_assert(length + sizeof(target.identifier) <=
                OGS_NAS_MAX_QOS_RULES_LEN);
        memcpy(buffer + length, &target.identifier, sizeof(target.identifier));
        length += sizeof(target.identifier);


        ogs_assert(length + sizeof(target.length) <=
                OGS_NAS_MAX_QOS_RULES_LEN);

        /* Just store the location of the QoS rule length */
        rule_length = buffer+length;

        length += sizeof(target.length);

        ogs_assert(length + sizeof(target.flags) <= OGS_NAS_MAX_QOS_RULES_LEN);
        memcpy(buffer + length, &target.flags, sizeof(target.flags));
        length += sizeof(target.flags);

        for (j = 0; j < target.num_of_packet_filter; j++) {
            ogs_assert(length + sizeof(target.pf[j].flags) <=
                    OGS_NAS_MAX_QOS_RULES_LEN);
            memcpy(buffer + length, &target.pf[j].flags,
                    sizeof(target.pf[j].flags));
            length += sizeof(target.pf[j].flags);

            ogs_assert(length + sizeof(target.pf[j].content.length) <=
                    OGS_NAS_MAX_QOS_RULES_LEN);
            memcpy(buffer + length, &target.pf[j].content.length,
                    sizeof(target.pf[j].content.length));
            length += sizeof(target.pf[j].content.length);

            for (k = 0; k < target.pf[j].content.num_of_component; k++) {
                ogs_assert(length +
                        sizeof(target.pf[j].content.component[k].type) <=
                        OGS_NAS_MAX_QOS_RULES_LEN);
                memcpy(buffer + length, &target.pf[j].content.component[k].type,
                        sizeof(target.pf[j].content.component[k].type));
                length += sizeof(target.pf[j].content.component[k].type);
                switch(target.pf[j].content.component[k].type) {
                case OGS_PACKET_FILTER_MATCH_ALL:
                    break;
                case OGS_PACKET_FILTER_PROTOCOL_IDENTIFIER_NEXT_HEADER_TYPE:
                    ogs_assert(length +
                            sizeof(target.pf[j].content.component[k].proto) <=
                                OGS_NAS_MAX_QOS_RULES_LEN);
                    memcpy(buffer + length,
                            &target.pf[j].content.component[k].proto,
                            sizeof(target.pf[j].content.component[k].proto));
                    length += sizeof(target.pf[j].content.component[k].proto);
                    break;
                case OGS_PACKET_FILTER_IPV4_REMOTE_ADDRESS_TYPE:
                case OGS_PACKET_FILTER_IPV4_LOCAL_ADDRESS_TYPE:
                    ogs_assert(length +
                        sizeof(target.pf[j].content.component[k].ipv4.addr)
                            <= OGS_NAS_MAX_QOS_RULES_LEN);
                    memcpy(buffer + length,
                        &target.pf[j].content.component[k].ipv4.addr,
                        sizeof(target.pf[j].content.component[k].ipv4.addr));
                    length +=
                        sizeof(target.pf[j].content.component[k].ipv4.addr);

                    ogs_assert(length +
                        sizeof(target.pf[j].content.component[k].ipv4.mask)
                            <= OGS_NAS_MAX_QOS_RULES_LEN);
                    memcpy(buffer + length,
                        &target.pf[j].content.component[k].ipv4.mask,
                        sizeof(target.pf[j].content.component[k].ipv4.mask));
                    length +=
                        sizeof(target.pf[j].content.component[k].ipv4.mask);
                    break;
                case OGS_PACKET_FILTER_IPV6_REMOTE_ADDRESS_PREFIX_LENGTH_TYPE:
                case OGS_PACKET_FILTER_IPV6_LOCAL_ADDRESS_PREFIX_LENGTH_TYPE:
                    ogs_assert(length +
                        sizeof(target.pf[j].content.component[k].ipv6.addr)
                            <= OGS_NAS_MAX_QOS_RULES_LEN);
                    memcpy(buffer + length,
                        &target.pf[j].content.component[k].ipv6.addr,
                        sizeof(target.pf[j].content.component[k].ipv6.addr));
                    length +=
                        sizeof(target.pf[j].content.component[k].ipv6.addr);

                    ogs_assert(length +
                        sizeof(target.pf[j].content.component[k].ipv6.prefixlen)
                            <= OGS_NAS_MAX_QOS_RULES_LEN);
                    memcpy(buffer + length,
                        &target.pf[j].content.component[k].ipv6.prefixlen,
                        sizeof(
                            target.pf[j].content.component[k].ipv6.prefixlen));
                    length += sizeof(
                            target.pf[j].content.component[k].ipv6.prefixlen);
                    break;
                case OGS_PACKET_FILTER_IPV6_REMOTE_ADDRESS_TYPE:
                case OGS_PACKET_FILTER_IPV6_LOCAL_ADDRESS_TYPE:
                    ogs_assert(length +
                        sizeof(target.pf[j].content.component[k].ipv6_mask.addr)
                            <= OGS_NAS_MAX_QOS_RULES_LEN);
                    memcpy(buffer + length,
                        &target.pf[j].content.component[k].ipv6_mask.addr,
                        sizeof(
                            target.pf[j].content.component[k].ipv6_mask.addr));
                    length += sizeof(
                            target.pf[j].content.component[k].ipv6_mask.addr);

                    ogs_assert(length +
                        sizeof(target.pf[j].content.component[k].ipv6_mask.mask)
                            <= OGS_NAS_MAX_QOS_RULES_LEN);
                    memcpy(buffer + length,
                        &target.pf[j].content.component[k].ipv6_mask.mask,
                        sizeof(
                            target.pf[j].content.component[k].ipv6_mask.mask));
                    length += sizeof(
                            target.pf[j].content.component[k].ipv6_mask.mask);
                    break;
                case OGS_PACKET_FILTER_SINGLE_LOCAL_PORT_TYPE:
                case OGS_PACKET_FILTER_SINGLE_REMOTE_PORT_TYPE:
                    ogs_assert(length +
                        sizeof(target.pf[j].content.component[k].port.low)
                            <= OGS_NAS_MAX_QOS_RULES_LEN);
                    target.pf[j].content.component[k].port.low =
                        htobe16(target.pf[j].content.component[k].port.low);
                    memcpy(buffer + length,
                        &target.pf[j].content.component[k].port.low,
                        sizeof(target.pf[j].content.component[k].port.low));
                    length +=
                        sizeof(target.pf[j].content.component[k].port.low);
                    break;
                case OGS_PACKET_FILTER_LOCAL_PORT_RANGE_TYPE:
                case OGS_PACKET_FILTER_REMOTE_PORT_RANGE_TYPE:
                    ogs_assert(length +
                        sizeof(target.pf[j].content.component[k].port.low)
                            <= OGS_NAS_MAX_QOS_RULES_LEN);
                    target.pf[j].content.component[k].port.low =
                        htobe16(target.pf[j].content.component[k].port.low);
                    memcpy(buffer + length,
                            &target.pf[j].content.component[k].port.low,
                            sizeof(target.pf[j].content.component[k].port.low));
                    length +=
                        sizeof(target.pf[j].content.component[k].port.low);

                    ogs_assert(length +
                        sizeof(target.pf[j].content.component[k].port.high)
                            <= OGS_NAS_MAX_QOS_RULES_LEN);
                    target.pf[j].content.component[k].port.high =
                        htobe16(target.pf[j].content.component[k].port.high);
                    memcpy(buffer + length,
                        &target.pf[j].content.component[k].port.high,
                        sizeof(target.pf[j].content.component[k].port.high));
                    length +=
                        sizeof(target.pf[j].content.component[k].port.high);
                    break;
                default:
                    ogs_fatal("Unknown Packet Filter Type(%d)",
                            target.pf[j].content.component[k].type);
                    ogs_assert_if_reached();
                }
            }
        }

        ogs_assert(length + sizeof(target.precedence) <=
                OGS_NAS_MAX_QOS_RULES_LEN);
        memcpy(buffer + length, &target.precedence, sizeof(target.precedence));
        length += sizeof(target.precedence);
        ogs_assert(length + sizeof(target.flow.flags) <=
                OGS_NAS_MAX_QOS_RULES_LEN);
        memcpy(buffer + length, &target.flow.flags, sizeof(target.precedence));
        length += sizeof(target.flow.flags);

        /* Update QoS Rule Length */
        target.length = htobe16(
                buffer+length - rule_length - sizeof(target.length));
        memcpy(rule_length, &target.length, sizeof(target.length));
    }

    rules->buffer = buffer;
    rules->length = length;
}
