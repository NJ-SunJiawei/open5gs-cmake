cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    event.h
    timer.h
    context.h
    smf-sm.h
    gtp-path.h
    s5c-build.h
    s5c-handler.h
    fd-path.h
    gx-handler.h
    pfcp-path.h
    n4-build.h
    n4-handler.h
    binding.h
    nnrf-build.h
    nnrf-handler.h
    nudm-build.h
    nudm-handler.h
    nsmf-handler.h
    namf-build.h
    namf-handler.h
    npcf-build.h
    npcf-handler.h
    sbi-path.h
    gsm-build.h
    gsm-handler.h
    nas-path.h
    ngap-build.h
    ngap-handler.h
    ngap-path.h
    init.c
    event.c
    timer.c
    context.c
    smf-sm.c
    nf-sm.c
    gsm-sm.c
    pfcp-sm.c
    gtp-path.c
    s5c-build.c
    s5c-handler.c 
    fd-path.c
    gx-handler.c 
    pfcp-path.c
    n4-build.c
    n4-handler.c
    binding.c
    nnrf-build.c
    nnrf-handler.c
    nudm-build.c
    nudm-handler.c
    nsmf-handler.c
    namf-build.c
    namf-handler.c
    npcf-build.c
    npcf-handler.c
    sbi-path.c
    gsm-build.c
    gsm-handler.c
    nas-path.c
    ngap-build.c
    ngap-handler.c
    ngap-path.c
)

INCLUDE (CheckIncludeFiles)
CHECK_INCLUDE_FILES(net/if.h HAVE_NET_IF_H)
CHECK_INCLUDE_FILES(netinet/ip.h HAVE_NETINET_IP_H)
CHECK_INCLUDE_FILES(netinet/ip6.h HAVE_NETINET_IP6_H)
CHECK_INCLUDE_FILES(netinet/ip_icmp.h HAVE_NETINET_IP_ICMP_H)
CHECK_INCLUDE_FILES(netinet/icmp6.h HAVE_NETINET_ICMP6_H)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/smf-config.h.in ${CMAKE_CURRENT_BINARY_DIR}/smf-config.h)

add_library(smf STATIC ${SRC_FILES})
target_include_directories(smf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(smf libapp libsbi libngap libnas_5gs libdiameter_gx libgtp libpfcp)

add_executable(open5gs-smfd ${5GCORE_MAIN_SRCS} app.c)
target_compile_options(open5gs-smfd PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/smf.yaml")
target_link_libraries(open5gs-smfd smf)

install(TARGETS open5gs-smfd
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



