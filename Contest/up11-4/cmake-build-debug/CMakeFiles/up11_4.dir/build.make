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
CMAKE_SOURCE_DIR = /home/pavel/CLionProjects/Contest/up11-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pavel/CLionProjects/Contest/up11-4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/up11_4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/up11_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/up11_4.dir/flags.make

CMakeFiles/up11_4.dir/main.c.o: CMakeFiles/up11_4.dir/flags.make
CMakeFiles/up11_4.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pavel/CLionProjects/Contest/up11-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/up11_4.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/up11_4.dir/main.c.o   -c /home/pavel/CLionProjects/Contest/up11-4/main.c

CMakeFiles/up11_4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/up11_4.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pavel/CLionProjects/Contest/up11-4/main.c > CMakeFiles/up11_4.dir/main.c.i

CMakeFiles/up11_4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/up11_4.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pavel/CLionProjects/Contest/up11-4/main.c -o CMakeFiles/up11_4.dir/main.c.s

# Object files for target up11_4
up11_4_OBJECTS = \
"CMakeFiles/up11_4.dir/main.c.o"

# External object files for target up11_4
up11_4_EXTERNAL_OBJECTS =

up11_4: CMakeFiles/up11_4.dir/main.c.o
up11_4: CMakeFiles/up11_4.dir/build.make
up11_4: CMakeFiles/up11_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pavel/CLionProjects/Contest/up11-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable up11_4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/up11_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/up11_4.dir/build: up11_4

.PHONY : CMakeFiles/up11_4.dir/build

CMakeFiles/up11_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/up11_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/up11_4.dir/clean

CMakeFiles/up11_4.dir/depend:
	cd /home/pavel/CLionProjects/Contest/up11-4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pavel/CLionProjects/Contest/up11-4 /home/pavel/CLionProjects/Contest/up11-4 /home/pavel/CLionProjects/Contest/up11-4/cmake-build-debug /home/pavel/CLionProjects/Contest/up11-4/cmake-build-debug /home/pavel/CLionProjects/Contest/up11-4/cmake-build-debug/CMakeFiles/up11_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/up11_4.dir/depend

