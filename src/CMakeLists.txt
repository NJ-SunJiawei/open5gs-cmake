cmake_minimum_required(VERSION 3.00)

include_directories(${LINUX_HEADER_PATH}/libmongoc-1.0/mongoc
                    ${LINUX_HEADER_PATH}/libmongoc-1.0
					${LINUX_HEADER_PATH}/libbson-1.0)
					
include_directories(${FREEDIAMETER_INCDIR})
link_directories(${FREEDIAMETER_LIBDIR})

set(TEMP Version)
set(OPEN5GS_VERSION  ${TEMP}${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.h.in ${CMAKE_CURRENT_BINARY_DIR}/version.h)

add_subdirectory(amf)
add_subdirectory(ausf)
add_subdirectory(hss)
add_subdirectory(mme)
add_subdirectory(nrf)
add_subdirectory(nssf)
add_subdirectory(pcf)
add_subdirectory(pcrf)
add_subdirectory(sgwc)
add_subdirectory(sgwu)
add_subdirectory(smf)
add_subdirectory(udm)
add_subdirectory(udr)
add_subdirectory(upf)



