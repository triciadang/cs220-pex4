# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /cygdrive/c/Users/C20Tricia.Dang/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/C20Tricia.Dang/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PEX4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PEX4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PEX4.dir/flags.make

CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o: CMakeFiles/PEX4.dir/flags.make
CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o: ../PEX4_Shannon_switching_game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o   -c /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/PEX4_Shannon_switching_game.c

CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/PEX4_Shannon_switching_game.c > CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.i

CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/PEX4_Shannon_switching_game.c -o CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.s

CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o.requires:

.PHONY : CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o.requires

CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o.provides: CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o.requires
	$(MAKE) -f CMakeFiles/PEX4.dir/build.make CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o.provides.build
.PHONY : CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o.provides

CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o.provides.build: CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o


CMakeFiles/PEX4.dir/gameLogic.c.o: CMakeFiles/PEX4.dir/flags.make
CMakeFiles/PEX4.dir/gameLogic.c.o: ../gameLogic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/PEX4.dir/gameLogic.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PEX4.dir/gameLogic.c.o   -c /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/gameLogic.c

CMakeFiles/PEX4.dir/gameLogic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PEX4.dir/gameLogic.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/gameLogic.c > CMakeFiles/PEX4.dir/gameLogic.c.i

CMakeFiles/PEX4.dir/gameLogic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PEX4.dir/gameLogic.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/gameLogic.c -o CMakeFiles/PEX4.dir/gameLogic.c.s

CMakeFiles/PEX4.dir/gameLogic.c.o.requires:

.PHONY : CMakeFiles/PEX4.dir/gameLogic.c.o.requires

CMakeFiles/PEX4.dir/gameLogic.c.o.provides: CMakeFiles/PEX4.dir/gameLogic.c.o.requires
	$(MAKE) -f CMakeFiles/PEX4.dir/build.make CMakeFiles/PEX4.dir/gameLogic.c.o.provides.build
.PHONY : CMakeFiles/PEX4.dir/gameLogic.c.o.provides

CMakeFiles/PEX4.dir/gameLogic.c.o.provides.build: CMakeFiles/PEX4.dir/gameLogic.c.o


CMakeFiles/PEX4.dir/graphics.c.o: CMakeFiles/PEX4.dir/flags.make
CMakeFiles/PEX4.dir/graphics.c.o: ../graphics.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/PEX4.dir/graphics.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PEX4.dir/graphics.c.o   -c /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/graphics.c

CMakeFiles/PEX4.dir/graphics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PEX4.dir/graphics.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/graphics.c > CMakeFiles/PEX4.dir/graphics.c.i

CMakeFiles/PEX4.dir/graphics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PEX4.dir/graphics.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/graphics.c -o CMakeFiles/PEX4.dir/graphics.c.s

CMakeFiles/PEX4.dir/graphics.c.o.requires:

.PHONY : CMakeFiles/PEX4.dir/graphics.c.o.requires

CMakeFiles/PEX4.dir/graphics.c.o.provides: CMakeFiles/PEX4.dir/graphics.c.o.requires
	$(MAKE) -f CMakeFiles/PEX4.dir/build.make CMakeFiles/PEX4.dir/graphics.c.o.provides.build
.PHONY : CMakeFiles/PEX4.dir/graphics.c.o.provides

CMakeFiles/PEX4.dir/graphics.c.o.provides.build: CMakeFiles/PEX4.dir/graphics.c.o


CMakeFiles/PEX4.dir/Graph.c.o: CMakeFiles/PEX4.dir/flags.make
CMakeFiles/PEX4.dir/Graph.c.o: ../Graph.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/PEX4.dir/Graph.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PEX4.dir/Graph.c.o   -c /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/Graph.c

CMakeFiles/PEX4.dir/Graph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PEX4.dir/Graph.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/Graph.c > CMakeFiles/PEX4.dir/Graph.c.i

CMakeFiles/PEX4.dir/Graph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PEX4.dir/Graph.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/Graph.c -o CMakeFiles/PEX4.dir/Graph.c.s

CMakeFiles/PEX4.dir/Graph.c.o.requires:

.PHONY : CMakeFiles/PEX4.dir/Graph.c.o.requires

CMakeFiles/PEX4.dir/Graph.c.o.provides: CMakeFiles/PEX4.dir/Graph.c.o.requires
	$(MAKE) -f CMakeFiles/PEX4.dir/build.make CMakeFiles/PEX4.dir/Graph.c.o.provides.build
.PHONY : CMakeFiles/PEX4.dir/Graph.c.o.provides

CMakeFiles/PEX4.dir/Graph.c.o.provides.build: CMakeFiles/PEX4.dir/Graph.c.o


# Object files for target PEX4
PEX4_OBJECTS = \
"CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o" \
"CMakeFiles/PEX4.dir/gameLogic.c.o" \
"CMakeFiles/PEX4.dir/graphics.c.o" \
"CMakeFiles/PEX4.dir/Graph.c.o"

# External object files for target PEX4
PEX4_EXTERNAL_OBJECTS =

PEX4.exe: CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o
PEX4.exe: CMakeFiles/PEX4.dir/gameLogic.c.o
PEX4.exe: CMakeFiles/PEX4.dir/graphics.c.o
PEX4.exe: CMakeFiles/PEX4.dir/Graph.c.o
PEX4.exe: CMakeFiles/PEX4.dir/build.make
PEX4.exe: CMakeFiles/PEX4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable PEX4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PEX4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PEX4.dir/build: PEX4.exe

.PHONY : CMakeFiles/PEX4.dir/build

CMakeFiles/PEX4.dir/requires: CMakeFiles/PEX4.dir/PEX4_Shannon_switching_game.c.o.requires
CMakeFiles/PEX4.dir/requires: CMakeFiles/PEX4.dir/gameLogic.c.o.requires
CMakeFiles/PEX4.dir/requires: CMakeFiles/PEX4.dir/graphics.c.o.requires
CMakeFiles/PEX4.dir/requires: CMakeFiles/PEX4.dir/Graph.c.o.requires

.PHONY : CMakeFiles/PEX4.dir/requires

CMakeFiles/PEX4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PEX4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PEX4.dir/clean

CMakeFiles/PEX4.dir/depend:
	cd /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/cmake-build-debug /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/cmake-build-debug /cygdrive/c/Users/C20Tricia.Dang/Documents/C3C_2nd_Semester/CS220/cs220_pex4_slav_dang/cmake-build-debug/CMakeFiles/PEX4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PEX4.dir/depend
