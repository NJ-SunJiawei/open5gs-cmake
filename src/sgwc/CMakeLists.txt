cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    event.h
    timer.h
    context.h 
    gtp-path.h
    s11-build.h
    s11-handler.h
    s5c-handler.h 
    sxa-build.h
    sxa-handler.h
    pfcp-path.h
    sgwc-sm.h
    init.c
    event.c
    timer.c
    context.c 
    gtp-path.c
    s11-build.c
    s11-handler.c
    s5c-handler.c 
    sxa-build.c
    sxa-handler.c
    pfcp-path.c
    pfcp-sm.c
    sgwc-sm.c
)

add_library(sgwc STATIC ${SRC_FILES})
target_include_directories(sgwc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(sgwc libapp libgtp libpfcp)

add_executable(open5gs-sgwcd ${5GCORE_MAIN_SRCS} app.c)
target_compile_options(open5gs-sgwcd PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/sgwc.yaml")
target_link_libraries(open5gs-sgwcd sgwc)

install(TARGETS open5gs-sgwcd
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



