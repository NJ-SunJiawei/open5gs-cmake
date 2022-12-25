cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    context.c
    event.c
    timer.c
    nausf-build.c
    nausf-handler.c
    nudm-build.c
    nudm-handler.c
    nsmf-build.c
    nsmf-handler.c
    npcf-build.c
    npcf-handler.c
    nnssf-build.c
    nnssf-handler.c
    nnrf-build.c
    nnrf-handler.c
    namf-handler.c
    sbi-path.c
    nf-sm.c
    ngap-sctp.c
    ngap-build.c
    ngap-handler.c
    ngap-path.c
    ngap-sm.c
    nas-security.c
    gmm-build.c
    gmm-handler.c
    nas-path.c
    gmm-sm.c
    amf-sm.c
    init.c
)

add_library(amf STATIC ${SRC_FILES})
target_include_directories(amf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(amf libapp libsctp libngap libnas_5gs libsbi)

add_executable(open5gs-amfd ${5GCORE_MAIN_SRCS} app.c)
target_compile_options(open5gs-amfd PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/amf.yaml")
target_link_libraries(open5gs-amfd amf)

install(TARGETS open5gs-amfd
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



