cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    context.c
    event.c
    timer.c
    nnrf-handler.c
    nnrf-build.c
    sbi-path.c
    nf-sm.c
    nrf-sm.c
    init.c
)

add_library(nrf STATIC ${SRC_FILES})
target_include_directories(nrf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(nrf libapp libsbi libdbi)

add_executable(open5gs-nrfd ${5GCORE_MAIN_SRCS} app.c)
target_compile_options(open5gs-nrfd PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/nrf.yaml")
target_link_libraries(open5gs-nrfd nrf)

install(TARGETS open5gs-nrfd
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



