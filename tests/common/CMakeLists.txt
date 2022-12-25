cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    sctp.c
    gtpu.c
    context.c
    application.c
    ngap-build.c
    ngap-handler.c
    ngap-path.c
    gmm-build.c
    gmm-handler.c
    gsm-build.c
    gsm-handler.c
    s1ap-build.c
    s1ap-handler.c
    s1ap-path.c
    emm-build.c
    emm-handler.c
    esm-build.c
    esm-handler.c
    nas-path.c
    nas-encoder.c
    nas-security.c
    sgsap-build.c
)

set(MESON_BUILD_ROOT ${5GCORE_BUILD_PATH})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test-config-private.h.in ${CMAKE_CURRENT_BINARY_DIR}/test-config-private.h)

add_library(testcommon STATIC ${SRC_FILES})
target_include_directories(testcommon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(core PUBLIC -Wno-missing-prototypes -Wno-missing-declarations -Wno-discarded-qualifiers -Wno-incompatible-pointer-types -Wno-unused-variable -Wno-deprecated-declarations)
target_link_libraries(testcommon libcore libipfw libapp libdbi libsctp libs1ap libngap libnas_eps libnas_5gs libdiameter_rx libgtp libdiameter_cx)



