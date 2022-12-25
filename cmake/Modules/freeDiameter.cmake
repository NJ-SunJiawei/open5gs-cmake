include(ExternalProject)

set(FLAGS_SRC ${5GCORE_SUBPROJECTS_PATH}/freeDiameter)
set(FLAGS_BINARY ${CMAKE_CURRENT_BINARY_DIR}/subprojects/freeDiameter)
set(FLAGS_CONFIGURE cd ${FLAGS_BINARY} && cmake ../../../subprojects/freeDiameter)
set(FLAGS_MAKE cd ${FLAGS_BINARY} && make)
set(FLAGS_INSTALL cd ${FLAGS_BINARY} && make install)

ExternalProject_Add(freeDiameter
       SOURCE_DIR        ${FLAGS_SRC}
	   BINARY_DIR        ${FLAGS_BINARY}
	   CONFIGURE_COMMAND ${FLAGS_CONFIGURE}
	   BUILD_COMMAND     ${FLAGS_MAKE} 
	   INSTALL_COMMAND   ${FLAGS_INSTALL}
)

set(FREEDIAMETER_LIBDIR ${FLAGS_BINARY}/libfdcore
                        ${FLAGS_BINARY}/libfdproto)
set(FREEDIAMETER_INCDIR ${FLAGS_BINARY}/include)

