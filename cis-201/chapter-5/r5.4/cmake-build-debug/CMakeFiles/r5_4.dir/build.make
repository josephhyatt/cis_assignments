# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/jedi/clion/clion-2018.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/jedi/clion/clion-2018.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/r5_4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/r5_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/r5_4.dir/flags.make

CMakeFiles/r5_4.dir/main.cpp.o: CMakeFiles/r5_4.dir/flags.make
CMakeFiles/r5_4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/r5_4.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r5_4.dir/main.cpp.o -c /home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4/main.cpp

CMakeFiles/r5_4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r5_4.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4/main.cpp > CMakeFiles/r5_4.dir/main.cpp.i

CMakeFiles/r5_4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r5_4.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4/main.cpp -o CMakeFiles/r5_4.dir/main.cpp.s

CMakeFiles/r5_4.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/r5_4.dir/main.cpp.o.requires

CMakeFiles/r5_4.dir/main.cpp.o.provides: CMakeFiles/r5_4.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/r5_4.dir/build.make CMakeFiles/r5_4.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/r5_4.dir/main.cpp.o.provides

CMakeFiles/r5_4.dir/main.cpp.o.provides.build: CMakeFiles/r5_4.dir/main.cpp.o


# Object files for target r5_4
r5_4_OBJECTS = \
"CMakeFiles/r5_4.dir/main.cpp.o"

# External object files for target r5_4
r5_4_EXTERNAL_OBJECTS =

r5_4: CMakeFiles/r5_4.dir/main.cpp.o
r5_4: CMakeFiles/r5_4.dir/build.make
r5_4: CMakeFiles/r5_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable r5_4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/r5_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/r5_4.dir/build: r5_4

.PHONY : CMakeFiles/r5_4.dir/build

CMakeFiles/r5_4.dir/requires: CMakeFiles/r5_4.dir/main.cpp.o.requires

.PHONY : CMakeFiles/r5_4.dir/requires

CMakeFiles/r5_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/r5_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/r5_4.dir/clean

CMakeFiles/r5_4.dir/depend:
	cd /home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4 /home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4 /home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4/cmake-build-debug /home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4/cmake-build-debug /home/jedi/code/vvc-assignments/cis-201/chapter-5/r5.4/cmake-build-debug/CMakeFiles/r5_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/r5_4.dir/depend
