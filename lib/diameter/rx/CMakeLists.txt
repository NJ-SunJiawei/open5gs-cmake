cmake_minimum_required(VERSION 3.00)

file(GLOB HDR_FILES *.h)
file(GLOB SRC_FILES *.c)

add_library(libdiameter_rx SHARED ${SRC_FILES} ${HDR_FILES})
target_include_directories(libdiameter_rx PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libdiameter_rx PUBLIC -DOGS_DIAM_COMPILATION)
target_compile_options(libdiameter_rx PUBLIC -Wno-missing-prototypes -Wno-missing-declarations -Wno-discarded-qualifiers -Wno-incompatible-pointer-types -Wno-strict-prototypes)
target_link_libraries(libdiameter_rx libdiameter_common)

set_target_properties(libdiameter_rx PROPERTIES
     OUTPUT_NAME "5g_diameter_rx"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libdiameter_rx
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



