cmake_minimum_required(VERSION 3.00)


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/open5gs.in ${CMAKE_CURRENT_BINARY_DIR}/open5gs)

file(MAKE_DIRECTORY ${5GCORE_INSTALL_VAR_PATH}/log/open5gs)