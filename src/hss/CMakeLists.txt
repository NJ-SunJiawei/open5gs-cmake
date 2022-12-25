cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    hss-context.h
    hss-fd-path.h
    hss-init.c
    hss-context.c
    hss-s6a-path.c
    hss-cx-path.c
    hss-fd-path.c
)

add_library(hss STATIC ${SRC_FILES})
target_include_directories(hss PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(hss libapp libcrypt libdbi libdiameter_s6a libdiameter_cx)

add_executable(open5gs-hssd ${5GCORE_MAIN_SRCS} app-init.c)
target_compile_options(open5gs-hssd PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/open5gs/hss.yaml")
target_link_libraries(open5gs-hssd hss)

install(TARGETS open5gs-hssd
        RUNTIME DESTINATION ${5GCORE_INSTALL_BIN_PATH}
		COMPONENT 5gbin)



