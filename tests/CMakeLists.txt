cmake_minimum_required(VERSION 3.00)

include_directories(${LINUX_HEADER_PATH}/libmongoc-1.0/mongoc
                    ${LINUX_HEADER_PATH}/libmongoc-1.0
					${LINUX_HEADER_PATH}/libbson-1.0)
					
include_directories(${5GCORE_BUILD_PATH}/tests/common)
					
include_directories(${5GCORE_TESTS_PATH}
                    ${5GCORE_TESTS_PATH}/310014
					${5GCORE_TESTS_PATH}/app
					${5GCORE_TESTS_PATH}/attach
					${5GCORE_TESTS_PATH}/common
					${5GCORE_TESTS_PATH}/core
					${5GCORE_TESTS_PATH}/crypt
					${5GCORE_TESTS_PATH}/csfb
					${5GCORE_TESTS_PATH}/handover
					${5GCORE_TESTS_PATH}/registration
					${5GCORE_TESTS_PATH}/sctp
					${5GCORE_TESTS_PATH}/slice
					${5GCORE_TESTS_PATH}/unit
					${5GCORE_TESTS_PATH}/volte
					${5GCORE_TESTS_PATH}/vonr)					

include_directories(${FREEDIAMETER_INCDIR})
link_directories(${FREEDIAMETER_LIBDIR})

add_subdirectory(core)
add_subdirectory(crypt)
add_subdirectory(sctp)
add_subdirectory(unit)
add_subdirectory(common)
add_subdirectory(app)
add_subdirectory(registration)
#add_subdirectory(vonr)
#add_subdirectory(slice)
#add_subdirectory(attach)
#add_subdirectory(volte)
#add_subdirectory(csfb)
#add_subdirectory(310014)
#add_subdirectory(handover)



