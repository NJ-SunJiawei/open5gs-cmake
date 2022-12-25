cmake_minimum_required(VERSION 3.00)


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/mme.conf.in ${CMAKE_CURRENT_BINARY_DIR}/mme.conf)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hss.conf.in ${CMAKE_CURRENT_BINARY_DIR}/hss.conf)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/smf.conf.in ${CMAKE_CURRENT_BINARY_DIR}/smf.conf)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/pcrf.conf.in ${CMAKE_CURRENT_BINARY_DIR}/pcrf.conf)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cacert.pem ${CMAKE_CURRENT_BINARY_DIR}/cacert.pem)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/mme.cert.pem ${CMAKE_CURRENT_BINARY_DIR}/mme.cert.pem)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/mme.key.pem ${CMAKE_CURRENT_BINARY_DIR}/mme.key.pem)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hss.cert.pem ${CMAKE_CURRENT_BINARY_DIR}/hss.cert.pem)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hss.key.pem ${CMAKE_CURRENT_BINARY_DIR}/hss.key.pem)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/smf.cert.pem ${CMAKE_CURRENT_BINARY_DIR}/smf.cert.pem)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/smf.key.pem ${CMAKE_CURRENT_BINARY_DIR}/smf.key.pem)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/pcrf.cert.pem ${CMAKE_CURRENT_BINARY_DIR}/pcrf.cert.pem)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/pcrf.key.pem ${CMAKE_CURRENT_BINARY_DIR}/pcrf.key.pem)

set(CONF ${CMAKE_CURRENT_BINARY_DIR}/mme.conf
         ${CMAKE_CURRENT_BINARY_DIR}/hss.conf
		 ${CMAKE_CURRENT_BINARY_DIR}/smf.conf
		 ${CMAKE_CURRENT_BINARY_DIR}/pcrf.conf
		 ${CMAKE_CURRENT_BINARY_DIR}/cacert.pem
		 ${CMAKE_CURRENT_BINARY_DIR}/mme.cert.pem
		 ${CMAKE_CURRENT_BINARY_DIR}/mme.key.pem
		 ${CMAKE_CURRENT_BINARY_DIR}/hss.cert.pem
		 ${CMAKE_CURRENT_BINARY_DIR}/hss.key.pem
		 ${CMAKE_CURRENT_BINARY_DIR}/smf.cert.pem
		 ${CMAKE_CURRENT_BINARY_DIR}/smf.key.pem
		 ${CMAKE_CURRENT_BINARY_DIR}/pcrf.cert.pem
		 ${CMAKE_CURRENT_BINARY_DIR}/pcrf.key.pem)

install(FILES ${CONF}
        DESTINATION ${5GCORE_INSTALL_CNF_PATH}/freeDiameter
		COMPONENT 5gcore-cnf)

