# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.25
cmake_policy(SET CMP0009 NEW)

# srcs at base/CMakeLists.txt:2 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/project/zero/base/include/*.h")
set(OLD_GLOB
  "/project/zero/base/include/base/Buffer.h"
  "/project/zero/base/include/base/StringPiece.h"
  "/project/zero/base/include/base/Timestamp.h"
  "/project/zero/base/include/base/Types.h"
  "/project/zero/base/include/base/copyable.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/project/zero/build/CMakeFiles/cmake.verify_globs")
endif()

# srcs at base/CMakeLists.txt:2 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/project/zero/base/src/*.cpp")
set(OLD_GLOB
  "/project/zero/base/src/Buffer.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/project/zero/build/CMakeFiles/cmake.verify_globs")
endif()

# srcs at net/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/project/zero/net/include/*.h")
set(OLD_GLOB
  "/project/zero/net/include/net/Endian.h"
  "/project/zero/net/include/net/HttpRequst.h"
  "/project/zero/net/include/net/HttpResponse.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/project/zero/build/CMakeFiles/cmake.verify_globs")
endif()

# srcs at net/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/project/zero/net/src/*.cpp")
set(OLD_GLOB
  "/project/zero/net/src/HttpResponse.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/project/zero/build/CMakeFiles/cmake.verify_globs")
endif()
