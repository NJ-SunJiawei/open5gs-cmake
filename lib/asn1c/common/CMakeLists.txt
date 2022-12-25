cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    ANY.h
    ANY.c
    OCTET_STRING.h
    OPEN_TYPE.h
    OPEN_TYPE.c
    constr_CHOICE.h
    GraphicString.h
    GraphicString.c
    INTEGER.h
    INTEGER.c
    NULL.h
    NULL.c
    NativeEnumerated.h
    NativeEnumerated.c
    NativeInteger.h
    NativeInteger.c
    OBJECT_IDENTIFIER.h
    OBJECT_IDENTIFIER.c
    asn_codecs_prim.h
    ObjectDescriptor.h
    ObjectDescriptor.c
    PrintableString.h
    PrintableString.c
    UTF8String.h
    UTF8String.c
    VisibleString.h
    VisibleString.c
    asn_SEQUENCE_OF.h
    asn_SEQUENCE_OF.c
    asn_SET_OF.h
    asn_SET_OF.c
    constr_CHOICE.c
    constr_SEQUENCE.h
    constr_SEQUENCE.c
    constr_SEQUENCE_OF.h
    constr_SEQUENCE_OF.c
    constr_SET_OF.h
    constr_SET_OF.c
    asn_application.h
    asn_application.c
    asn_ioc.h
    asn_system.h
    asn_codecs.h
    asn_internal.h
    asn_internal.c
    asn_bit_data.h
    asn_bit_data.c
    OCTET_STRING.c
    BIT_STRING.h
    BIT_STRING.c
    asn_codecs_prim.c
    ber_tlv_length.h
    ber_tlv_length.c
    ber_tlv_tag.h
    ber_tlv_tag.c
    constr_TYPE.h
    constr_TYPE.c
    constraints.h
    constraints.c
    per_decoder.h
    per_encoder.h
    per_support.h
    per_opentype.h
    per_decoder.c
    per_encoder.c
    per_support.c
    per_opentype.c
    aper_decoder.h
    aper_encoder.h
    aper_support.h
    aper_opentype.h
    aper_decoder.c
    aper_encoder.c
    aper_support.c
    aper_opentype.c
    ANY_aper.c
    INTEGER_aper.c
    NULL_aper.c
    NativeEnumerated_aper.c
    NativeInteger_aper.c
    OCTET_STRING_aper.c
    OPEN_TYPE_aper.c
    constr_CHOICE_aper.c
    constr_SEQUENCE_OF_aper.c
    constr_SEQUENCE_aper.c
    constr_SET_OF_aper.c
    BIT_STRING_print.c
    INTEGER_print.c
    NULL_print.c
    NativeInteger_print.c
    OBJECT_IDENTIFIER_print.c
    OCTET_STRING_print.c
    UTF8String_print.c
    constr_CHOICE_print.c
    constr_SEQUENCE_print.c
    constr_SET_OF_print.c
    asn_random_fill.h
    asn_random_fill.c
    BIT_STRING_rfill.c
    INTEGER_rfill.c
    NULL_rfill.c
    NativeInteger_rfill.c
    OBJECT_IDENTIFIER_rfill.c
    OCTET_STRING_rfill.c
    UTF8String_rfill.c
    constr_CHOICE_rfill.c
    constr_SEQUENCE_rfill.c
    constr_SET_OF_rfill.c
)

add_library(libasn1c_common SHARED ${SRC_FILES})
target_include_directories(libasn1c_common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libasn1c_common PUBLIC -DASN_DISABLE_BER_SUPPORT -DASN_DISABLE_XER_SUPPORT -DASN_DISABLE_OER_SUPPORT -DASN_DISABLE_UPER_SUPPORT)
target_compile_options(libasn1c_common PUBLIC -w -std=gnu99)
target_link_libraries(libasn1c_common libcore)

set_target_properties(libasn1c_common PROPERTIES
     OUTPUT_NAME "5g_asn1c_common"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libasn1c_common
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



