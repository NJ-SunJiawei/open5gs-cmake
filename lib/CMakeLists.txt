cmake_minimum_required(VERSION 3.00)

include_directories(${FREEDIAMETER_INCDIR})
link_directories(${FREEDIAMETER_LIBDIR})

add_subdirectory(app)
add_subdirectory(asn1c/common)
add_subdirectory(asn1c/ngap)
add_subdirectory(asn1c/s1ap)
add_subdirectory(asn1c/util)
add_subdirectory(core)
add_subdirectory(crypt)
add_subdirectory(dbi)
add_subdirectory(diameter/common)
add_subdirectory(diameter/gx)
add_subdirectory(diameter/rx)
add_subdirectory(diameter/s6a)
add_subdirectory(diameter/cx)
add_subdirectory(gtp)
add_subdirectory(ipfw)
add_subdirectory(nas/5gs)
add_subdirectory(nas/common)
add_subdirectory(nas/eps)
add_subdirectory(ngap)
add_subdirectory(pfcp)
add_subdirectory(s1ap)
add_subdirectory(sbi)
add_subdirectory(sctp)
add_subdirectory(tun)



