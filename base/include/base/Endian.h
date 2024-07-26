#include <endian.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
namespace zero
{
namespace net
{

namespace sockets
{


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diangostic ignored "-Wold-style-cast"
/**
 * uint16  u 表示无符号，uint16占用2个字节 
 * uint32  表示无符号32位 
**/
/* 将主机字节序转换为64位的网路字节序 */
inline uint64_t hostToNetwork64(uint64_t host64) {
    return htobe64(host64);
}
inline uint16_t hostToNetWork16(const struct sockaddr_in* addr) {
    return ntohs(addr->sin_port);
}

inline uint32_t hostToNetwork32(uint32_t host32) {
    return htobe32(host32);
}

inline uint16_t hostToNetwork16(uint16_t host16) {
    return htobe16(host16);
}

inline uint64_t networkToHost64(uint64_t net64) {
    return be64toh(net64);
}

inline uint32_t networkToHost32(uint32_t net32) {
    return be32toh(net32);
}

inline uint16_t networkToHost16(uint16_t net16) {
    return be16toh(net16);
}

#pragma GCC diagnostic pop
} // namespace sockets

}
}