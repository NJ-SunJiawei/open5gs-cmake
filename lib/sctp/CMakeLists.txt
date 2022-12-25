cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    ogs-sctp.h
    ogs-sctp.c
    ogs-lksctp.c
)

INCLUDE (CheckIncludeFiles)
CHECK_INCLUDE_FILES(netinet/sctp.h HAVE_NETINET_SCTP_H)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sctp-config.h.in ${CMAKE_CURRENT_BINARY_DIR}/sctp-config.h)

add_library(libsctp SHARED ${SRC_FILES})
target_include_directories(libsctp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libsctp PUBLIC -DOGS_SCTP_COMPILATION)
target_link_libraries(libsctp libapp sctp)

set_target_properties(libsctp PROPERTIES
     OUTPUT_NAME "5g_sctp"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libsctp
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



