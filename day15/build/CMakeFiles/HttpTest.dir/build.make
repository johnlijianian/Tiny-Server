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
include CMakeFiles/HttpTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HttpTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HttpTest.dir/flags.make

CMakeFiles/HttpTest.dir/HttpTest.cpp.o: CMakeFiles/HttpTest.dir/flags.make
CMakeFiles/HttpTest.dir/HttpTest.cpp.o: ../HttpTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HttpTest.dir/HttpTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HttpTest.dir/HttpTest.cpp.o -c /home/ubuntu/ljn/github/Tiny-Server/day15/HttpTest.cpp

CMakeFiles/HttpTest.dir/HttpTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HttpTest.dir/HttpTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ljn/github/Tiny-Server/day15/HttpTest.cpp > CMakeFiles/HttpTest.dir/HttpTest.cpp.i

CMakeFiles/HttpTest.dir/HttpTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HttpTest.dir/HttpTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ljn/github/Tiny-Server/day15/HttpTest.cpp -o CMakeFiles/HttpTest.dir/HttpTest.cpp.s

# Object files for target HttpTest
HttpTest_OBJECTS = \
"CMakeFiles/HttpTest.dir/HttpTest.cpp.o"

# External object files for target HttpTest
HttpTest_EXTERNAL_OBJECTS =

HttpTest: CMakeFiles/HttpTest.dir/HttpTest.cpp.o
HttpTest: CMakeFiles/HttpTest.dir/build.make
HttpTest: src/libMyMuduoLib.so
HttpTest: CMakeFiles/HttpTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HttpTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HttpTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HttpTest.dir/build: HttpTest

.PHONY : CMakeFiles/HttpTest.dir/build

CMakeFiles/HttpTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HttpTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HttpTest.dir/clean

CMakeFiles/HttpTest.dir/depend:
	cd /home/ubuntu/ljn/github/Tiny-Server/day15/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/ljn/github/Tiny-Server/day15 /home/ubuntu/ljn/github/Tiny-Server/day15 /home/ubuntu/ljn/github/Tiny-Server/day15/build /home/ubuntu/ljn/github/Tiny-Server/day15/build /home/ubuntu/ljn/github/Tiny-Server/day15/build/CMakeFiles/HttpTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HttpTest.dir/depend

