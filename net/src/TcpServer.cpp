// #include <net/TcpServer.h>
// #include <net/Acceptor.h>
// #include <net/EventLoop.h>
// #include <net/EventLoopThreadPool.h>
#include <net/SocketsOps.h>

#include <stdio.h>
using namespace zero;


// TcpServer::TcpServer(EventLoop* loop, const InetAddress& listenAddr,
//                     const std::string& nameArg, Option option):
//     :loop_(loop),
//     ipPort(listenAddr.toIpPort()),
//     name_(nameArg),
//     acceptor(new Acceptor(loop,listenAddr,option == kReusePort)),
//     threadPool_(new EventLoopTHreadPool(loop,name_)),
//     connectionCallback_(defaultConnectionCallback),
//     messageCallback_(defaultMessageCallback),
//     newConnId_(1) {
//         acceptor_->setNewConnectionCallback( 
//             std::bind(&TcpServer::newConnection,this,_1,_2)
//         );
//     }