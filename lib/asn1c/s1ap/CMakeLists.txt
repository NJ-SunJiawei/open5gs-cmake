cmake_minimum_required(VERSION 3.00)

file(GLOB HDR_FILES *.h)
file(GLOB SRC_FILES *.c)

add_library(libasn1c_s1ap SHARED ${SRC_FILES} ${HDR_FILES})
target_include_directories(libasn1c_s1ap PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libasn1c_s1ap PUBLIC -DASN_DISABLE_BER_SUPPORT -DASN_DISABLE_XER_SUPPORT -DASN_DISABLE_OER_SUPPORT -DASN_DISABLE_UPER_SUPPORT)
target_compile_options(libasn1c_s1ap PUBLIC -w -std=gnu99)
target_link_libraries(libasn1c_s1ap libasn1c_common libasn1c_util)

set_target_properties(libasn1c_s1ap PROPERTIES
     OUTPUT_NAME "5g_asn1c_s1ap"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libasn1c_s1ap
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



