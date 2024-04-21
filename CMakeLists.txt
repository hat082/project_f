cmake_minimum_required(VERSION 3.0)
project(RobotControl)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenCV REQUIRED)

# Collect all source and header files
file(GLOB SOURCES "src/*.cpp")
file(GLOB INCLUDES "include/*.h")

# Add include directories
include_directories(include ${OpenCV_INCLUDE_DIRS})  

# Add definitions
add_definitions(${OpenCV_DEFINITIONS})

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})

# Link the required libraries
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} wiringPi wiringPiDev)  
