cmake_minimum_required(VERSION 3.0)
project(main CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake;${CMAKE_MODULE_PATH}")
# 设置cmake的全局变量
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR} /include)
# # 添加头文件
# include_directories(${PROJECT_SOURCE_DIR}  /include)

#aux_source_directory(. SRC_LIST) # 定义变量，存储当前目录下的所有源文件
add_executable(main main.cpp)
#target_link_libraries(main pthread)
# 链接pthread库到可执行文件
# 使用CMake提供的线程包而不是直接链接pthread

add_subdirectory(base)
add_subdirectory(net)