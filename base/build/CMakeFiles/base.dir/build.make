# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /project/zero/base

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /project/zero/base/build

# Include any dependencies generated for this target.
include CMakeFiles/base.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/base.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/base.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/base.dir/flags.make

CMakeFiles/base.dir/src/Buffer.o: CMakeFiles/base.dir/flags.make
CMakeFiles/base.dir/src/Buffer.o: /project/zero/base/src/Buffer.cpp
CMakeFiles/base.dir/src/Buffer.o: CMakeFiles/base.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/base/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/base.dir/src/Buffer.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base.dir/src/Buffer.o -MF CMakeFiles/base.dir/src/Buffer.o.d -o CMakeFiles/base.dir/src/Buffer.o -c /project/zero/base/src/Buffer.cpp

CMakeFiles/base.dir/src/Buffer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/src/Buffer.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/base/src/Buffer.cpp > CMakeFiles/base.dir/src/Buffer.i

CMakeFiles/base.dir/src/Buffer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/src/Buffer.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/base/src/Buffer.cpp -o CMakeFiles/base.dir/src/Buffer.s

# Object files for target base
base_OBJECTS = \
"CMakeFiles/base.dir/src/Buffer.o"

# External object files for target base
base_EXTERNAL_OBJECTS =

libbase.a: CMakeFiles/base.dir/src/Buffer.o
libbase.a: CMakeFiles/base.dir/build.make
libbase.a: CMakeFiles/base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/project/zero/base/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libbase.a"
	$(CMAKE_COMMAND) -P CMakeFiles/base.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/base.dir/build: libbase.a
.PHONY : CMakeFiles/base.dir/build

CMakeFiles/base.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/base.dir/cmake_clean.cmake
.PHONY : CMakeFiles/base.dir/clean

CMakeFiles/base.dir/depend:
	cd /project/zero/base/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /project/zero/base /project/zero/base /project/zero/base/build /project/zero/base/build /project/zero/base/build/CMakeFiles/base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/base.dir/depend
