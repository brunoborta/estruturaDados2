# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/arvore_binaria.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/arvore_binaria.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arvore_binaria.dir/flags.make

CMakeFiles/arvore_binaria.dir/main.c.o: CMakeFiles/arvore_binaria.dir/flags.make
CMakeFiles/arvore_binaria.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/arvore_binaria.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arvore_binaria.dir/main.c.o   -c /Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria/main.c

CMakeFiles/arvore_binaria.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arvore_binaria.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria/main.c > CMakeFiles/arvore_binaria.dir/main.c.i

CMakeFiles/arvore_binaria.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arvore_binaria.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria/main.c -o CMakeFiles/arvore_binaria.dir/main.c.s

CMakeFiles/arvore_binaria.dir/main.c.o.requires:

.PHONY : CMakeFiles/arvore_binaria.dir/main.c.o.requires

CMakeFiles/arvore_binaria.dir/main.c.o.provides: CMakeFiles/arvore_binaria.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/arvore_binaria.dir/build.make CMakeFiles/arvore_binaria.dir/main.c.o.provides.build
.PHONY : CMakeFiles/arvore_binaria.dir/main.c.o.provides

CMakeFiles/arvore_binaria.dir/main.c.o.provides.build: CMakeFiles/arvore_binaria.dir/main.c.o


# Object files for target arvore_binaria
arvore_binaria_OBJECTS = \
"CMakeFiles/arvore_binaria.dir/main.c.o"

# External object files for target arvore_binaria
arvore_binaria_EXTERNAL_OBJECTS =

arvore_binaria: CMakeFiles/arvore_binaria.dir/main.c.o
arvore_binaria: CMakeFiles/arvore_binaria.dir/build.make
arvore_binaria: CMakeFiles/arvore_binaria.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable arvore_binaria"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arvore_binaria.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arvore_binaria.dir/build: arvore_binaria

.PHONY : CMakeFiles/arvore_binaria.dir/build

CMakeFiles/arvore_binaria.dir/requires: CMakeFiles/arvore_binaria.dir/main.c.o.requires

.PHONY : CMakeFiles/arvore_binaria.dir/requires

CMakeFiles/arvore_binaria.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arvore_binaria.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arvore_binaria.dir/clean

CMakeFiles/arvore_binaria.dir/depend:
	cd /Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria /Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria /Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria/cmake-build-debug /Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria/cmake-build-debug /Users/brunobortagaray/CLionProjects/estruturaDados2/arvore_binaria/cmake-build-debug/CMakeFiles/arvore_binaria.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arvore_binaria.dir/depend

