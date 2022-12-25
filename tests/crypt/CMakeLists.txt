cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    aes-test.c
    sha-test.c
    base64-test.c
    abts-main.c
)

add_executable(crypt ${SRC_FILES})
target_include_directories(crypt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(crypt PUBLIC -Wno-missing-prototypes -Wno-missing-declarations -Wno-discarded-qualifiers -Wno-incompatible-pointer-types -Wno-unused-variable -Wno-deprecated-declarations)
target_link_libraries(crypt libcrypt)


