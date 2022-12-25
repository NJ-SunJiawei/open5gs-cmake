cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
    ogs-core.h
    ogs-compat.h
    ogs-macros.h
    ogs-pool.h
    ogs-list.h
    ogs-abort.h
    ogs-errno.h
    ogs-strings.h
    ogs-time.h
    ogs-conv.h
    ogs-log.h
    ogs-pkbuf.h
    ogs-memory.h
    ogs-rbtree.h
    ogs-timer.h
    ogs-rand.h
    ogs-uuid.h
    ogs-thread.h
    ogs-signal.h
    ogs-process.h
    ogs-sockaddr.h
    ogs-socket.h
    ogs-sockpair.h
    ogs-socknode.h
    ogs-udp.h
    ogs-tcp.h
    ogs-queue.h
    ogs-poll.h
    ogs-notify.h
    ogs-tlv.h
    ogs-tlv-msg.h
    ogs-env.h
    ogs-fsm.h
    ogs-hash.h
    ogs-misc.h
    ogs-getopt.h
    ogs-3gpp-types.h
    abts.h
    ogs-abort.c
    ogs-errno.c
    ogs-strings.c
    ogs-time.c
    ogs-conv.c
    ogs-log.c
    ogs-pkbuf.c
    ogs-memory.c
    ogs-rbtree.c
    ogs-timer.c
    ogs-rand.c
    ogs-uuid.c
    ogs-thread.c
    ogs-signal.c
    ogs-process.c
    ogs-sockaddr.c
    ogs-socket.c
    ogs-sockpair.c
    ogs-socknode.c
    ogs-udp.c
    ogs-tcp.c
    ogs-queue.c
    ogs-select.c
    ogs-poll.c
    ogs-notify.c
    ogs-tlv.c
    ogs-tlv-msg.c
    ogs-env.c
    ogs-fsm.c
    ogs-hash.c
    ogs-misc.c
    ogs-getopt.c
    ogs-3gpp-types.c
    ogs-core.c
    abts.c
)

OPTION(DISABLE "Disable support?" OFF)
IF (DISABLE)
    list(FILTER SRC_FILES EXCLUDE REGEX "ogs-kqueue.c")
ENDIF (DISABLE)

INCLUDE (TestBigEndian)
set(_GNU_SOURCE 1)
set(OGS_BIG_ENDIAN 4321)
set(OGS_LITTLE_ENDIAN 1234)
TEST_BIG_ENDIAN (HOST_BIG_ENDIAN)
IF(HOST_BIG_ENDIAN)
    set(OGS_BYTE_ORDER OGS_BIG_ENDIAN)
ENDIF(HOST_BIG_ENDIAN)

IF(NOT HOST_BIG_ENDIAN)
    set(OGS_BYTE_ORDER OGS_LITTLE_ENDIAN)
ENDIF(NOT HOST_BIG_ENDIAN)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/core-config.h.in ${CMAKE_CURRENT_BINARY_DIR}/core-config.h)


INCLUDE (CheckLibraryExists)
INCLUDE (CheckFunctionExists)
INCLUDE (CheckIncludeFiles)
INCLUDE (CheckSymbolExists)
INCLUDE (CheckCSourceCompiles)

CHECK_INCLUDE_FILES(arpa/inet.h HAVE_ARPA_INET_H)
CHECK_INCLUDE_FILES(ctype.h HAVE_CTYPE_H)
CHECK_INCLUDE_FILES(errno.h HAVE_ERRNO_H)
CHECK_INCLUDE_FILES(execinfo.h HAVE_EXECINFO_H)
CHECK_INCLUDE_FILES(fcntl.h HAVE_FCNTL_H)
CHECK_INCLUDE_FILES(ifaddrs.h HAVE_IFADDRS_H)
CHECK_INCLUDE_FILES(netdb.h HAVE_NETDB_H)
CHECK_INCLUDE_FILES(pthread.h HAVE_PTHREAD_H)
CHECK_INCLUDE_FILES(signal.h HAVE_SIGNAL_H)
CHECK_INCLUDE_FILES(stdarg.h HAVE_STDARG_H)
CHECK_INCLUDE_FILES(stddef.h HAVE_STDDEF_H)
CHECK_INCLUDE_FILES(stdio.h HAVE_STDIO_H)
CHECK_INCLUDE_FILES(stdint.h HAVE_STDINT_H)
CHECK_INCLUDE_FILES(stdbool.h HAVE_STDBOOL_H)
CHECK_INCLUDE_FILES(stdlib.h HAVE_STDLIB_H)
CHECK_INCLUDE_FILES(string.h HAVE_STRING_H)
CHECK_INCLUDE_FILES(strings.h HAVE_STRINGS_H)
CHECK_INCLUDE_FILES(time.h HAVE_TIME_H)
CHECK_INCLUDE_FILES(unistd.h HAVE_UNISTD_H)
CHECK_INCLUDE_FILES(net/if.h HAVE_NET_IF_H)
CHECK_INCLUDE_FILES(netinet/in.h HAVE_NETINET_IN_H)
CHECK_INCLUDE_FILES(netinet/in_systm.h HAVE_NETINET_IN_SYSTM_H)
CHECK_INCLUDE_FILES(netinet/udp.h HAVE_NETINET_TCP_H)
CHECK_INCLUDE_FILES(netinet/tcp.h HAVE_NETINET_UDP_H)
CHECK_INCLUDE_FILES(sys/ioctl.h HAVE_SYS_IOCTL_H)
CHECK_INCLUDE_FILES(sys/param.h HAVE_SYS_PARAM_H)
CHECK_INCLUDE_FILES(sys/random.h HAVE_SYS_RANDOM_H)
CHECK_INCLUDE_FILES(sys/socket.h HAVE_SYS_SOCKET_H)
CHECK_INCLUDE_FILES(sys/stat.h HAVE_SYS_STAT_H)
CHECK_INCLUDE_FILES(limits.h HAVE_LIMITS_H)
CHECK_INCLUDE_FILES(sys/syslimits.h HAVE_SYS_SYSLIMITS_H)
CHECK_INCLUDE_FILES(sys/types.h HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILES(sys/wait.h HAVE_SYS_UIO_H)
CHECK_INCLUDE_FILES(sys/uio.h HAVE_SYS_WAIT_H)
CHECK_INCLUDE_FILES(sys/time.h HAVE_SYS_TIME_H)

CHECK_FUNCTION_EXISTS(arc4random HAVE_ARC4RANDOM)
CHECK_FUNCTION_EXISTS(arc4random_buf HAVE_ARC4RANDOM_BUF)
CHECK_FUNCTION_EXISTS(getrandom HAVE_GETRANDOM)
CHECK_FUNCTION_EXISTS(localtime_r HAVE_LOCALTIME_R)
CHECK_FUNCTION_EXISTS(getifaddrs HAVE_GETIFADDRS)
CHECK_FUNCTION_EXISTS(getenv HAVE_GETENV)
CHECK_FUNCTION_EXISTS(putenv HAVE_PUTENV)
CHECK_FUNCTION_EXISTS(setenv HAVE_SETENV)
CHECK_FUNCTION_EXISTS(unsetenv HAVE_UNSETENV)
CHECK_FUNCTION_EXISTS(strerror_r HAVE_STRERROR_R)
CHECK_FUNCTION_EXISTS(sigaction HAVE_SIGACTION)
CHECK_FUNCTION_EXISTS(sigwait HAVE_SIGWAIT)
CHECK_FUNCTION_EXISTS(sigsuspend HAVE_SIGSUSPEND)
CHECK_FUNCTION_EXISTS(eventfd HAVE_EVENTFD)
CHECK_FUNCTION_EXISTS(kqueue HAVE_KQUEUE)
CHECK_FUNCTION_EXISTS(epoll_ctl HAVE_EPOLL_CTL)

set(HAVE_PTHREAD_BAR 1)
set(HAVE_DECL_SYS_SIGLIST 1)
set(STRERROR_R_CHAR_P 1)

IF(HAVE_EXECINFO_H)
    CHECK_SYMBOL_EXISTS(backtrace execinfo.h HAVE_BACKTRACE)
ENDIF(HAVE_EXECINFO_H)

CHECK_LIBRARY_EXISTS (rt clock_gettime "" HAVE_LIBRT)
IF (HAVE_LIBRT)
    SET(CLOCK_GETTIME_LIBS "-lrt")
    SET(HAVE_CLOCK_GETTIME 1)
ELSE (HAVE_LIBRT)
    CHECK_LIBRARY_EXISTS (posix4 clock_gettime "" HAVE_LIBPOSIX4)
    IF (HAVE_LIBPOSIX4)
       SET(CLOCK_GETTIME_LIBS "-lposix4")
       SET(HAVE_CLOCK_GETTIME 1)
    ENDIF (HAVE_LIBPOSIX4)
ENDIF (HAVE_LIBRT)

IF(HAVE_EPOLL_CTL)
    set(HAVE_EPOLL 1)
	set(SRC_FILES ${SRC_FILES} ogs-epoll.c)
ENDIF(HAVE_EPOLL_CTL)

IF(HAVE_KQUEUE)
	set(SRC_FILES ${SRC_FILES} ogs-kqueue.c)
ENDIF(HAVE_KQUEUE)

set(OGS_DEV_RANDOM /dev/urandom)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/core-config-private.h.in ${CMAKE_CURRENT_BINARY_DIR}/core-config-private.h)

include_directories(${5GCORE_LIB_PATH}
                    ${5GCORE_LIB_PATH}/core
					${5GCORE_BUILD_PATH}/lib
					${5GCORE_BUILD_PATH}/lib/core)
					
add_library(libcore SHARED ${SRC_FILES})
target_include_directories(libcore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(libcore PUBLIC -DOGS_CORE_COMPILATION)
target_link_libraries(libcore rt pthread)

set_target_properties(libcore PROPERTIES
     OUTPUT_NAME "5g_core"
	 SOVERSION ${FD_PROJECT_VERSION_API}
	 VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
)

install(TARGETS libcore
        LIBRARY DESTINATION ${5GCORE_INSTALL_LIB_PATH}
		COMPONENT 5glib)



