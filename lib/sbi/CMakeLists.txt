cmake_minimum_required(VERSION 3.00)

add_subdirectory(openapi)

set(SRC_FILES
    contrib/multipart_parser.c
    custom/links.c
    yuarel.c
    conv.c
    message.c
    mhd-server.c
    nghttp2-server.c
    server.c
    client.c
    context.c
    nnrf-build.c
    nnrf-handler.c
    path.c
)

add_library(libsbi SHARED ${SRC_FILES})
target_include_directories(libsbi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libsbi PUBLIC -DOGS_SBI_COMPILATION)
target_link_libraries(libsbi libcore libcrypt libapp libsbi_openapi)
target_link_libraries(libsbi gnutls nghttp2 microhttpd curl)

set_target_properties(libsbi PROPERTIES
     OUTPUT_NAME "5g_sbi"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libsbi
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



