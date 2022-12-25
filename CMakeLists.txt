cmake_minimum_required(VERSION 3.00)
project(5gCORE)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Version of the source code
set(FD_PROJECT_VERSION_MAJOR 1)
set(FD_PROJECT_VERSION_MINOR 3)
set(FD_PROJECT_VERSION_REV 2)

# Version of the API with the library
set(FD_PROJECT_VERSION_API 6)


set(CMAKE_BUILD_TYPE "DEBUG")
set(CMAKE_CFLAG "$ENV{CFLAGS} -Wextra -Wlogical-op -Wfloat-equal -Wwrite-strings -Wdate-time -Wunused -Wno-sign-compare -Wno-unused-parameter -fstack-protector")
set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -Wall -ffunction-sections -fdata-sections")

#system path
set(LINUX_HEADER_PATH /usr/include)
set(LINUX_LIB_PATH /usr/lib)
set(LINUX_HEADER_PATH_LOCAL /usr/local/include)
set(LINUX_LIB_PATH_LOCAL /usr/local/lib)

#install path
set(INSTALL_ROOT /usr/local)

set(5GCORE_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(5GCORE_BUILD_PATH ${5GCORE_ROOT_PATH}/build)
set(5GCORE_CONFIGS_PATH ${5GCORE_BUILD_PATH}/configs)


#install file path
set(5GCORE_INSTALL_PATH ${INSTALL_ROOT}/install/5G)
set(5GCORE_INSTALL_VAR_PATH ${5GCORE_INSTALL_PATH}/var)
set(5GCORE_INSTALL_LIB_PATH ${5GCORE_INSTALL_PATH}/lib)
set(5GCORE_INSTALL_BIN_PATH ${5GCORE_INSTALL_PATH}/bin)
set(5GCORE_INSTALL_CNF_PATH ${5GCORE_INSTALL_PATH}/cnf)

#install runpath
#set(CMAKE_SKIP_BUILD_RPATH FALSE)                 # 编译时加上RPATH  
#set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)         # 编译时RPATH不使用安装的RPATH  
set(CMAKE_INSTALL_RPATH "${5GCORE_INSTALl_LIB_PATH}") # 安装RPATH为空  
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)           # 安装的执行文件不加上RPATH 

#src path

set(5GCORE_SRC_PATH ${5GCORE_ROOT_PATH}/src)
set(5GCORE_LIB_PATH ${5GCORE_ROOT_PATH}/lib)
set(5GCORE_TESTS_PATH ${5GCORE_ROOT_PATH}/tests)
set(5GCORE_SUBPROJECTS_PATH ${5GCORE_ROOT_PATH}/subprojects)

#cmake build include
include_directories(${5GCORE_BUILD_PATH}/src
                    ${5GCORE_BUILD_PATH}/src/smf
                    ${5GCORE_BUILD_PATH}/src/upf
                    ${5GCORE_BUILD_PATH}/lib
                    ${5GCORE_BUILD_PATH}/lib/core
                    ${5GCORE_BUILD_PATH}/lib/pfcp
                    ${5GCORE_BUILD_PATH}/lib/sctp)

#lib common include
include_directories(${5GCORE_LIB_PATH}
                    ${5GCORE_LIB_PATH}/app
                    ${5GCORE_LIB_PATH}/asn1c/common
                    ${5GCORE_LIB_PATH}/asn1c/ngap
                    ${5GCORE_LIB_PATH}/asn1c/s1ap
                    ${5GCORE_LIB_PATH}/asn1c/util
                    ${5GCORE_LIB_PATH}/core
					${5GCORE_LIB_PATH}/crypt
					${5GCORE_LIB_PATH}/dbi
					${5GCORE_LIB_PATH}/diameter/common
					${5GCORE_LIB_PATH}/diameter/gx
					${5GCORE_LIB_PATH}/diameter/rx
					${5GCORE_LIB_PATH}/diameter/sa6
					${5GCORE_LIB_PATH}/diameter/cx
					${5GCORE_LIB_PATH}/gtp
					${5GCORE_LIB_PATH}/ipfw
					${5GCORE_LIB_PATH}/nas/common
					${5GCORE_LIB_PATH}/nas/5gs
					${5GCORE_LIB_PATH}/nas/epc
					${5GCORE_LIB_PATH}/ngap
					${5GCORE_LIB_PATH}/pfcp
					${5GCORE_LIB_PATH}/s1ap
					${5GCORE_LIB_PATH}/sbi
					${5GCORE_LIB_PATH}/sbi/openapi
					${5GCORE_LIB_PATH}/sbi/openapi/model
					${5GCORE_LIB_PATH}/sctp
					${5GCORE_LIB_PATH}/tun)

#src common include					
include_directories(${5GCORE_SRC_PATH}/amf
                    ${5GCORE_SRC_PATH}/ausf
					${5GCORE_SRC_PATH}/hss
					${5GCORE_SRC_PATH}/mme
					${5GCORE_SRC_PATH}/nrf
					${5GCORE_SRC_PATH}/nssf
					${5GCORE_SRC_PATH}/pcf
					${5GCORE_SRC_PATH}/pcrf
					${5GCORE_SRC_PATH}/sgwc
					${5GCORE_SRC_PATH}/sgwu
					${5GCORE_SRC_PATH}/smf
					${5GCORE_SRC_PATH}/udm
					${5GCORE_SRC_PATH}/udr
					${5GCORE_SRC_PATH}/upf)
					
#find_package(Boost REQUIRED)
#include_directories(${LIBBOOST_INCLUDE_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")
include(${CMAKE_MODULE_PATH}/freeDiameter.cmake)


set(5GCORE_MAIN_SRCS ${5GCORE_SRC_PATH}/main)

add_subdirectory(configs)
add_subdirectory(misc)
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)




