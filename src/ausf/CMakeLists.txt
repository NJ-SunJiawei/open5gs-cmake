cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    context.c
    event.c
    timer.c
    nnrf-build.c
    nnrf-handler.c
    nf-sm.c
    nausf-handler.c
    nudm-build.c
    nudm-handler.c
    ue-sm.c
    sbi-path.c
    ausf-sm.c
    init.c
)

add_library(ausf STATIC ${SRC_FILES})
target_include_directories(ausf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ausf libapp libcrypt libsbi)

add_executable(open5gs-ausfd ${5GCORE_MAIN_SRCS} app.c)
target_compile_options(open5gs-ausfd PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/ausf.yaml")
target_link_libraries(open5gs-ausfd ausf)

install(TARGETS open5gs-ausfd
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



