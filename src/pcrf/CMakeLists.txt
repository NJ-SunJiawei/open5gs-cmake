cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    pcrf-context.h
    pcrf-fd-path.h
    pcrf-init.c
    pcrf-context.c
    pcrf-fd-path.c
    pcrf-gx-path.c
    pcrf-rx-path.c
)

add_library(pcrf STATIC ${SRC_FILES})
target_include_directories(pcrf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(pcrf libapp libdbi libdiameter_rx libdiameter_gx)

add_executable(open5gs-pcrfd ${5GCORE_MAIN_SRCS} app-init.c)
target_compile_options(open5gs-pcrfd PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/pcrf.yaml")
target_link_libraries(open5gs-pcrfd pcrf)

install(TARGETS open5gs-pcrfd
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



