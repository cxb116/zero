cmake_minimum_required(VERSION 3.0)
project(main LANGUAGES C CXX)
# 优化
#set(CMAKE_BUILD_TYPE Release)   # 发布模式  他会使assert 失效
#set(CMAKE_BUILD_TYPE Debug)     # 完全不优化生成测试信息，方便调试

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # 编译器在检测到不支持c++ 11 时报错
set(CMAKE_CXX_EXTENSIONS OFF)
# 添加头文件
include_directories(base/include/ net/include/)
add_subdirectory(base)
add_subdirectory(net)

#=======================================================
# 链接pthread库到可执行文件
# 使用CMake提供的线程包而不是直接链接pthread
# target_link_libraries(main pthread)

# set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake;${CMAKE_MODULE_PATH}")
# include (MyUserfulFuncs)
# 设置cmake的全局变量
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR} /include)
# # 添加头文件

#aux_source_directory(. SRC_LIST) # 定义变量，存储当前目录下的所有源文件
#add_executable(main main.cpp)
#=======================================================
# 追加cpp 文件 方法1
#set(sources main.cpp other.cpp)
#target_sources(main PUBLIC ${sources})

# 所有cpp 和 .h  方法2
# file(GLOB sources *.cpp *.h)
# target_sources(main PUBLIC ${sources})

# aux_source_directory(. sources)

# aux_source_directory(base sources)
# target_sources(main PUBLIC ${sources})





