/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r16.4.0/38413-g40.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER`
 */

#ifndef	_NGAP_EN_DCSONConfigurationTransfer_H_
#define	_NGAP_EN_DCSONConfigurationTransfer_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NGAP_EN-DCSONConfigurationTransfer */
typedef OCTET_STRING_t	 NGAP_EN_DCSONConfigurationTransfer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_EN_DCSONConfigurationTransfer;
asn_struct_free_f NGAP_EN_DCSONConfigurationTransfer_free;
asn_struct_print_f NGAP_EN_DCSONConfigurationTransfer_print;
asn_constr_check_f NGAP_EN_DCSONConfigurationTransfer_constraint;
per_type_decoder_f NGAP_EN_DCSONConfigurationTransfer_decode_aper;
per_type_encoder_f NGAP_EN_DCSONConfigurationTransfer_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_EN_DCSONConfigurationTransfer_H_ */
#include <asn_internal.h>
