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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/csm/clickMox/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csm/clickMox/catkin_ws/build

# Include any dependencies generated for this target.
include motordriver/CMakeFiles/roboclaw.dir/depend.make

# Include the progress variables for this target.
include motordriver/CMakeFiles/roboclaw.dir/progress.make

# Include the compile flags for this target's objects.
include motordriver/CMakeFiles/roboclaw.dir/flags.make

motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o: motordriver/CMakeFiles/roboclaw.dir/flags.make
motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o: /home/csm/clickMox/catkin_ws/src/motordriver/src/roboclaw.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csm/clickMox/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o"
	cd /home/csm/clickMox/catkin_ws/build/motordriver && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/roboclaw.dir/src/roboclaw.c.o   -c /home/csm/clickMox/catkin_ws/src/motordriver/src/roboclaw.c

motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/roboclaw.dir/src/roboclaw.c.i"
	cd /home/csm/clickMox/catkin_ws/build/motordriver && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csm/clickMox/catkin_ws/src/motordriver/src/roboclaw.c > CMakeFiles/roboclaw.dir/src/roboclaw.c.i

motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/roboclaw.dir/src/roboclaw.c.s"
	cd /home/csm/clickMox/catkin_ws/build/motordriver && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csm/clickMox/catkin_ws/src/motordriver/src/roboclaw.c -o CMakeFiles/roboclaw.dir/src/roboclaw.c.s

motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o.requires:

.PHONY : motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o.requires

motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o.provides: motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o.requires
	$(MAKE) -f motordriver/CMakeFiles/roboclaw.dir/build.make motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o.provides.build
.PHONY : motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o.provides

motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o.provides.build: motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o


# Object files for target roboclaw
roboclaw_OBJECTS = \
"CMakeFiles/roboclaw.dir/src/roboclaw.c.o"

# External object files for target roboclaw
roboclaw_EXTERNAL_OBJECTS =

/home/csm/clickMox/catkin_ws/devel/lib/libroboclaw.so: motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o
/home/csm/clickMox/catkin_ws/devel/lib/libroboclaw.so: motordriver/CMakeFiles/roboclaw.dir/build.make
/home/csm/clickMox/catkin_ws/devel/lib/libroboclaw.so: motordriver/CMakeFiles/roboclaw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/csm/clickMox/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library /home/csm/clickMox/catkin_ws/devel/lib/libroboclaw.so"
	cd /home/csm/clickMox/catkin_ws/build/motordriver && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/roboclaw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
motordriver/CMakeFiles/roboclaw.dir/build: /home/csm/clickMox/catkin_ws/devel/lib/libroboclaw.so

.PHONY : motordriver/CMakeFiles/roboclaw.dir/build

motordriver/CMakeFiles/roboclaw.dir/requires: motordriver/CMakeFiles/roboclaw.dir/src/roboclaw.c.o.requires

.PHONY : motordriver/CMakeFiles/roboclaw.dir/requires

motordriver/CMakeFiles/roboclaw.dir/clean:
	cd /home/csm/clickMox/catkin_ws/build/motordriver && $(CMAKE_COMMAND) -P CMakeFiles/roboclaw.dir/cmake_clean.cmake
.PHONY : motordriver/CMakeFiles/roboclaw.dir/clean

motordriver/CMakeFiles/roboclaw.dir/depend:
	cd /home/csm/clickMox/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csm/clickMox/catkin_ws/src /home/csm/clickMox/catkin_ws/src/motordriver /home/csm/clickMox/catkin_ws/build /home/csm/clickMox/catkin_ws/build/motordriver /home/csm/clickMox/catkin_ws/build/motordriver/CMakeFiles/roboclaw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : motordriver/CMakeFiles/roboclaw.dir/depend

