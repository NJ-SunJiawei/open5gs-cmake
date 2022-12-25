cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    context.c
    event.c
    timer.c
    nnrf-build.c
    nnrf-handler.c
    nf-sm.c
    nudm-handler.c
    nudr-build.c
    nudr-handler.c
    ue-sm.c
    sbi-path.c
    udm-sm.c
    init.c
)

add_library(udm STATIC ${SRC_FILES})
target_include_directories(udm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(udm libapp libcrypt libsbi)

add_executable(open5gs-udmd ${5GCORE_MAIN_SRCS} app.c)
target_compile_options(open5gs-udmd PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/udm.yaml")
target_link_libraries(open5gs-udmd udm)

install(TARGETS open5gs-udmd
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



