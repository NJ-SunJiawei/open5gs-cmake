cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    context.c
    event.c
    timer.c
    nnrf-build.c
    nnrf-handler.c
    nf-sm.c
    npcf-handler.c
    nudr-build.c
    nudr-handler.c
    am-sm.c
    sm-sm.c
    sbi-path.c
    pcf-sm.c
    init.c
)

add_library(pcf STATIC ${SRC_FILES})
target_include_directories(pcf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(pcf libapp libsbi libcrypt libdbi)

add_executable(open5gs-pcfd ${5GCORE_MAIN_SRCS} app.c)
target_compile_options(open5gs-pcfd PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/pcf.yaml")
target_link_libraries(open5gs-pcfd pcf)

install(TARGETS open5gs-pcfd
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



