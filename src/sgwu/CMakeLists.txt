cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    timer.h
    event.h
    context.h 
    gtp-path.h
    sxa-build.h
    sxa-handler.h
    pfcp-path.h
    sgwu-sm.h
    init.c
    timer.c
    event.c
    context.c 
    gtp-path.c
    sxa-build.c
    sxa-handler.c
    pfcp-path.c
    pfcp-sm.c
    sgwu-sm.c
)

add_library(sgwu STATIC ${SRC_FILES})
target_include_directories(sgwu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(sgwu libapp libgtp libpfcp)

add_executable(open5gs-sgwud ${5GCORE_MAIN_SRCS} app.c)
target_compile_options(open5gs-sgwud PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/sgwu.yaml")
target_link_libraries(open5gs-sgwud sgwu)

install(TARGETS open5gs-sgwud
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



