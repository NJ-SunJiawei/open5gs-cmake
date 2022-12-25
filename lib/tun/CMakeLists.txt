cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    ogs-tun.h
    tunio.c
)

IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(SRC_FILES ${SRC_FILES} linux-setup.c)
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(SRC_FILES ${SRC_FILES} windows-setup.c)
ELSE()
    set(SRC_FILES ${SRC_FILES} mac-setup.c)
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Linux")

add_library(libtun SHARED ${SRC_FILES})
target_include_directories(libtun PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libtun PUBLIC -DOGS_TUN_COMPILATION)
target_link_libraries(libtun libcore libipfw)

set_target_properties(libtun PROPERTIES
     OUTPUT_NAME "5g_tun"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libtun
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



