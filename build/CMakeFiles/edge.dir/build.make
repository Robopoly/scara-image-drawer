# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adrien/scara-image-drawer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adrien/scara-image-drawer/build

# Include any dependencies generated for this target.
include CMakeFiles/edge.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/edge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/edge.dir/flags.make

CMakeFiles/edge.dir/edge.o: CMakeFiles/edge.dir/flags.make
CMakeFiles/edge.dir/edge.o: ../edge.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adrien/scara-image-drawer/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/edge.dir/edge.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/edge.dir/edge.o -c /home/adrien/scara-image-drawer/edge.cpp

CMakeFiles/edge.dir/edge.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/edge.dir/edge.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/adrien/scara-image-drawer/edge.cpp > CMakeFiles/edge.dir/edge.i

CMakeFiles/edge.dir/edge.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/edge.dir/edge.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/adrien/scara-image-drawer/edge.cpp -o CMakeFiles/edge.dir/edge.s

CMakeFiles/edge.dir/edge.o.requires:
.PHONY : CMakeFiles/edge.dir/edge.o.requires

CMakeFiles/edge.dir/edge.o.provides: CMakeFiles/edge.dir/edge.o.requires
	$(MAKE) -f CMakeFiles/edge.dir/build.make CMakeFiles/edge.dir/edge.o.provides.build
.PHONY : CMakeFiles/edge.dir/edge.o.provides

CMakeFiles/edge.dir/edge.o.provides.build: CMakeFiles/edge.dir/edge.o
.PHONY : CMakeFiles/edge.dir/edge.o.provides.build

# Object files for target edge
edge_OBJECTS = \
"CMakeFiles/edge.dir/edge.o"

# External object files for target edge
edge_EXTERNAL_OBJECTS =

edge: CMakeFiles/edge.dir/edge.o
edge: /usr/lib/libopencv_gpu.so.2.3.1
edge: /usr/lib/libopencv_contrib.so.2.3.1
edge: /usr/lib/libopencv_legacy.so.2.3.1
edge: /usr/lib/libopencv_objdetect.so.2.3.1
edge: /usr/lib/libopencv_calib3d.so.2.3.1
edge: /usr/lib/libopencv_features2d.so.2.3.1
edge: /usr/lib/libopencv_video.so.2.3.1
edge: /usr/lib/libopencv_highgui.so.2.3.1
edge: /usr/lib/libopencv_ml.so.2.3.1
edge: /usr/lib/libopencv_imgproc.so.2.3.1
edge: /usr/lib/libopencv_flann.so.2.3.1
edge: /usr/lib/libopencv_core.so.2.3.1
edge: CMakeFiles/edge.dir/build.make
edge: CMakeFiles/edge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable edge"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/edge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/edge.dir/build: edge
.PHONY : CMakeFiles/edge.dir/build

CMakeFiles/edge.dir/requires: CMakeFiles/edge.dir/edge.o.requires
.PHONY : CMakeFiles/edge.dir/requires

CMakeFiles/edge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/edge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/edge.dir/clean

CMakeFiles/edge.dir/depend:
	cd /home/adrien/scara-image-drawer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrien/scara-image-drawer /home/adrien/scara-image-drawer /home/adrien/scara-image-drawer/build /home/adrien/scara-image-drawer/build /home/adrien/scara-image-drawer/build/CMakeFiles/edge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/edge.dir/depend
