cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    ogs-crypt.h
    ogs-aes.h
    ogs-aes-cmac.h
    ogs-sha1.h
    ogs-sha1-hmac.h
    ogs-sha2.h
    ogs-sha2-hmac.h
    milenage.h
    snow-3g.h
    zuc.h
    kasumi.h
    ogs-kdf.h
    ogs-aes.c
    ogs-aes-cmac.c
    ogs-sha1.c
    ogs-sha1-hmac.c
    ogs-sha2.c
    ogs-sha2-hmac.c
    milenage.c
    snow-3g.c
    zuc.c
    kasumi.c
    ogs-kdf.c
    ogs-base64.c
)

add_library(libcrypt SHARED ${SRC_FILES})
target_include_directories(libcrypt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libcrypt PUBLIC -DOGS_CRYPT_COMPILATION)
target_link_libraries(libcrypt libcore)

set_target_properties(libcrypt PROPERTIES
     OUTPUT_NAME "5g_crypt"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libcrypt
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



