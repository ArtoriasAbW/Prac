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
CMAKE_COMMAND = /home/pavel/Загрузки/CLion-2019.2.4/clion-2019.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/pavel/Загрузки/CLion-2019.2.4/clion-2019.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pavel/CLionProjects/Contest/mz10-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pavel/CLionProjects/Contest/mz10-2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mz10_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mz10_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mz10_2.dir/flags.make

CMakeFiles/mz10_2.dir/main.c.o: CMakeFiles/mz10_2.dir/flags.make
CMakeFiles/mz10_2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pavel/CLionProjects/Contest/mz10-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mz10_2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mz10_2.dir/main.c.o   -c /home/pavel/CLionProjects/Contest/mz10-2/main.c

CMakeFiles/mz10_2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mz10_2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pavel/CLionProjects/Contest/mz10-2/main.c > CMakeFiles/mz10_2.dir/main.c.i

CMakeFiles/mz10_2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mz10_2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pavel/CLionProjects/Contest/mz10-2/main.c -o CMakeFiles/mz10_2.dir/main.c.s

# Object files for target mz10_2
mz10_2_OBJECTS = \
"CMakeFiles/mz10_2.dir/main.c.o"

# External object files for target mz10_2
mz10_2_EXTERNAL_OBJECTS =

mz10_2: CMakeFiles/mz10_2.dir/main.c.o
mz10_2: CMakeFiles/mz10_2.dir/build.make
mz10_2: CMakeFiles/mz10_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pavel/CLionProjects/Contest/mz10-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable mz10_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mz10_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mz10_2.dir/build: mz10_2

.PHONY : CMakeFiles/mz10_2.dir/build

CMakeFiles/mz10_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mz10_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mz10_2.dir/clean

CMakeFiles/mz10_2.dir/depend:
	cd /home/pavel/CLionProjects/Contest/mz10-2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pavel/CLionProjects/Contest/mz10-2 /home/pavel/CLionProjects/Contest/mz10-2 /home/pavel/CLionProjects/Contest/mz10-2/cmake-build-debug /home/pavel/CLionProjects/Contest/mz10-2/cmake-build-debug /home/pavel/CLionProjects/Contest/mz10-2/cmake-build-debug/CMakeFiles/mz10_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mz10_2.dir/depend
