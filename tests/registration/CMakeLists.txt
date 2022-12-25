cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    abts-main.c
    guti-test.c
    auth-test.c
    idle-test.c
    dereg-test.c
    paging-test.c
    identity-test.c
    gmm-status-test.c
    ue-context-test.c
    reset-test.c
)

add_executable(registration ${SRC_FILES})
target_include_directories(registration PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(registration PUBLIC -Wno-missing-prototypes -Wno-missing-declarations -Wno-discarded-qualifiers -Wno-incompatible-pointer-types -Wno-unused-variable -Wno-deprecated-declarations)
target_link_libraries(registration test5gc)


