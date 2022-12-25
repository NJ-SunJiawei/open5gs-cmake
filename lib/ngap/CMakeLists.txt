cmake_minimum_required(VERSION 3.00)

file(GLOB HDR_FILES *.h)
file(GLOB SRC_FILES *.c)

add_library(libngap SHARED ${SRC_FILES} ${HDR_FILES})
target_include_directories(libngap PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libngap PUBLIC -DOGS_S1AP_COMPILATION)
target_link_libraries(libngap libasn1c_ngap)

set_target_properties(libngap PROPERTIES
     OUTPUT_NAME "5g_ngap"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libngap
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



