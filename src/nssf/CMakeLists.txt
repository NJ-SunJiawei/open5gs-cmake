cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    context.c
    event.c
    timer.c
    nnrf-build.c
    nnrf-handler.c
    nf-sm.c
    nnssf-handler.c
    sbi-path.c
    nssf-sm.c
    init.c
)

add_library(nssf STATIC ${SRC_FILES})
target_include_directories(nssf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(nssf libapp libsbi)

add_executable(open5gs-nssfd ${5GCORE_MAIN_SRCS} app.c)
target_compile_options(open5gs-nssfd PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/nssf.yaml")
target_link_libraries(open5gs-nssfd nssf)

install(TARGETS open5gs-nssfd
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



