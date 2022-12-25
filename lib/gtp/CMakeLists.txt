cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    ogs-gtp.h
    message.h
    types.h
    conv.h
    context.h
    build.h
    path.h
    xact.h
    util.h
    message.c
    types.c
    conv.c
    context.c
    build.c
    path.c
    xact.c
    util.c
)

add_library(libgtp SHARED ${SRC_FILES})
target_include_directories(libgtp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libgtp PUBLIC -DOGS_GTP_COMPILATION)
target_link_libraries(libgtp libcore libapp)

set_target_properties(libgtp PROPERTIES
     OUTPUT_NAME "5g_gtp"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libgtp
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



