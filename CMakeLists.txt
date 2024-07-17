cmake_minimum_required(VERSION 3.0)
project(main)

# cmake => makefile   make
# mymuduo最终编译成so动态库，设置动态库的路径，放在根目录的lib文件夹下面
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# 设置调试信息 以及 启动C++11语言标准
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")
set(SRC_LIST 
    Acceptor.cc
    Acceptor.h 
    Buffer.cc 
    Buffer.h
    Callbacks.h
    Channel.cc
    Channel.h
    CurrentThread.cc
    CurrentThread.h
    DefaultPoller.cc
    EPollPoller.cc
    EPollPoller.h
    EventLoop.cc
    EventLoop.h
    EventLoopThread.cc
    EventLoopThread.h
    EventLoopThreadPool.cc
    EventLoopThreadPool.h
    InetAddress.cc
    InetAddress.h
    Logger.cc
    Logger.h
    noncopyable.h
    Poller.cc
    Poller.h
    Socket.cc
    Socket.h
    TcpConnection.cc
    TcpConnection.h
    TcpServer.cc
    TcpServer.h
    Thread.cc
    Thread.h
    Timestamp.cc
    Timestamp.h
    )

add_executable(mian main.cc ${SRC_LIST})
# 定义参与编译的源代码文件 
#aux_source_directory(. SRC_LIST)
# 编译生成动态库mymuduo
#add_library(main SHARED ${SRC_LIST})