# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/85/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/85/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pavel/CLionProjects/Contest/up05-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pavel/CLionProjects/Contest/up05-1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/up05_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/up05_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/up05_1.dir/flags.make

CMakeFiles/up05_1.dir/main.c.o: CMakeFiles/up05_1.dir/flags.make
CMakeFiles/up05_1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pavel/CLionProjects/Contest/up05-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/up05_1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/up05_1.dir/main.c.o   -c /home/pavel/CLionProjects/Contest/up05-1/main.c

CMakeFiles/up05_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/up05_1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pavel/CLionProjects/Contest/up05-1/main.c > CMakeFiles/up05_1.dir/main.c.i

CMakeFiles/up05_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/up05_1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pavel/CLionProjects/Contest/up05-1/main.c -o CMakeFiles/up05_1.dir/main.c.s

# Object files for target up05_1
up05_1_OBJECTS = \
"CMakeFiles/up05_1.dir/main.c.o"

# External object files for target up05_1
up05_1_EXTERNAL_OBJECTS =

up05_1: CMakeFiles/up05_1.dir/main.c.o
up05_1: CMakeFiles/up05_1.dir/build.make
up05_1: CMakeFiles/up05_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pavel/CLionProjects/Contest/up05-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable up05_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/up05_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/up05_1.dir/build: up05_1

.PHONY : CMakeFiles/up05_1.dir/build

CMakeFiles/up05_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/up05_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/up05_1.dir/clean

CMakeFiles/up05_1.dir/depend:
	cd /home/pavel/CLionProjects/Contest/up05-1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pavel/CLionProjects/Contest/up05-1 /home/pavel/CLionProjects/Contest/up05-1 /home/pavel/CLionProjects/Contest/up05-1/cmake-build-debug /home/pavel/CLionProjects/Contest/up05-1/cmake-build-debug /home/pavel/CLionProjects/Contest/up05-1/cmake-build-debug/CMakeFiles/up05_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/up05_1.dir/depend

