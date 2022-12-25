cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    abts-main.c
    sctp-test.c
)

add_executable(sctp ${SRC_FILES})
target_include_directories(sctp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(sctp PUBLIC -Wno-missing-prototypes -Wno-missing-declarations -Wno-discarded-qualifiers -Wno-incompatible-pointer-types -Wno-unused-variable -Wno-deprecated-declarations)
target_link_libraries(sctp libsctp)


