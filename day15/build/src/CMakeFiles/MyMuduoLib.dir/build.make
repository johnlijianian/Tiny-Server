# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/ljn/github/Tiny-Server/day15

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/ljn/github/Tiny-Server/day15/build

# Include any dependencies generated for this target.
include src/CMakeFiles/MyMuduoLib.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/MyMuduoLib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/MyMuduoLib.dir/flags.make

src/CMakeFiles/MyMuduoLib.dir/Acceptor.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Acceptor.cpp.o: ../src/Acceptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Acceptor.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Acceptor.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/Acceptor.cpp

src/CMakeFiles/MyMuduoLib.dir/Acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Acceptor.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/Acceptor.cpp > CMakeFiles/MyMuduoLib.dir/Acceptor.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Acceptor.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/Acceptor.cpp -o CMakeFiles/MyMuduoLib.dir/Acceptor.cpp.s

src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o: ../src/Buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/Buffer.cpp

src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Buffer.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/Buffer.cpp > CMakeFiles/MyMuduoLib.dir/Buffer.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Buffer.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/Buffer.cpp -o CMakeFiles/MyMuduoLib.dir/Buffer.cpp.s

src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o: ../src/Channel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Channel.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/Channel.cpp

src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Channel.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/Channel.cpp > CMakeFiles/MyMuduoLib.dir/Channel.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Channel.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/Channel.cpp -o CMakeFiles/MyMuduoLib.dir/Channel.cpp.s

src/CMakeFiles/MyMuduoLib.dir/Connection.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Connection.cpp.o: ../src/Connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Connection.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Connection.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/Connection.cpp

src/CMakeFiles/MyMuduoLib.dir/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Connection.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/Connection.cpp > CMakeFiles/MyMuduoLib.dir/Connection.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Connection.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/Connection.cpp -o CMakeFiles/MyMuduoLib.dir/Connection.cpp.s

src/CMakeFiles/MyMuduoLib.dir/Epoll.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Epoll.cpp.o: ../src/Epoll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Epoll.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Epoll.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/Epoll.cpp

src/CMakeFiles/MyMuduoLib.dir/Epoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Epoll.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/Epoll.cpp > CMakeFiles/MyMuduoLib.dir/Epoll.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Epoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Epoll.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/Epoll.cpp -o CMakeFiles/MyMuduoLib.dir/Epoll.cpp.s

src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o: ../src/EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/EventLoop.cpp

src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/EventLoop.cpp > CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.i

src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/EventLoop.cpp -o CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.s

src/CMakeFiles/MyMuduoLib.dir/HttpResponse.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/HttpResponse.cpp.o: ../src/HttpResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/HttpResponse.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/HttpResponse.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/HttpResponse.cpp

src/CMakeFiles/MyMuduoLib.dir/HttpResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/HttpResponse.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/HttpResponse.cpp > CMakeFiles/MyMuduoLib.dir/HttpResponse.cpp.i

src/CMakeFiles/MyMuduoLib.dir/HttpResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/HttpResponse.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/HttpResponse.cpp -o CMakeFiles/MyMuduoLib.dir/HttpResponse.cpp.s

src/CMakeFiles/MyMuduoLib.dir/HttpServer.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/HttpServer.cpp.o: ../src/HttpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/HttpServer.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/HttpServer.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/HttpServer.cpp

src/CMakeFiles/MyMuduoLib.dir/HttpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/HttpServer.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/HttpServer.cpp > CMakeFiles/MyMuduoLib.dir/HttpServer.cpp.i

src/CMakeFiles/MyMuduoLib.dir/HttpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/HttpServer.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/HttpServer.cpp -o CMakeFiles/MyMuduoLib.dir/HttpServer.cpp.s

src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o: ../src/InetAddress.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/InetAddress.cpp

src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/InetAddress.cpp > CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.i

src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/InetAddress.cpp -o CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.s

src/CMakeFiles/MyMuduoLib.dir/Server.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Server.cpp.o: ../src/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Server.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Server.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/Server.cpp

src/CMakeFiles/MyMuduoLib.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Server.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/Server.cpp > CMakeFiles/MyMuduoLib.dir/Server.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Server.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/Server.cpp -o CMakeFiles/MyMuduoLib.dir/Server.cpp.s

src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o: ../src/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Socket.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/Socket.cpp

src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Socket.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/Socket.cpp > CMakeFiles/MyMuduoLib.dir/Socket.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Socket.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/Socket.cpp -o CMakeFiles/MyMuduoLib.dir/Socket.cpp.s

src/CMakeFiles/MyMuduoLib.dir/ThreadPool.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/ThreadPool.cpp.o: ../src/ThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/ThreadPool.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/ThreadPool.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/ThreadPool.cpp

src/CMakeFiles/MyMuduoLib.dir/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/ThreadPool.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/ThreadPool.cpp > CMakeFiles/MyMuduoLib.dir/ThreadPool.cpp.i

src/CMakeFiles/MyMuduoLib.dir/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/ThreadPool.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/ThreadPool.cpp -o CMakeFiles/MyMuduoLib.dir/ThreadPool.cpp.s

src/CMakeFiles/MyMuduoLib.dir/TimeStamp.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/TimeStamp.cpp.o: ../src/TimeStamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/TimeStamp.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/TimeStamp.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/TimeStamp.cpp

src/CMakeFiles/MyMuduoLib.dir/TimeStamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/TimeStamp.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/TimeStamp.cpp > CMakeFiles/MyMuduoLib.dir/TimeStamp.cpp.i

src/CMakeFiles/MyMuduoLib.dir/TimeStamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/TimeStamp.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/TimeStamp.cpp -o CMakeFiles/MyMuduoLib.dir/TimeStamp.cpp.s

src/CMakeFiles/MyMuduoLib.dir/Timer.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Timer.cpp.o: ../src/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Timer.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Timer.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/Timer.cpp

src/CMakeFiles/MyMuduoLib.dir/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Timer.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/Timer.cpp > CMakeFiles/MyMuduoLib.dir/Timer.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Timer.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/Timer.cpp -o CMakeFiles/MyMuduoLib.dir/Timer.cpp.s

src/CMakeFiles/MyMuduoLib.dir/TimerQueue.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/TimerQueue.cpp.o: ../src/TimerQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/TimerQueue.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/TimerQueue.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/TimerQueue.cpp

src/CMakeFiles/MyMuduoLib.dir/TimerQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/TimerQueue.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/TimerQueue.cpp > CMakeFiles/MyMuduoLib.dir/TimerQueue.cpp.i

src/CMakeFiles/MyMuduoLib.dir/TimerQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/TimerQueue.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/TimerQueue.cpp -o CMakeFiles/MyMuduoLib.dir/TimerQueue.cpp.s

src/CMakeFiles/MyMuduoLib.dir/util.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/util.cpp.o: ../src/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/util.cpp.o"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/util.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/src/util.cpp

src/CMakeFiles/MyMuduoLib.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/util.cpp.i"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/src/util.cpp > CMakeFiles/MyMuduoLib.dir/util.cpp.i

src/CMakeFiles/MyMuduoLib.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/util.cpp.s"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/src/util.cpp -o CMakeFiles/MyMuduoLib.dir/util.cpp.s

# Object files for target MyMuduoLib
MyMuduoLib_OBJECTS = \
"CMakeFiles/MyMuduoLib.dir/Acceptor.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/Channel.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/Connection.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/Epoll.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/HttpResponse.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/HttpServer.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/Server.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/Socket.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/ThreadPool.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/TimeStamp.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/Timer.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/TimerQueue.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/util.cpp.o"

# External object files for target MyMuduoLib
MyMuduoLib_EXTERNAL_OBJECTS =

src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/Acceptor.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/Connection.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/Epoll.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/HttpResponse.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/HttpServer.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/Server.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/ThreadPool.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/TimeStamp.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/Timer.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/TimerQueue.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/util.cpp.o
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/build.make
src/libMyMuduoLib.so: src/CMakeFiles/MyMuduoLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX shared library libMyMuduoLib.so"
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyMuduoLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/MyMuduoLib.dir/build: src/libMyMuduoLib.so

.PHONY : src/CMakeFiles/MyMuduoLib.dir/build

src/CMakeFiles/MyMuduoLib.dir/clean:
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build/src && $(CMAKE_COMMAND) -P CMakeFiles/MyMuduoLib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/MyMuduoLib.dir/clean

src/CMakeFiles/MyMuduoLib.dir/depend:
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/ljn/github/Tiny-Server/day15 /home/ubuntu/ljn/github/Tiny-Server/day15/src /home/ubuntu/ljn/github/Tiny-Server/day15/build /home/ubuntu/ljn/github/Tiny-Server/day15/build/src /home/ubuntu/ljn/github/Tiny-Server/day15/build/src/CMakeFiles/MyMuduoLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/MyMuduoLib.dir/depend

