# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/cs104/cs104_test/hw3/hw3_check

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cs104/cs104_test/hw3/hw3_check

# Include any dependencies generated for this target.
include stack_tests/CMakeFiles/hw3_stack.dir/depend.make

# Include the progress variables for this target.
include stack_tests/CMakeFiles/hw3_stack.dir/progress.make

# Include the compile flags for this target's objects.
include stack_tests/CMakeFiles/hw3_stack.dir/flags.make

stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o: stack_tests/CMakeFiles/hw3_stack.dir/flags.make
stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o: /home/cs104/cs104_test/hw3/ulliststr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs104/cs104_test/hw3/hw3_check/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o"
	cd /home/cs104/cs104_test/hw3/hw3_check/stack_tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o -c /home/cs104/cs104_test/hw3/ulliststr.cpp

stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.i"
	cd /home/cs104/cs104_test/hw3/hw3_check/stack_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs104/cs104_test/hw3/ulliststr.cpp > CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.i

stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.s"
	cd /home/cs104/cs104_test/hw3/hw3_check/stack_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs104/cs104_test/hw3/ulliststr.cpp -o CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.s

stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o.requires:

.PHONY : stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o.requires

stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o.provides: stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o.requires
	$(MAKE) -f stack_tests/CMakeFiles/hw3_stack.dir/build.make stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o.provides.build
.PHONY : stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o.provides

stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o.provides.build: stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o


stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o: stack_tests/CMakeFiles/hw3_stack.dir/flags.make
stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o: /home/cs104/cs104_test/hw3/stackstring.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs104/cs104_test/hw3/hw3_check/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o"
	cd /home/cs104/cs104_test/hw3/hw3_check/stack_tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o -c /home/cs104/cs104_test/hw3/stackstring.cpp

stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.i"
	cd /home/cs104/cs104_test/hw3/hw3_check/stack_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs104/cs104_test/hw3/stackstring.cpp > CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.i

stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.s"
	cd /home/cs104/cs104_test/hw3/hw3_check/stack_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs104/cs104_test/hw3/stackstring.cpp -o CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.s

stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o.requires:

.PHONY : stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o.requires

stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o.provides: stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o.requires
	$(MAKE) -f stack_tests/CMakeFiles/hw3_stack.dir/build.make stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o.provides.build
.PHONY : stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o.provides

stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o.provides.build: stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o


# Object files for target hw3_stack
hw3_stack_OBJECTS = \
"CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o" \
"CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o"

# External object files for target hw3_stack
hw3_stack_EXTERNAL_OBJECTS =

stack_tests/libhw3_stack.a: stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o
stack_tests/libhw3_stack.a: stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o
stack_tests/libhw3_stack.a: stack_tests/CMakeFiles/hw3_stack.dir/build.make
stack_tests/libhw3_stack.a: stack_tests/CMakeFiles/hw3_stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cs104/cs104_test/hw3/hw3_check/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libhw3_stack.a"
	cd /home/cs104/cs104_test/hw3/hw3_check/stack_tests && $(CMAKE_COMMAND) -P CMakeFiles/hw3_stack.dir/cmake_clean_target.cmake
	cd /home/cs104/cs104_test/hw3/hw3_check/stack_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw3_stack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
stack_tests/CMakeFiles/hw3_stack.dir/build: stack_tests/libhw3_stack.a

.PHONY : stack_tests/CMakeFiles/hw3_stack.dir/build

stack_tests/CMakeFiles/hw3_stack.dir/requires: stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/ulliststr.cpp.o.requires
stack_tests/CMakeFiles/hw3_stack.dir/requires: stack_tests/CMakeFiles/hw3_stack.dir/home/cs104/cs104_test/hw3/stackstring.cpp.o.requires

.PHONY : stack_tests/CMakeFiles/hw3_stack.dir/requires

stack_tests/CMakeFiles/hw3_stack.dir/clean:
	cd /home/cs104/cs104_test/hw3/hw3_check/stack_tests && $(CMAKE_COMMAND) -P CMakeFiles/hw3_stack.dir/cmake_clean.cmake
.PHONY : stack_tests/CMakeFiles/hw3_stack.dir/clean

stack_tests/CMakeFiles/hw3_stack.dir/depend:
	cd /home/cs104/cs104_test/hw3/hw3_check && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs104/cs104_test/hw3/hw3_check /home/cs104/cs104_test/hw3/hw3_check/stack_tests /home/cs104/cs104_test/hw3/hw3_check /home/cs104/cs104_test/hw3/hw3_check/stack_tests /home/cs104/cs104_test/hw3/hw3_check/stack_tests/CMakeFiles/hw3_stack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : stack_tests/CMakeFiles/hw3_stack.dir/depend
