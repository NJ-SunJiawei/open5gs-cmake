cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    ogs-dbi.h

    ogs-mongoc.h

    ogs-mongoc.c
    subscription.c
    session.c
    ims.c
)

include_directories(${LINUX_HEADER_PATH}/libmongoc-1.0/mongoc
                    ${LINUX_HEADER_PATH}/libmongoc-1.0
					${LINUX_HEADER_PATH}/libbson-1.0)

add_library(libdbi SHARED ${SRC_FILES})
target_include_directories(libdbi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libdbi PUBLIC -DOGS_DBI_COMPILATION)
target_link_libraries(libdbi libcrypt mongoc-1.0)

set_target_properties(libdbi PROPERTIES
     OUTPUT_NAME "5g_dbi"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libdbi
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



