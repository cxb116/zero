cmake_minimum_required(VERSION 3.0)
project(main)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")
# 设置cmake的全局变量
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR} /include)
# # 添加头文件
# include_directories(${PROJECT_SOURCE_DIR}  /include)

#aux_source_directory(. SRC_LIST) # 定义变量，存储当前目录下的所有源文件
add_executable(main main.cpp)
#target_link_libraries(main pthread)
# 链接pthread库到可执行文件
# 使用CMake提供的线程包而不是直接链接pthread

