cmake_minimum_required(VERSION 3.00)

file(GLOB HDR_FILES *.h)
file(GLOB SRC_FILES *.c)

add_library(libs1ap SHARED ${SRC_FILES} ${HDR_FILES})
target_include_directories(libs1ap PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libs1ap PUBLIC -DOGS_NGAP_COMPILATION)
target_link_libraries(libs1ap libasn1c_s1ap)

set_target_properties(libs1ap PROPERTIES
     OUTPUT_NAME "5gs1ap"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libs1ap
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



