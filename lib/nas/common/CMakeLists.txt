cmake_minimum_required(VERSION 3.00)

file(GLOB HDR_FILES *.h)
file(GLOB SRC_FILES *.c)

add_library(libnas_common SHARED ${SRC_FILES} ${HDR_FILES})
target_include_directories(libnas_common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libnas_common PUBLIC -DOGS_NAS_COMPILATION)
target_link_libraries(libnas_common libcore libcrypt)

set_target_properties(libnas_common PROPERTIES
     OUTPUT_NAME "5g_nas_common"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libnas_common
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



