#file （GLOB/GLOB_RECURSE 变量名，要搜索的文件路径和文件类型）
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(base STATIC ${srcs})
target_include_directories(base PUBLIC include)
