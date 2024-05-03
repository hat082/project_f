# Building a CMake Project

## Prerequisites
- Ensure CMake is installed on your system.

## Steps to Build the Project

### 1. Create a Build Directory
```bash
mkdir build
cd build
```

### 2. Generate Build System
Run CMake to generate the build system from the `CMakeLists.txt` file.
```bash
cmake ..
```

### 3. Compile the Project
Use the generated build system to compile the project. If Makefiles were created:
```bash
make
```

For other build systems, use the corresponding build command (e.g., `ninja` for Ninja).


### 4. Run the Program
After compilation, locate and run the generated executable in the build directory.
```bash
./RobotControl
```

## Notes
- Make sure all required dependencies (e.g., OpenCV, wiringPi) are installed before running CMake.
- If you encounter issues, CMake will typically provide error messages to help diagnose the problem.
