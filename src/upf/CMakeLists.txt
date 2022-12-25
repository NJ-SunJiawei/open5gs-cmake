cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    rule-match.h
    event.h
    timer.h
    context.h
    upf-sm.h
    gtp-path.h
    pfcp-path.h
    n4-build.h
    n4-handler.h
    rule-match.c
    init.c
    event.c
    timer.c
    context.c
    upf-sm.c
    pfcp-sm.c
    gtp-path.c
    pfcp-path.c
    n4-build.c
    n4-handler.c
)

INCLUDE (CheckIncludeFiles)
INCLUDE (CheckFunctionExists)
CHECK_INCLUDE_FILES(net/if.h HAVE_NET_IF_H)
CHECK_INCLUDE_FILES(netinet/ip.h HAVE_NETINET_IP_H)
CHECK_INCLUDE_FILES(netinet/ip6.h HAVE_NETINET_IP6_H)
CHECK_INCLUDE_FILES(netinet/ip_icmp.h HAVE_NETINET_IP_ICMP_H)
CHECK_INCLUDE_FILES(netinet/icmp6.h HAVE_NETINET_ICMP6_H)
CHECK_FUNCTION_EXISTS(kqueue HAVE_KQUEUE)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/upf-config.h.in ${CMAKE_CURRENT_BINARY_DIR}/upf-config.h)

add_library(upf STATIC ${SRC_FILES})
target_include_directories(upf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(upf libapp libdiameter_gx libgtp libpfcp libtun)

add_executable(open5gs-upfd ${5GCORE_MAIN_SRCS} app.c)
target_compile_options(open5gs-upfd PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/upf.yaml")
target_link_libraries(open5gs-upfd upf)

install(TARGETS open5gs-upfd
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



