cmake_minimum_required(VERSION 3.00)

set(EPC_SRC_FILES
    epc-init.c
)

add_library(testepc STATIC ${EPC_SRC_FILES})
target_include_directories(testepc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(testepc PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/sample.yaml")
target_link_libraries(testepc testcommon bson-1.0)

add_executable(epc ${5GCORE_MAIN_SRCS})
target_link_libraries(epc testepc)
##########################################################
set(5GC_SRC_FILES
    5gc-init.c
)

add_library(test5gc STATIC ${5GC_SRC_FILES})
target_include_directories(test5gc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(test5gc PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/sample.yaml")
target_link_libraries(test5gc testcommon bson-1.0)

add_executable(5gc ${5GCORE_MAIN_SRCS})
target_link_libraries(5gc test5gc)
##########################################################
set(APP_SRC_FILES
    app-init.c
)

add_library(testapp STATIC ${APP_SRC_FILES})
target_include_directories(testapp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(testapp PUBLIC -DDEFAULT_CONFIG_FILENAME="${5GCORE_CONFIGS_PATH}/sample.yaml")
target_link_libraries(testapp testcommon bson-1.0)

add_executable(app ${5GCORE_MAIN_SRCS})
target_link_libraries(app testapp)


