cmake_minimum_required(VERSION 3.00)

file(GLOB HDR_FILES *.h)
file(GLOB SRC_FILES *.c)

add_library(libnas_5gs SHARED ${SRC_FILES} ${HDR_FILES})
target_include_directories(libnas_5gs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libnas_5gs PUBLIC -DOGS_NAS_COMPILATION)
target_link_libraries(libnas_5gs libnas_common)

set_target_properties(libnas_5gs PROPERTIES
     OUTPUT_NAME "5g_nas_5gs"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libnas_5gs
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



