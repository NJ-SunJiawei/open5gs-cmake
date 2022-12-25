cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    mme-event.h
    mme-timer.h
    mme-context.h
    s1ap-build.h
    s1ap-handler.h
    s1ap-path.h 
    sgsap-build.h
    sgsap-handler.h
    sgsap-conv.h
    sgsap-path.h 
    mme-fd-path.h
    mme-s6a-handler.h 
    nas-security.h
    nas-path.h 
    emm-handler.h
    emm-build.h 
    esm-handler.h
    esm-build.h 
    mme-gtp-path.h
    mme-s11-build.h
    mme-s11-handler.h 
    sbc-message.h
    sbc-handler.h
    mme-sm.h
    mme-path.h 
    mme-init.c
    mme-event.c
    mme-timer.c
    mme-context.c 
    s1ap-sm.c
    s1ap-build.c
    s1ap-handler.c
    s1ap-sctp.c
    s1ap-path.c 
    sgsap-sm.c
    sgsap-build.c
    sgsap-handler.c
    sgsap-conv.c
    sgsap-sctp.c
    sgsap-path.c
    mme-fd-path.c
    mme-s6a-handler.c 
    nas-security.c
    nas-path.c
    emm-sm.c
    emm-handler.c
    emm-build.c
    esm-sm.c
    esm-handler.c
    esm-build.c
    mme-gtp-path.c
    mme-s11-build.c
    mme-s11-handler.c
    mme-sm.c
    mme-path.c 
    sbc-handler.c 
)

add_library(mme STATIC ${SRC_FILES})
target_include_directories(mme PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mme libapp libsctp libs1ap libnas_eps libdiameter_s6a libgtp)

add_executable(open5gs-mmed ${5GCORE_MAIN_SRCS} app-init.c)
target_compile_options(open5gs-mmed PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/mme.yaml")
target_link_libraries(open5gs-mmed mme)

install(TARGETS open5gs-mmed
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



