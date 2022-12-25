cmake_minimum_required(VERSION 3.00)

file(GLOB HDR_FILES *.h)
file(GLOB SRC_FILES *.c)

add_library(libdiameter_cx SHARED ${SRC_FILES} ${HDR_FILES})
target_include_directories(libdiameter_cx PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libdiameter_cx PUBLIC -DOGS_DIAM_COMPILATION)
target_compile_options(libdiameter_cx PUBLIC -Wno-missing-prototypes -Wno-missing-declarations -Wno-discarded-qualifiers -Wno-incompatible-pointer-types -Wno-strict-prototypes)
target_link_libraries(libdiameter_cx libdiameter_common)

set_target_properties(libdiameter_cx PROPERTIES
     OUTPUT_NAME "5g_diameter_cx"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libdiameter_cx
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



