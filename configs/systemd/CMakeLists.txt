cmake_minimum_required(VERSION 3.00)


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/99-open5gs.netdev ${CMAKE_CURRENT_BINARY_DIR}/99-open5gs.netdev)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/99-open5gs.network ${CMAKE_CURRENT_BINARY_DIR}/99-open5gs.network)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-mmed.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-mmed.service)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-smfd.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-smfd.service)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-amfd.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-amfd.service)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-sgwcd.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-sgwcd.service)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-sgwud.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-sgwud.service)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-hssd.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-hssd.service)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-pcrfd.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-pcrfd.service)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-nrfd.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-nrfd.service)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-ausfd.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-ausfd.service)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-udmd.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-udmd.service)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-pcfd.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-pcfd.service)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-nssfd.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-nssfd.service)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs-udrd.service.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs-udrd.service)


