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
CMAKE_SOURCE_DIR = /project/zero

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /project/zero/build

# Include any dependencies generated for this target.
include net/CMakeFiles/src.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include net/CMakeFiles/src.dir/compiler_depend.make

# Include the progress variables for this target.
include net/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include net/CMakeFiles/src.dir/flags.make

net/CMakeFiles/src.dir/src/Channel.cpp.o: net/CMakeFiles/src.dir/flags.make
net/CMakeFiles/src.dir/src/Channel.cpp.o: /project/zero/net/src/Channel.cpp
net/CMakeFiles/src.dir/src/Channel.cpp.o: net/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object net/CMakeFiles/src.dir/src/Channel.cpp.o"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/src.dir/src/Channel.cpp.o -MF CMakeFiles/src.dir/src/Channel.cpp.o.d -o CMakeFiles/src.dir/src/Channel.cpp.o -c /project/zero/net/src/Channel.cpp

net/CMakeFiles/src.dir/src/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src/Channel.cpp.i"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/net/src/Channel.cpp > CMakeFiles/src.dir/src/Channel.cpp.i

net/CMakeFiles/src.dir/src/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src/Channel.cpp.s"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/net/src/Channel.cpp -o CMakeFiles/src.dir/src/Channel.cpp.s

net/CMakeFiles/src.dir/src/DefaultPoller.cpp.o: net/CMakeFiles/src.dir/flags.make
net/CMakeFiles/src.dir/src/DefaultPoller.cpp.o: /project/zero/net/src/DefaultPoller.cpp
net/CMakeFiles/src.dir/src/DefaultPoller.cpp.o: net/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object net/CMakeFiles/src.dir/src/DefaultPoller.cpp.o"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/src.dir/src/DefaultPoller.cpp.o -MF CMakeFiles/src.dir/src/DefaultPoller.cpp.o.d -o CMakeFiles/src.dir/src/DefaultPoller.cpp.o -c /project/zero/net/src/DefaultPoller.cpp

net/CMakeFiles/src.dir/src/DefaultPoller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src/DefaultPoller.cpp.i"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/net/src/DefaultPoller.cpp > CMakeFiles/src.dir/src/DefaultPoller.cpp.i

net/CMakeFiles/src.dir/src/DefaultPoller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src/DefaultPoller.cpp.s"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/net/src/DefaultPoller.cpp -o CMakeFiles/src.dir/src/DefaultPoller.cpp.s

net/CMakeFiles/src.dir/src/EPollerPoller.cpp.o: net/CMakeFiles/src.dir/flags.make
net/CMakeFiles/src.dir/src/EPollerPoller.cpp.o: /project/zero/net/src/EPollerPoller.cpp
net/CMakeFiles/src.dir/src/EPollerPoller.cpp.o: net/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object net/CMakeFiles/src.dir/src/EPollerPoller.cpp.o"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/src.dir/src/EPollerPoller.cpp.o -MF CMakeFiles/src.dir/src/EPollerPoller.cpp.o.d -o CMakeFiles/src.dir/src/EPollerPoller.cpp.o -c /project/zero/net/src/EPollerPoller.cpp

net/CMakeFiles/src.dir/src/EPollerPoller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src/EPollerPoller.cpp.i"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/net/src/EPollerPoller.cpp > CMakeFiles/src.dir/src/EPollerPoller.cpp.i

net/CMakeFiles/src.dir/src/EPollerPoller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src/EPollerPoller.cpp.s"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/net/src/EPollerPoller.cpp -o CMakeFiles/src.dir/src/EPollerPoller.cpp.s

net/CMakeFiles/src.dir/src/EventLoop.cpp.o: net/CMakeFiles/src.dir/flags.make
net/CMakeFiles/src.dir/src/EventLoop.cpp.o: /project/zero/net/src/EventLoop.cpp
net/CMakeFiles/src.dir/src/EventLoop.cpp.o: net/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object net/CMakeFiles/src.dir/src/EventLoop.cpp.o"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/src.dir/src/EventLoop.cpp.o -MF CMakeFiles/src.dir/src/EventLoop.cpp.o.d -o CMakeFiles/src.dir/src/EventLoop.cpp.o -c /project/zero/net/src/EventLoop.cpp

net/CMakeFiles/src.dir/src/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src/EventLoop.cpp.i"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/net/src/EventLoop.cpp > CMakeFiles/src.dir/src/EventLoop.cpp.i

net/CMakeFiles/src.dir/src/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src/EventLoop.cpp.s"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/net/src/EventLoop.cpp -o CMakeFiles/src.dir/src/EventLoop.cpp.s

net/CMakeFiles/src.dir/src/EventLoopThread.cpp.o: net/CMakeFiles/src.dir/flags.make
net/CMakeFiles/src.dir/src/EventLoopThread.cpp.o: /project/zero/net/src/EventLoopThread.cpp
net/CMakeFiles/src.dir/src/EventLoopThread.cpp.o: net/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object net/CMakeFiles/src.dir/src/EventLoopThread.cpp.o"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/src.dir/src/EventLoopThread.cpp.o -MF CMakeFiles/src.dir/src/EventLoopThread.cpp.o.d -o CMakeFiles/src.dir/src/EventLoopThread.cpp.o -c /project/zero/net/src/EventLoopThread.cpp

net/CMakeFiles/src.dir/src/EventLoopThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src/EventLoopThread.cpp.i"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/net/src/EventLoopThread.cpp > CMakeFiles/src.dir/src/EventLoopThread.cpp.i

net/CMakeFiles/src.dir/src/EventLoopThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src/EventLoopThread.cpp.s"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/net/src/EventLoopThread.cpp -o CMakeFiles/src.dir/src/EventLoopThread.cpp.s

net/CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.o: net/CMakeFiles/src.dir/flags.make
net/CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.o: /project/zero/net/src/EventLoopThreadPool.cpp
net/CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.o: net/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object net/CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.o"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.o -MF CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.o.d -o CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.o -c /project/zero/net/src/EventLoopThreadPool.cpp

net/CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.i"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/net/src/EventLoopThreadPool.cpp > CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.i

net/CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.s"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/net/src/EventLoopThreadPool.cpp -o CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.s

net/CMakeFiles/src.dir/src/HttpResponse.cpp.o: net/CMakeFiles/src.dir/flags.make
net/CMakeFiles/src.dir/src/HttpResponse.cpp.o: /project/zero/net/src/HttpResponse.cpp
net/CMakeFiles/src.dir/src/HttpResponse.cpp.o: net/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object net/CMakeFiles/src.dir/src/HttpResponse.cpp.o"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/src.dir/src/HttpResponse.cpp.o -MF CMakeFiles/src.dir/src/HttpResponse.cpp.o.d -o CMakeFiles/src.dir/src/HttpResponse.cpp.o -c /project/zero/net/src/HttpResponse.cpp

net/CMakeFiles/src.dir/src/HttpResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src/HttpResponse.cpp.i"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/net/src/HttpResponse.cpp > CMakeFiles/src.dir/src/HttpResponse.cpp.i

net/CMakeFiles/src.dir/src/HttpResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src/HttpResponse.cpp.s"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/net/src/HttpResponse.cpp -o CMakeFiles/src.dir/src/HttpResponse.cpp.s

net/CMakeFiles/src.dir/src/InetAddress.cpp.o: net/CMakeFiles/src.dir/flags.make
net/CMakeFiles/src.dir/src/InetAddress.cpp.o: /project/zero/net/src/InetAddress.cpp
net/CMakeFiles/src.dir/src/InetAddress.cpp.o: net/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object net/CMakeFiles/src.dir/src/InetAddress.cpp.o"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/src.dir/src/InetAddress.cpp.o -MF CMakeFiles/src.dir/src/InetAddress.cpp.o.d -o CMakeFiles/src.dir/src/InetAddress.cpp.o -c /project/zero/net/src/InetAddress.cpp

net/CMakeFiles/src.dir/src/InetAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src/InetAddress.cpp.i"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/net/src/InetAddress.cpp > CMakeFiles/src.dir/src/InetAddress.cpp.i

net/CMakeFiles/src.dir/src/InetAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src/InetAddress.cpp.s"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/net/src/InetAddress.cpp -o CMakeFiles/src.dir/src/InetAddress.cpp.s

net/CMakeFiles/src.dir/src/Poller.cpp.o: net/CMakeFiles/src.dir/flags.make
net/CMakeFiles/src.dir/src/Poller.cpp.o: /project/zero/net/src/Poller.cpp
net/CMakeFiles/src.dir/src/Poller.cpp.o: net/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object net/CMakeFiles/src.dir/src/Poller.cpp.o"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/src.dir/src/Poller.cpp.o -MF CMakeFiles/src.dir/src/Poller.cpp.o.d -o CMakeFiles/src.dir/src/Poller.cpp.o -c /project/zero/net/src/Poller.cpp

net/CMakeFiles/src.dir/src/Poller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src/Poller.cpp.i"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/net/src/Poller.cpp > CMakeFiles/src.dir/src/Poller.cpp.i

net/CMakeFiles/src.dir/src/Poller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src/Poller.cpp.s"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/net/src/Poller.cpp -o CMakeFiles/src.dir/src/Poller.cpp.s

net/CMakeFiles/src.dir/src/SocketsOps.cpp.o: net/CMakeFiles/src.dir/flags.make
net/CMakeFiles/src.dir/src/SocketsOps.cpp.o: /project/zero/net/src/SocketsOps.cpp
net/CMakeFiles/src.dir/src/SocketsOps.cpp.o: net/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object net/CMakeFiles/src.dir/src/SocketsOps.cpp.o"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/src.dir/src/SocketsOps.cpp.o -MF CMakeFiles/src.dir/src/SocketsOps.cpp.o.d -o CMakeFiles/src.dir/src/SocketsOps.cpp.o -c /project/zero/net/src/SocketsOps.cpp

net/CMakeFiles/src.dir/src/SocketsOps.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src/SocketsOps.cpp.i"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/net/src/SocketsOps.cpp > CMakeFiles/src.dir/src/SocketsOps.cpp.i

net/CMakeFiles/src.dir/src/SocketsOps.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src/SocketsOps.cpp.s"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/net/src/SocketsOps.cpp -o CMakeFiles/src.dir/src/SocketsOps.cpp.s

net/CMakeFiles/src.dir/src/TcpServer.cpp.o: net/CMakeFiles/src.dir/flags.make
net/CMakeFiles/src.dir/src/TcpServer.cpp.o: /project/zero/net/src/TcpServer.cpp
net/CMakeFiles/src.dir/src/TcpServer.cpp.o: net/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object net/CMakeFiles/src.dir/src/TcpServer.cpp.o"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/src.dir/src/TcpServer.cpp.o -MF CMakeFiles/src.dir/src/TcpServer.cpp.o.d -o CMakeFiles/src.dir/src/TcpServer.cpp.o -c /project/zero/net/src/TcpServer.cpp

net/CMakeFiles/src.dir/src/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src/TcpServer.cpp.i"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/net/src/TcpServer.cpp > CMakeFiles/src.dir/src/TcpServer.cpp.i

net/CMakeFiles/src.dir/src/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src/TcpServer.cpp.s"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/net/src/TcpServer.cpp -o CMakeFiles/src.dir/src/TcpServer.cpp.s

net/CMakeFiles/src.dir/src/main.cpp.o: net/CMakeFiles/src.dir/flags.make
net/CMakeFiles/src.dir/src/main.cpp.o: /project/zero/net/src/main.cpp
net/CMakeFiles/src.dir/src/main.cpp.o: net/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object net/CMakeFiles/src.dir/src/main.cpp.o"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT net/CMakeFiles/src.dir/src/main.cpp.o -MF CMakeFiles/src.dir/src/main.cpp.o.d -o CMakeFiles/src.dir/src/main.cpp.o -c /project/zero/net/src/main.cpp

net/CMakeFiles/src.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src/main.cpp.i"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/net/src/main.cpp > CMakeFiles/src.dir/src/main.cpp.i

net/CMakeFiles/src.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src/main.cpp.s"
	cd /project/zero/build/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/net/src/main.cpp -o CMakeFiles/src.dir/src/main.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/src/Channel.cpp.o" \
"CMakeFiles/src.dir/src/DefaultPoller.cpp.o" \
"CMakeFiles/src.dir/src/EPollerPoller.cpp.o" \
"CMakeFiles/src.dir/src/EventLoop.cpp.o" \
"CMakeFiles/src.dir/src/EventLoopThread.cpp.o" \
"CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.o" \
"CMakeFiles/src.dir/src/HttpResponse.cpp.o" \
"CMakeFiles/src.dir/src/InetAddress.cpp.o" \
"CMakeFiles/src.dir/src/Poller.cpp.o" \
"CMakeFiles/src.dir/src/SocketsOps.cpp.o" \
"CMakeFiles/src.dir/src/TcpServer.cpp.o" \
"CMakeFiles/src.dir/src/main.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

net/src: net/CMakeFiles/src.dir/src/Channel.cpp.o
net/src: net/CMakeFiles/src.dir/src/DefaultPoller.cpp.o
net/src: net/CMakeFiles/src.dir/src/EPollerPoller.cpp.o
net/src: net/CMakeFiles/src.dir/src/EventLoop.cpp.o
net/src: net/CMakeFiles/src.dir/src/EventLoopThread.cpp.o
net/src: net/CMakeFiles/src.dir/src/EventLoopThreadPool.cpp.o
net/src: net/CMakeFiles/src.dir/src/HttpResponse.cpp.o
net/src: net/CMakeFiles/src.dir/src/InetAddress.cpp.o
net/src: net/CMakeFiles/src.dir/src/Poller.cpp.o
net/src: net/CMakeFiles/src.dir/src/SocketsOps.cpp.o
net/src: net/CMakeFiles/src.dir/src/TcpServer.cpp.o
net/src: net/CMakeFiles/src.dir/src/main.cpp.o
net/src: net/CMakeFiles/src.dir/build.make
net/src: base/libbase.a
net/src: net/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable src"
	cd /project/zero/build/net && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
net/CMakeFiles/src.dir/build: net/src
.PHONY : net/CMakeFiles/src.dir/build

net/CMakeFiles/src.dir/clean:
	cd /project/zero/build/net && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : net/CMakeFiles/src.dir/clean

net/CMakeFiles/src.dir/depend:
	cd /project/zero/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /project/zero /project/zero/net /project/zero/build /project/zero/build/net /project/zero/build/net/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : net/CMakeFiles/src.dir/depend

