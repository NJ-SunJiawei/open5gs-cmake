cmake_minimum_required(VERSION 3.00)

#nxxf.yaml
set(localstatedir ${5GCORE_INSTALL_VAR_PATH})
set(libdir ${5GCORE_INSTALL_LIB_PATH})
set(bindir ${5GCORE_INSTALL_BIN_PATH})
set(sysconfdir ${5GCORE_INSTALL_CNF_PATH})

#sample.yaml
set(freediameter_extensions_builddir ${5GCORE_BUILD_PATH}/subprojects/freeDiameter/extensions)

add_subdirectory(open5gs)
add_subdirectory(freeDiameter)
add_subdirectory(systemd)
add_subdirectory(logrotate)
add_subdirectory(newsyslog)


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sample.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/sample.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/310014.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/310014.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/csfb.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/csfb.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/volte.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/volte.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/vonr.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/vonr.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/slice.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/slice.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/srslte.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/srslte.yaml)

