file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_executable(src ${srcs})
target_include_directories(src PUBLIC include)
target_link_libraries(src PUBLIC base)