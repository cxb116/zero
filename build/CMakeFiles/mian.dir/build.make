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
include CMakeFiles/mian.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mian.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mian.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mian.dir/flags.make

CMakeFiles/mian.dir/main.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/main.cc.o: /project/zero/main.cc
CMakeFiles/mian.dir/main.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mian.dir/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/main.cc.o -MF CMakeFiles/mian.dir/main.cc.o.d -o CMakeFiles/mian.dir/main.cc.o -c /project/zero/main.cc

CMakeFiles/mian.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/main.cc > CMakeFiles/mian.dir/main.cc.i

CMakeFiles/mian.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/main.cc -o CMakeFiles/mian.dir/main.cc.s

CMakeFiles/mian.dir/Acceptor.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/Acceptor.cc.o: /project/zero/Acceptor.cc
CMakeFiles/mian.dir/Acceptor.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mian.dir/Acceptor.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/Acceptor.cc.o -MF CMakeFiles/mian.dir/Acceptor.cc.o.d -o CMakeFiles/mian.dir/Acceptor.cc.o -c /project/zero/Acceptor.cc

CMakeFiles/mian.dir/Acceptor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/Acceptor.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/Acceptor.cc > CMakeFiles/mian.dir/Acceptor.cc.i

CMakeFiles/mian.dir/Acceptor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/Acceptor.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/Acceptor.cc -o CMakeFiles/mian.dir/Acceptor.cc.s

CMakeFiles/mian.dir/Buffer.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/Buffer.cc.o: /project/zero/Buffer.cc
CMakeFiles/mian.dir/Buffer.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mian.dir/Buffer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/Buffer.cc.o -MF CMakeFiles/mian.dir/Buffer.cc.o.d -o CMakeFiles/mian.dir/Buffer.cc.o -c /project/zero/Buffer.cc

CMakeFiles/mian.dir/Buffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/Buffer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/Buffer.cc > CMakeFiles/mian.dir/Buffer.cc.i

CMakeFiles/mian.dir/Buffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/Buffer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/Buffer.cc -o CMakeFiles/mian.dir/Buffer.cc.s

CMakeFiles/mian.dir/Channel.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/Channel.cc.o: /project/zero/Channel.cc
CMakeFiles/mian.dir/Channel.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mian.dir/Channel.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/Channel.cc.o -MF CMakeFiles/mian.dir/Channel.cc.o.d -o CMakeFiles/mian.dir/Channel.cc.o -c /project/zero/Channel.cc

CMakeFiles/mian.dir/Channel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/Channel.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/Channel.cc > CMakeFiles/mian.dir/Channel.cc.i

CMakeFiles/mian.dir/Channel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/Channel.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/Channel.cc -o CMakeFiles/mian.dir/Channel.cc.s

CMakeFiles/mian.dir/CurrentThread.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/CurrentThread.cc.o: /project/zero/CurrentThread.cc
CMakeFiles/mian.dir/CurrentThread.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mian.dir/CurrentThread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/CurrentThread.cc.o -MF CMakeFiles/mian.dir/CurrentThread.cc.o.d -o CMakeFiles/mian.dir/CurrentThread.cc.o -c /project/zero/CurrentThread.cc

CMakeFiles/mian.dir/CurrentThread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/CurrentThread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/CurrentThread.cc > CMakeFiles/mian.dir/CurrentThread.cc.i

CMakeFiles/mian.dir/CurrentThread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/CurrentThread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/CurrentThread.cc -o CMakeFiles/mian.dir/CurrentThread.cc.s

CMakeFiles/mian.dir/DefaultPoller.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/DefaultPoller.cc.o: /project/zero/DefaultPoller.cc
CMakeFiles/mian.dir/DefaultPoller.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mian.dir/DefaultPoller.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/DefaultPoller.cc.o -MF CMakeFiles/mian.dir/DefaultPoller.cc.o.d -o CMakeFiles/mian.dir/DefaultPoller.cc.o -c /project/zero/DefaultPoller.cc

CMakeFiles/mian.dir/DefaultPoller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/DefaultPoller.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/DefaultPoller.cc > CMakeFiles/mian.dir/DefaultPoller.cc.i

CMakeFiles/mian.dir/DefaultPoller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/DefaultPoller.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/DefaultPoller.cc -o CMakeFiles/mian.dir/DefaultPoller.cc.s

CMakeFiles/mian.dir/EPollPoller.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/EPollPoller.cc.o: /project/zero/EPollPoller.cc
CMakeFiles/mian.dir/EPollPoller.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/mian.dir/EPollPoller.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/EPollPoller.cc.o -MF CMakeFiles/mian.dir/EPollPoller.cc.o.d -o CMakeFiles/mian.dir/EPollPoller.cc.o -c /project/zero/EPollPoller.cc

CMakeFiles/mian.dir/EPollPoller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/EPollPoller.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/EPollPoller.cc > CMakeFiles/mian.dir/EPollPoller.cc.i

CMakeFiles/mian.dir/EPollPoller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/EPollPoller.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/EPollPoller.cc -o CMakeFiles/mian.dir/EPollPoller.cc.s

CMakeFiles/mian.dir/EventLoop.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/EventLoop.cc.o: /project/zero/EventLoop.cc
CMakeFiles/mian.dir/EventLoop.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/mian.dir/EventLoop.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/EventLoop.cc.o -MF CMakeFiles/mian.dir/EventLoop.cc.o.d -o CMakeFiles/mian.dir/EventLoop.cc.o -c /project/zero/EventLoop.cc

CMakeFiles/mian.dir/EventLoop.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/EventLoop.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/EventLoop.cc > CMakeFiles/mian.dir/EventLoop.cc.i

CMakeFiles/mian.dir/EventLoop.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/EventLoop.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/EventLoop.cc -o CMakeFiles/mian.dir/EventLoop.cc.s

CMakeFiles/mian.dir/EventLoopThread.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/EventLoopThread.cc.o: /project/zero/EventLoopThread.cc
CMakeFiles/mian.dir/EventLoopThread.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/mian.dir/EventLoopThread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/EventLoopThread.cc.o -MF CMakeFiles/mian.dir/EventLoopThread.cc.o.d -o CMakeFiles/mian.dir/EventLoopThread.cc.o -c /project/zero/EventLoopThread.cc

CMakeFiles/mian.dir/EventLoopThread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/EventLoopThread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/EventLoopThread.cc > CMakeFiles/mian.dir/EventLoopThread.cc.i

CMakeFiles/mian.dir/EventLoopThread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/EventLoopThread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/EventLoopThread.cc -o CMakeFiles/mian.dir/EventLoopThread.cc.s

CMakeFiles/mian.dir/EventLoopThreadPool.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/EventLoopThreadPool.cc.o: /project/zero/EventLoopThreadPool.cc
CMakeFiles/mian.dir/EventLoopThreadPool.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/mian.dir/EventLoopThreadPool.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/EventLoopThreadPool.cc.o -MF CMakeFiles/mian.dir/EventLoopThreadPool.cc.o.d -o CMakeFiles/mian.dir/EventLoopThreadPool.cc.o -c /project/zero/EventLoopThreadPool.cc

CMakeFiles/mian.dir/EventLoopThreadPool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/EventLoopThreadPool.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/EventLoopThreadPool.cc > CMakeFiles/mian.dir/EventLoopThreadPool.cc.i

CMakeFiles/mian.dir/EventLoopThreadPool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/EventLoopThreadPool.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/EventLoopThreadPool.cc -o CMakeFiles/mian.dir/EventLoopThreadPool.cc.s

CMakeFiles/mian.dir/InetAddress.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/InetAddress.cc.o: /project/zero/InetAddress.cc
CMakeFiles/mian.dir/InetAddress.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/mian.dir/InetAddress.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/InetAddress.cc.o -MF CMakeFiles/mian.dir/InetAddress.cc.o.d -o CMakeFiles/mian.dir/InetAddress.cc.o -c /project/zero/InetAddress.cc

CMakeFiles/mian.dir/InetAddress.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/InetAddress.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/InetAddress.cc > CMakeFiles/mian.dir/InetAddress.cc.i

CMakeFiles/mian.dir/InetAddress.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/InetAddress.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/InetAddress.cc -o CMakeFiles/mian.dir/InetAddress.cc.s

CMakeFiles/mian.dir/Logger.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/Logger.cc.o: /project/zero/Logger.cc
CMakeFiles/mian.dir/Logger.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/mian.dir/Logger.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/Logger.cc.o -MF CMakeFiles/mian.dir/Logger.cc.o.d -o CMakeFiles/mian.dir/Logger.cc.o -c /project/zero/Logger.cc

CMakeFiles/mian.dir/Logger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/Logger.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/Logger.cc > CMakeFiles/mian.dir/Logger.cc.i

CMakeFiles/mian.dir/Logger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/Logger.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/Logger.cc -o CMakeFiles/mian.dir/Logger.cc.s

CMakeFiles/mian.dir/Poller.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/Poller.cc.o: /project/zero/Poller.cc
CMakeFiles/mian.dir/Poller.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/mian.dir/Poller.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/Poller.cc.o -MF CMakeFiles/mian.dir/Poller.cc.o.d -o CMakeFiles/mian.dir/Poller.cc.o -c /project/zero/Poller.cc

CMakeFiles/mian.dir/Poller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/Poller.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/Poller.cc > CMakeFiles/mian.dir/Poller.cc.i

CMakeFiles/mian.dir/Poller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/Poller.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/Poller.cc -o CMakeFiles/mian.dir/Poller.cc.s

CMakeFiles/mian.dir/Socket.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/Socket.cc.o: /project/zero/Socket.cc
CMakeFiles/mian.dir/Socket.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/mian.dir/Socket.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/Socket.cc.o -MF CMakeFiles/mian.dir/Socket.cc.o.d -o CMakeFiles/mian.dir/Socket.cc.o -c /project/zero/Socket.cc

CMakeFiles/mian.dir/Socket.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/Socket.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/Socket.cc > CMakeFiles/mian.dir/Socket.cc.i

CMakeFiles/mian.dir/Socket.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/Socket.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/Socket.cc -o CMakeFiles/mian.dir/Socket.cc.s

CMakeFiles/mian.dir/TcpConnection.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/TcpConnection.cc.o: /project/zero/TcpConnection.cc
CMakeFiles/mian.dir/TcpConnection.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/mian.dir/TcpConnection.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/TcpConnection.cc.o -MF CMakeFiles/mian.dir/TcpConnection.cc.o.d -o CMakeFiles/mian.dir/TcpConnection.cc.o -c /project/zero/TcpConnection.cc

CMakeFiles/mian.dir/TcpConnection.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/TcpConnection.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/TcpConnection.cc > CMakeFiles/mian.dir/TcpConnection.cc.i

CMakeFiles/mian.dir/TcpConnection.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/TcpConnection.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/TcpConnection.cc -o CMakeFiles/mian.dir/TcpConnection.cc.s

CMakeFiles/mian.dir/TcpServer.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/TcpServer.cc.o: /project/zero/TcpServer.cc
CMakeFiles/mian.dir/TcpServer.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/mian.dir/TcpServer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/TcpServer.cc.o -MF CMakeFiles/mian.dir/TcpServer.cc.o.d -o CMakeFiles/mian.dir/TcpServer.cc.o -c /project/zero/TcpServer.cc

CMakeFiles/mian.dir/TcpServer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/TcpServer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/TcpServer.cc > CMakeFiles/mian.dir/TcpServer.cc.i

CMakeFiles/mian.dir/TcpServer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/TcpServer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/TcpServer.cc -o CMakeFiles/mian.dir/TcpServer.cc.s

CMakeFiles/mian.dir/Thread.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/Thread.cc.o: /project/zero/Thread.cc
CMakeFiles/mian.dir/Thread.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/mian.dir/Thread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/Thread.cc.o -MF CMakeFiles/mian.dir/Thread.cc.o.d -o CMakeFiles/mian.dir/Thread.cc.o -c /project/zero/Thread.cc

CMakeFiles/mian.dir/Thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/Thread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/Thread.cc > CMakeFiles/mian.dir/Thread.cc.i

CMakeFiles/mian.dir/Thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/Thread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/Thread.cc -o CMakeFiles/mian.dir/Thread.cc.s

CMakeFiles/mian.dir/Timestamp.cc.o: CMakeFiles/mian.dir/flags.make
CMakeFiles/mian.dir/Timestamp.cc.o: /project/zero/Timestamp.cc
CMakeFiles/mian.dir/Timestamp.cc.o: CMakeFiles/mian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/mian.dir/Timestamp.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mian.dir/Timestamp.cc.o -MF CMakeFiles/mian.dir/Timestamp.cc.o.d -o CMakeFiles/mian.dir/Timestamp.cc.o -c /project/zero/Timestamp.cc

CMakeFiles/mian.dir/Timestamp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mian.dir/Timestamp.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /project/zero/Timestamp.cc > CMakeFiles/mian.dir/Timestamp.cc.i

CMakeFiles/mian.dir/Timestamp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mian.dir/Timestamp.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /project/zero/Timestamp.cc -o CMakeFiles/mian.dir/Timestamp.cc.s

# Object files for target mian
mian_OBJECTS = \
"CMakeFiles/mian.dir/main.cc.o" \
"CMakeFiles/mian.dir/Acceptor.cc.o" \
"CMakeFiles/mian.dir/Buffer.cc.o" \
"CMakeFiles/mian.dir/Channel.cc.o" \
"CMakeFiles/mian.dir/CurrentThread.cc.o" \
"CMakeFiles/mian.dir/DefaultPoller.cc.o" \
"CMakeFiles/mian.dir/EPollPoller.cc.o" \
"CMakeFiles/mian.dir/EventLoop.cc.o" \
"CMakeFiles/mian.dir/EventLoopThread.cc.o" \
"CMakeFiles/mian.dir/EventLoopThreadPool.cc.o" \
"CMakeFiles/mian.dir/InetAddress.cc.o" \
"CMakeFiles/mian.dir/Logger.cc.o" \
"CMakeFiles/mian.dir/Poller.cc.o" \
"CMakeFiles/mian.dir/Socket.cc.o" \
"CMakeFiles/mian.dir/TcpConnection.cc.o" \
"CMakeFiles/mian.dir/TcpServer.cc.o" \
"CMakeFiles/mian.dir/Thread.cc.o" \
"CMakeFiles/mian.dir/Timestamp.cc.o"

# External object files for target mian
mian_EXTERNAL_OBJECTS =

mian: CMakeFiles/mian.dir/main.cc.o
mian: CMakeFiles/mian.dir/Acceptor.cc.o
mian: CMakeFiles/mian.dir/Buffer.cc.o
mian: CMakeFiles/mian.dir/Channel.cc.o
mian: CMakeFiles/mian.dir/CurrentThread.cc.o
mian: CMakeFiles/mian.dir/DefaultPoller.cc.o
mian: CMakeFiles/mian.dir/EPollPoller.cc.o
mian: CMakeFiles/mian.dir/EventLoop.cc.o
mian: CMakeFiles/mian.dir/EventLoopThread.cc.o
mian: CMakeFiles/mian.dir/EventLoopThreadPool.cc.o
mian: CMakeFiles/mian.dir/InetAddress.cc.o
mian: CMakeFiles/mian.dir/Logger.cc.o
mian: CMakeFiles/mian.dir/Poller.cc.o
mian: CMakeFiles/mian.dir/Socket.cc.o
mian: CMakeFiles/mian.dir/TcpConnection.cc.o
mian: CMakeFiles/mian.dir/TcpServer.cc.o
mian: CMakeFiles/mian.dir/Thread.cc.o
mian: CMakeFiles/mian.dir/Timestamp.cc.o
mian: CMakeFiles/mian.dir/build.make
mian: CMakeFiles/mian.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/project/zero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable mian"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mian.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mian.dir/build: mian
.PHONY : CMakeFiles/mian.dir/build

CMakeFiles/mian.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mian.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mian.dir/clean

CMakeFiles/mian.dir/depend:
	cd /project/zero/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /project/zero /project/zero /project/zero/build /project/zero/build /project/zero/build/CMakeFiles/mian.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mian.dir/depend

