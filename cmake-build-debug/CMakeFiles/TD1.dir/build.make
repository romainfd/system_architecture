# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TD1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TD1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TD1.dir/flags.make

CMakeFiles/TD1.dir/bits.c.o: CMakeFiles/TD1.dir/flags.make
CMakeFiles/TD1.dir/bits.c.o: ../bits.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TD1.dir/bits.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TD1.dir/bits.c.o   -c /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/bits.c

CMakeFiles/TD1.dir/bits.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TD1.dir/bits.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/bits.c > CMakeFiles/TD1.dir/bits.c.i

CMakeFiles/TD1.dir/bits.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TD1.dir/bits.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/bits.c -o CMakeFiles/TD1.dir/bits.c.s

CMakeFiles/TD1.dir/btest.c.o: CMakeFiles/TD1.dir/flags.make
CMakeFiles/TD1.dir/btest.c.o: ../btest.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TD1.dir/btest.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TD1.dir/btest.c.o   -c /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/btest.c

CMakeFiles/TD1.dir/btest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TD1.dir/btest.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/btest.c > CMakeFiles/TD1.dir/btest.c.i

CMakeFiles/TD1.dir/btest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TD1.dir/btest.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/btest.c -o CMakeFiles/TD1.dir/btest.c.s

CMakeFiles/TD1.dir/decl.c.o: CMakeFiles/TD1.dir/flags.make
CMakeFiles/TD1.dir/decl.c.o: ../decl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TD1.dir/decl.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TD1.dir/decl.c.o   -c /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/decl.c

CMakeFiles/TD1.dir/decl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TD1.dir/decl.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/decl.c > CMakeFiles/TD1.dir/decl.c.i

CMakeFiles/TD1.dir/decl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TD1.dir/decl.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/decl.c -o CMakeFiles/TD1.dir/decl.c.s

CMakeFiles/TD1.dir/fshow.c.o: CMakeFiles/TD1.dir/flags.make
CMakeFiles/TD1.dir/fshow.c.o: ../fshow.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/TD1.dir/fshow.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TD1.dir/fshow.c.o   -c /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/fshow.c

CMakeFiles/TD1.dir/fshow.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TD1.dir/fshow.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/fshow.c > CMakeFiles/TD1.dir/fshow.c.i

CMakeFiles/TD1.dir/fshow.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TD1.dir/fshow.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/fshow.c -o CMakeFiles/TD1.dir/fshow.c.s

CMakeFiles/TD1.dir/ishow.c.o: CMakeFiles/TD1.dir/flags.make
CMakeFiles/TD1.dir/ishow.c.o: ../ishow.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/TD1.dir/ishow.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TD1.dir/ishow.c.o   -c /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/ishow.c

CMakeFiles/TD1.dir/ishow.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TD1.dir/ishow.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/ishow.c > CMakeFiles/TD1.dir/ishow.c.i

CMakeFiles/TD1.dir/ishow.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TD1.dir/ishow.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/ishow.c -o CMakeFiles/TD1.dir/ishow.c.s

CMakeFiles/TD1.dir/tests.c.o: CMakeFiles/TD1.dir/flags.make
CMakeFiles/TD1.dir/tests.c.o: ../tests.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/TD1.dir/tests.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TD1.dir/tests.c.o   -c /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/tests.c

CMakeFiles/TD1.dir/tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TD1.dir/tests.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/tests.c > CMakeFiles/TD1.dir/tests.c.i

CMakeFiles/TD1.dir/tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TD1.dir/tests.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/tests.c -o CMakeFiles/TD1.dir/tests.c.s

# Object files for target TD1
TD1_OBJECTS = \
"CMakeFiles/TD1.dir/bits.c.o" \
"CMakeFiles/TD1.dir/btest.c.o" \
"CMakeFiles/TD1.dir/decl.c.o" \
"CMakeFiles/TD1.dir/fshow.c.o" \
"CMakeFiles/TD1.dir/ishow.c.o" \
"CMakeFiles/TD1.dir/tests.c.o"

# External object files for target TD1
TD1_EXTERNAL_OBJECTS =

TD1: CMakeFiles/TD1.dir/bits.c.o
TD1: CMakeFiles/TD1.dir/btest.c.o
TD1: CMakeFiles/TD1.dir/decl.c.o
TD1: CMakeFiles/TD1.dir/fshow.c.o
TD1: CMakeFiles/TD1.dir/ishow.c.o
TD1: CMakeFiles/TD1.dir/tests.c.o
TD1: CMakeFiles/TD1.dir/build.make
TD1: CMakeFiles/TD1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable TD1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TD1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TD1.dir/build: TD1

.PHONY : CMakeFiles/TD1.dir/build

CMakeFiles/TD1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TD1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TD1.dir/clean

CMakeFiles/TD1.dir/depend:
	cd /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1 /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1 /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/cmake-build-debug /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/cmake-build-debug /Users/romainfouilland/drive/TravailTemp/Polytechnique/3A/Cours/INF559/TD1/cmake-build-debug/CMakeFiles/TD1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TD1.dir/depend

