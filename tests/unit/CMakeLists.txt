cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    abts-main.c
    s1ap-message-test.c
    nas-message-test.c
    gtp-message-test.c
    ngap-message-test.c
    sbi-message-test.c
    security-test.c
    crash-test.c
)

add_executable(unit ${SRC_FILES})
target_include_directories(unit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(unit PUBLIC -DOGS_SBI_COMPLIATION)
target_compile_options(unit PUBLIC -Wno-missing-prototypes -Wno-missing-declarations -Wno-discarded-qualifiers -Wno-incompatible-pointer-types -Wno-unused-variable -Wno-deprecated-declarations)
target_link_libraries(unit libs1ap libgtp libngap libnas_eps libsbi)


