cmake_minimum_required(VERSION 3.00)


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/mme.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/mme.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sgwc.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/sgwc.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sgwu.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/sgwu.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/smf.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/smf.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/amf.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/amf.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hss.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/hss.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/pcf.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/pcf.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/pcrf.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/pcrf.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/nrf.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/nrf.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/ausf.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/ausf.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/udm.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/udm.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/udr.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/udr.yaml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/nssf.yaml.in ${CMAKE_CURRENT_BINARY_DIR}/nssf.yaml)




set(YAML ${CMAKE_CURRENT_BINARY_DIR}/mme.yaml
         ${CMAKE_CURRENT_BINARY_DIR}/sgwc.yaml
		 ${CMAKE_CURRENT_BINARY_DIR}/sgwu.yaml
		 ${CMAKE_CURRENT_BINARY_DIR}/smf.yaml
		 ${CMAKE_CURRENT_BINARY_DIR}/amf.yaml
		 ${CMAKE_CURRENT_BINARY_DIR}/hss.yaml
		 ${CMAKE_CURRENT_BINARY_DIR}/pcf.yaml
		 ${CMAKE_CURRENT_BINARY_DIR}/pcrf.yaml
		 ${CMAKE_CURRENT_BINARY_DIR}/nrf.yaml
		 ${CMAKE_CURRENT_BINARY_DIR}/ausf.yaml
		 ${CMAKE_CURRENT_BINARY_DIR}/udm.yaml
		 ${CMAKE_CURRENT_BINARY_DIR}/udr.yaml
		 ${CMAKE_CURRENT_BINARY_DIR}/nssf.yaml)

install(FILES ${YAML}
        DESTINATION ${5GCORE_INSTALL_CNF_PATH}
		COMPONENT 5gcore-cnf)

