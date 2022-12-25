cmake_minimum_required(VERSION 3.00)

file(GLOB HDR_FILES *.h)
file(GLOB SRC_FILES *.c)

INCLUDE (CheckIncludeFiles)
CHECK_INCLUDE_FILES(netinet/ip.h HAVE_NETINET_IP_H)
CHECK_INCLUDE_FILES(netinet/ip6.h HAVE_NETINET_IP6_H)
CHECK_INCLUDE_FILES(netinet/tcp.h HAVE_NETINET_TCP_H)
CHECK_INCLUDE_FILES(netinet/udp.h HAVE_NETINET_UDP_H)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/pfcp-config.h.in ${CMAKE_CURRENT_BINARY_DIR}/pfcp-config.h)

add_library(libpfcp SHARED ${SRC_FILES} ${HDR_FILES})
target_include_directories(libpfcp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libpfcp PUBLIC -DOGS_PFCP_COMPILATION)
target_link_libraries(libpfcp libcore libipfw libapp libgtp)

set_target_properties(libpfcp PROPERTIES
     OUTPUT_NAME "5g_pfcp"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libpfcp
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



