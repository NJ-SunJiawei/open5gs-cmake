cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    list-test.c
    pool-test.c
    strings-test.c
    time-test.c
    conv-test.c
    log-test.c
    pkbuf-test.c
    memory-test.c
    rbtree-test.c
    timer-test.c
    thread-test.c
    socket-test.c
    queue-test.c
    poll-test.c
    tlv-test.c
    fsm-test.c
    hash-test.c
    uuid-test.c
    abts-main.c
)

add_executable(core ${SRC_FILES})
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(core PUBLIC -Wno-missing-prototypes -Wno-missing-declarations -Wno-discarded-qualifiers -Wno-incompatible-pointer-types -Wno-unused-variable -Wno-deprecated-declarations)
target_link_libraries(core libcore)


