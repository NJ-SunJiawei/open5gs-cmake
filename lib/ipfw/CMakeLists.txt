cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    ipfw2.h
    glue.h
    missing.h
    ipfw2.c
    dummynet.c
    ipv6.c
    tables.c
    expand_number.c
    humanize_number.c
    glue.c
    ogs-ipfw.h
    ogs-ipfw.c
)

include_directories(${5GCORE_LIB_PATH}/ipfw/objs/include_e)

add_library(libipfw SHARED ${SRC_FILES})
target_include_directories(libipfw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libipfw PUBLIC -include glue.h)
target_compile_options(libipfw PUBLIC -Wno-shift-negative-value -Wno-unused-but-set-variable -Wno-unknown-warning-option -Wno-missing-prototypes
                                      -Wno-missing-declarations -Wno-discarded-qualifiers -Wno-redundant-decls -Wno-shift-overflow -Wno-float-equal
									  -Wno-implicit-fallthrough -Wno-incompatible-pointer-types-discards-qualifiers -Wno-format-nonliteral -Wno-cpp)
target_compile_options(libipfw PUBLIC -D_DEFAULT_SOURCE -D_BSD_SOURCE -DUSERSPACE -D__BSD_VISIBLE -DNEED_STRTONUM -DNEED_ROUNDUP2 -DNEED_SYSCTLBYNAME)

OPTION(IS_LINUX "LINUX support?" ON)
IF (IS_LINUX)
    target_compile_options(libipfw PUBLIC -DNEED_SIN_LEN)   
ENDIF (IS_LINUX)

target_link_libraries(libipfw libcore)

set_target_properties(libipfw PROPERTIES
     OUTPUT_NAME "5g_ipfw"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libipfw
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



