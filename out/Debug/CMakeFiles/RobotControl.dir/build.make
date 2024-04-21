# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hat082/cpp_projects/pid_improved

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hat082/cpp_projects/pid_improved/out/Debug

# Include any dependencies generated for this target.
include CMakeFiles/RobotControl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RobotControl.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RobotControl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RobotControl.dir/flags.make

CMakeFiles/RobotControl.dir/src/Camera.cpp.o: CMakeFiles/RobotControl.dir/flags.make
CMakeFiles/RobotControl.dir/src/Camera.cpp.o: ../../src/Camera.cpp
CMakeFiles/RobotControl.dir/src/Camera.cpp.o: CMakeFiles/RobotControl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hat082/cpp_projects/pid_improved/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RobotControl.dir/src/Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RobotControl.dir/src/Camera.cpp.o -MF CMakeFiles/RobotControl.dir/src/Camera.cpp.o.d -o CMakeFiles/RobotControl.dir/src/Camera.cpp.o -c /home/hat082/cpp_projects/pid_improved/src/Camera.cpp

CMakeFiles/RobotControl.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RobotControl.dir/src/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hat082/cpp_projects/pid_improved/src/Camera.cpp > CMakeFiles/RobotControl.dir/src/Camera.cpp.i

CMakeFiles/RobotControl.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RobotControl.dir/src/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hat082/cpp_projects/pid_improved/src/Camera.cpp -o CMakeFiles/RobotControl.dir/src/Camera.cpp.s

CMakeFiles/RobotControl.dir/src/GPIO.cpp.o: CMakeFiles/RobotControl.dir/flags.make
CMakeFiles/RobotControl.dir/src/GPIO.cpp.o: ../../src/GPIO.cpp
CMakeFiles/RobotControl.dir/src/GPIO.cpp.o: CMakeFiles/RobotControl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hat082/cpp_projects/pid_improved/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RobotControl.dir/src/GPIO.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RobotControl.dir/src/GPIO.cpp.o -MF CMakeFiles/RobotControl.dir/src/GPIO.cpp.o.d -o CMakeFiles/RobotControl.dir/src/GPIO.cpp.o -c /home/hat082/cpp_projects/pid_improved/src/GPIO.cpp

CMakeFiles/RobotControl.dir/src/GPIO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RobotControl.dir/src/GPIO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hat082/cpp_projects/pid_improved/src/GPIO.cpp > CMakeFiles/RobotControl.dir/src/GPIO.cpp.i

CMakeFiles/RobotControl.dir/src/GPIO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RobotControl.dir/src/GPIO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hat082/cpp_projects/pid_improved/src/GPIO.cpp -o CMakeFiles/RobotControl.dir/src/GPIO.cpp.s

CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.o: CMakeFiles/RobotControl.dir/flags.make
CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.o: ../../src/ImageProcessor.cpp
CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.o: CMakeFiles/RobotControl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hat082/cpp_projects/pid_improved/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.o -MF CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.o.d -o CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.o -c /home/hat082/cpp_projects/pid_improved/src/ImageProcessor.cpp

CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hat082/cpp_projects/pid_improved/src/ImageProcessor.cpp > CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.i

CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hat082/cpp_projects/pid_improved/src/ImageProcessor.cpp -o CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.s

CMakeFiles/RobotControl.dir/src/PIDController.cpp.o: CMakeFiles/RobotControl.dir/flags.make
CMakeFiles/RobotControl.dir/src/PIDController.cpp.o: ../../src/PIDController.cpp
CMakeFiles/RobotControl.dir/src/PIDController.cpp.o: CMakeFiles/RobotControl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hat082/cpp_projects/pid_improved/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RobotControl.dir/src/PIDController.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RobotControl.dir/src/PIDController.cpp.o -MF CMakeFiles/RobotControl.dir/src/PIDController.cpp.o.d -o CMakeFiles/RobotControl.dir/src/PIDController.cpp.o -c /home/hat082/cpp_projects/pid_improved/src/PIDController.cpp

CMakeFiles/RobotControl.dir/src/PIDController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RobotControl.dir/src/PIDController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hat082/cpp_projects/pid_improved/src/PIDController.cpp > CMakeFiles/RobotControl.dir/src/PIDController.cpp.i

CMakeFiles/RobotControl.dir/src/PIDController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RobotControl.dir/src/PIDController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hat082/cpp_projects/pid_improved/src/PIDController.cpp -o CMakeFiles/RobotControl.dir/src/PIDController.cpp.s

CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.o: CMakeFiles/RobotControl.dir/flags.make
CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.o: ../../src/RobotSystem.cpp
CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.o: CMakeFiles/RobotControl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hat082/cpp_projects/pid_improved/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.o -MF CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.o.d -o CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.o -c /home/hat082/cpp_projects/pid_improved/src/RobotSystem.cpp

CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hat082/cpp_projects/pid_improved/src/RobotSystem.cpp > CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.i

CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hat082/cpp_projects/pid_improved/src/RobotSystem.cpp -o CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.s

CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.o: CMakeFiles/RobotControl.dir/flags.make
CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.o: ../../src/SerialCommunicator.cpp
CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.o: CMakeFiles/RobotControl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hat082/cpp_projects/pid_improved/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.o -MF CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.o.d -o CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.o -c /home/hat082/cpp_projects/pid_improved/src/SerialCommunicator.cpp

CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hat082/cpp_projects/pid_improved/src/SerialCommunicator.cpp > CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.i

CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hat082/cpp_projects/pid_improved/src/SerialCommunicator.cpp -o CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.s

CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.o: CMakeFiles/RobotControl.dir/flags.make
CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.o: ../../src/TaskExecutor.cpp
CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.o: CMakeFiles/RobotControl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hat082/cpp_projects/pid_improved/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.o -MF CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.o.d -o CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.o -c /home/hat082/cpp_projects/pid_improved/src/TaskExecutor.cpp

CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hat082/cpp_projects/pid_improved/src/TaskExecutor.cpp > CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.i

CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hat082/cpp_projects/pid_improved/src/TaskExecutor.cpp -o CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.s

CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.o: CMakeFiles/RobotControl.dir/flags.make
CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.o: ../../src/TemplateMatcher.cpp
CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.o: CMakeFiles/RobotControl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hat082/cpp_projects/pid_improved/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.o -MF CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.o.d -o CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.o -c /home/hat082/cpp_projects/pid_improved/src/TemplateMatcher.cpp

CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hat082/cpp_projects/pid_improved/src/TemplateMatcher.cpp > CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.i

CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hat082/cpp_projects/pid_improved/src/TemplateMatcher.cpp -o CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.s

CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.o: CMakeFiles/RobotControl.dir/flags.make
CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.o: ../../src/UltrasonicSensor.cpp
CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.o: CMakeFiles/RobotControl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hat082/cpp_projects/pid_improved/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.o -MF CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.o.d -o CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.o -c /home/hat082/cpp_projects/pid_improved/src/UltrasonicSensor.cpp

CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hat082/cpp_projects/pid_improved/src/UltrasonicSensor.cpp > CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.i

CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hat082/cpp_projects/pid_improved/src/UltrasonicSensor.cpp -o CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.s

CMakeFiles/RobotControl.dir/src/main.cpp.o: CMakeFiles/RobotControl.dir/flags.make
CMakeFiles/RobotControl.dir/src/main.cpp.o: ../../src/main.cpp
CMakeFiles/RobotControl.dir/src/main.cpp.o: CMakeFiles/RobotControl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hat082/cpp_projects/pid_improved/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/RobotControl.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RobotControl.dir/src/main.cpp.o -MF CMakeFiles/RobotControl.dir/src/main.cpp.o.d -o CMakeFiles/RobotControl.dir/src/main.cpp.o -c /home/hat082/cpp_projects/pid_improved/src/main.cpp

CMakeFiles/RobotControl.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RobotControl.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hat082/cpp_projects/pid_improved/src/main.cpp > CMakeFiles/RobotControl.dir/src/main.cpp.i

CMakeFiles/RobotControl.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RobotControl.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hat082/cpp_projects/pid_improved/src/main.cpp -o CMakeFiles/RobotControl.dir/src/main.cpp.s

# Object files for target RobotControl
RobotControl_OBJECTS = \
"CMakeFiles/RobotControl.dir/src/Camera.cpp.o" \
"CMakeFiles/RobotControl.dir/src/GPIO.cpp.o" \
"CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.o" \
"CMakeFiles/RobotControl.dir/src/PIDController.cpp.o" \
"CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.o" \
"CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.o" \
"CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.o" \
"CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.o" \
"CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.o" \
"CMakeFiles/RobotControl.dir/src/main.cpp.o"

# External object files for target RobotControl
RobotControl_EXTERNAL_OBJECTS =

RobotControl: CMakeFiles/RobotControl.dir/src/Camera.cpp.o
RobotControl: CMakeFiles/RobotControl.dir/src/GPIO.cpp.o
RobotControl: CMakeFiles/RobotControl.dir/src/ImageProcessor.cpp.o
RobotControl: CMakeFiles/RobotControl.dir/src/PIDController.cpp.o
RobotControl: CMakeFiles/RobotControl.dir/src/RobotSystem.cpp.o
RobotControl: CMakeFiles/RobotControl.dir/src/SerialCommunicator.cpp.o
RobotControl: CMakeFiles/RobotControl.dir/src/TaskExecutor.cpp.o
RobotControl: CMakeFiles/RobotControl.dir/src/TemplateMatcher.cpp.o
RobotControl: CMakeFiles/RobotControl.dir/src/UltrasonicSensor.cpp.o
RobotControl: CMakeFiles/RobotControl.dir/src/main.cpp.o
RobotControl: CMakeFiles/RobotControl.dir/build.make
RobotControl: /usr/local/lib/libopencv_gapi.so.4.9.0
RobotControl: /usr/local/lib/libopencv_highgui.so.4.9.0
RobotControl: /usr/local/lib/libopencv_ml.so.4.9.0
RobotControl: /usr/local/lib/libopencv_objdetect.so.4.9.0
RobotControl: /usr/local/lib/libopencv_photo.so.4.9.0
RobotControl: /usr/local/lib/libopencv_stitching.so.4.9.0
RobotControl: /usr/local/lib/libopencv_video.so.4.9.0
RobotControl: /usr/local/lib/libopencv_videoio.so.4.9.0
RobotControl: /usr/local/lib/libopencv_imgcodecs.so.4.9.0
RobotControl: /usr/local/lib/libopencv_dnn.so.4.9.0
RobotControl: /usr/local/lib/libopencv_calib3d.so.4.9.0
RobotControl: /usr/local/lib/libopencv_features2d.so.4.9.0
RobotControl: /usr/local/lib/libopencv_flann.so.4.9.0
RobotControl: /usr/local/lib/libopencv_imgproc.so.4.9.0
RobotControl: /usr/local/lib/libopencv_core.so.4.9.0
RobotControl: CMakeFiles/RobotControl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hat082/cpp_projects/pid_improved/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable RobotControl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RobotControl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RobotControl.dir/build: RobotControl
.PHONY : CMakeFiles/RobotControl.dir/build

CMakeFiles/RobotControl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RobotControl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RobotControl.dir/clean

CMakeFiles/RobotControl.dir/depend:
	cd /home/hat082/cpp_projects/pid_improved/out/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hat082/cpp_projects/pid_improved /home/hat082/cpp_projects/pid_improved /home/hat082/cpp_projects/pid_improved/out/Debug /home/hat082/cpp_projects/pid_improved/out/Debug /home/hat082/cpp_projects/pid_improved/out/Debug/CMakeFiles/RobotControl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RobotControl.dir/depend

