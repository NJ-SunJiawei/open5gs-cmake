cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    context.c
    event.c
    timer.c
    nnrf-build.c
    nnrf-handler.c
    nf-sm.c
    nudr-handler.c
    sbi-path.c
    udr-sm.c
    init.c
)

add_library(udr STATIC ${SRC_FILES})
target_include_directories(udr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(udr libapp libdbi libsbi)

add_executable(open5gs-udrd ${5GCORE_MAIN_SRCS} app.c)
target_compile_options(open5gs-udrd PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/udr.yaml")
target_link_libraries(open5gs-udrd udr)

install(TARGETS open5gs-udrd
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



