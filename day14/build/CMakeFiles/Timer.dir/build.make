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
CMAKE_SOURCE_DIR = /home/ubuntu/ljn/github/Tiny-Server/day13

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/ljn/github/Tiny-Server/day13/build

# Include any dependencies generated for this target.
include CMakeFiles/Timer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Timer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Timer.dir/flags.make

CMakeFiles/Timer.dir/timer_test.cpp.o: CMakeFiles/Timer.dir/flags.make
CMakeFiles/Timer.dir/timer_test.cpp.o: ../timer_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day13/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Timer.dir/timer_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Timer.dir/timer_test.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day13/timer_test.cpp

CMakeFiles/Timer.dir/timer_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Timer.dir/timer_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day13/timer_test.cpp > CMakeFiles/Timer.dir/timer_test.cpp.i

CMakeFiles/Timer.dir/timer_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Timer.dir/timer_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day13/timer_test.cpp -o CMakeFiles/Timer.dir/timer_test.cpp.s

CMakeFiles/Timer.dir/ThreadPoolTest.cpp.o: CMakeFiles/Timer.dir/flags.make
CMakeFiles/Timer.dir/ThreadPoolTest.cpp.o: ../ThreadPoolTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day13/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Timer.dir/ThreadPoolTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Timer.dir/ThreadPoolTest.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day13/ThreadPoolTest.cpp

CMakeFiles/Timer.dir/ThreadPoolTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Timer.dir/ThreadPoolTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day13/ThreadPoolTest.cpp > CMakeFiles/Timer.dir/ThreadPoolTest.cpp.i

CMakeFiles/Timer.dir/ThreadPoolTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Timer.dir/ThreadPoolTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day13/ThreadPoolTest.cpp -o CMakeFiles/Timer.dir/ThreadPoolTest.cpp.s

CMakeFiles/Timer.dir/client.cpp.o: CMakeFiles/Timer.dir/flags.make
CMakeFiles/Timer.dir/client.cpp.o: ../client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day13/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Timer.dir/client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Timer.dir/client.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day13/client.cpp

CMakeFiles/Timer.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Timer.dir/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day13/client.cpp > CMakeFiles/Timer.dir/client.cpp.i

CMakeFiles/Timer.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Timer.dir/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day13/client.cpp -o CMakeFiles/Timer.dir/client.cpp.s

CMakeFiles/Timer.dir/server.cpp.o: CMakeFiles/Timer.dir/flags.make
CMakeFiles/Timer.dir/server.cpp.o: ../server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day13/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Timer.dir/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Timer.dir/server.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day13/server.cpp

CMakeFiles/Timer.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Timer.dir/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day13/server.cpp > CMakeFiles/Timer.dir/server.cpp.i

CMakeFiles/Timer.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Timer.dir/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day13/server.cpp -o CMakeFiles/Timer.dir/server.cpp.s

CMakeFiles/Timer.dir/test.cpp.o: CMakeFiles/Timer.dir/flags.make
CMakeFiles/Timer.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day13/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Timer.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Timer.dir/test.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day13/test.cpp

CMakeFiles/Timer.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Timer.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day13/test.cpp > CMakeFiles/Timer.dir/test.cpp.i

CMakeFiles/Timer.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Timer.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day13/test.cpp -o CMakeFiles/Timer.dir/test.cpp.s

# Object files for target Timer
Timer_OBJECTS = \
"CMakeFiles/Timer.dir/timer_test.cpp.o" \
"CMakeFiles/Timer.dir/ThreadPoolTest.cpp.o" \
"CMakeFiles/Timer.dir/client.cpp.o" \
"CMakeFiles/Timer.dir/server.cpp.o" \
"CMakeFiles/Timer.dir/test.cpp.o"

# External object files for target Timer
Timer_EXTERNAL_OBJECTS =

Timer: CMakeFiles/Timer.dir/timer_test.cpp.o
Timer: CMakeFiles/Timer.dir/ThreadPoolTest.cpp.o
Timer: CMakeFiles/Timer.dir/client.cpp.o
Timer: CMakeFiles/Timer.dir/server.cpp.o
Timer: CMakeFiles/Timer.dir/test.cpp.o
Timer: CMakeFiles/Timer.dir/build.make
Timer: CMakeFiles/Timer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day13/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Timer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Timer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Timer.dir/build: Timer

.PHONY : CMakeFiles/Timer.dir/build

CMakeFiles/Timer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Timer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Timer.dir/clean

CMakeFiles/Timer.dir/depend:
	cd /home/ubuntu/ljn/github/Tiny-Server/day13/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/ljn/github/Tiny-Server/day13 /home/ubuntu/ljn/github/Tiny-Server/day13 /home/ubuntu/ljn/github/Tiny-Server/day13/build /home/ubuntu/ljn/github/Tiny-Server/day13/build /home/ubuntu/ljn/github/Tiny-Server/day13/build/CMakeFiles/Timer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Timer.dir/depend
