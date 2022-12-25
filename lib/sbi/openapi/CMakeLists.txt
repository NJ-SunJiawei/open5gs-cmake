cmake_minimum_required(VERSION 3.00)

file(GLOB_RECURSE HDR_FILES *.h)
file(GLOB_RECURSE SRC_FILES *.c)

add_library(libsbi_openapi SHARED ${SRC_FILES} ${HDR_FILES})
target_include_directories(libsbi_openapi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libsbi_openapi PUBLIC -DOGS_SBI_COMPILATION)
target_compile_options(libsbi_openapi PUBLIC -Wno-strict-prototypes -Wno-missing-prototypes -Wno-missing-declarations -Wno-unused-variable -Wno-unused-label -Wno-float-equal)
target_link_libraries(libsbi_openapi libcore)

set_target_properties(libsbi_openapi PROPERTIES
     OUTPUT_NAME "5g_sbi_openapi"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libsbi_openapi
        LIBRARY DESTINATION ${5GCORE_INSTALl_LIB_PATH}
		COMPONENT 5glib)



