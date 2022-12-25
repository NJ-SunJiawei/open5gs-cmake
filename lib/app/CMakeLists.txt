cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    ogs-app.h
    ogs-yaml.h
    ogs-context.h
    ogs-init.h
    ogs-yaml.c
    ogs-context.c
    ogs-init.c
)

add_library(libapp SHARED ${SRC_FILES})
target_include_directories(libapp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libapp PUBLIC -DOGS_APP_COMPILATION)
target_link_libraries(libapp libcore)
target_link_libraries(libapp yaml pthread)

set_target_properties(libapp PROPERTIES
     OUTPUT_NAME "5g_app"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libapp
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



