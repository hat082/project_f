#include "Camera.h"
#include <RobotSystem.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

// bool Robot::init() {
// Initialize all the components of the robot system
// Return true if initialization is successful, false otherwise
// camera_.initialize();
// gpio_.initialize();
// imageProcessor_.initialize();
// pidController_.initialize();
// serialCommunicator_.initialize();
// taskExecutor_.initialize();
// templateMatcher_.initialize();
// ultrasonicSensor_.initialize();

//   return true;
// }

using Task = TaskExecutor::Task;
using Color = ImageProcessor::Color;

// Constructor implementation
Robot::Robot() : camera_(), imageProcessor_() {
  // Additional initialization for Robot if needed
  // Initialize all the class members here

  task_ = Task::NONE;
  imageProcessor_.loadTemplates(templs_);
  std::cout
      << "Initialization complete. Press [Enter] to continue, [q] to quit."
      << std::endl;

}

// Destructor implementation
Robot::~Robot() {
  // Perform any necessary cleanup here if needed
  // For example, if there are resources that need to be released
  std::cout << "Destruction complete. Terminating Program." << std::endl;
}

bool Robot::existPink() {
  // Implement the logic to check if pink is detected by the camera
  // Return true if pink is detected, false otherwise
  cv::Mat mask;
  imageProcessor_.createMask(frame_, Color::PINK, mask);

  // std::cout << countNonZero(frame);
  if (countNonZero(mask) >= 10000) {
    std::cout << "Pink Detected\n";
    return true;
  } else {
    // printf(" pink pixels: %d ", countNonZero(frame));
    return false;
  }
}

void Robot::takeImage() { frame_ = camera_.captureImage(); };

void Robot::templateMatch() {
  cv::Mat mask;
  cv::Mat warp;
  double max = -1;
  camera_.moveCamera(90);

  do {
    takeImage();
    imageProcessor_.createMask(frame_, Color::PINK, mask);

    imageProcessor_.warpPerspective(mask, warp);

    // loop through all templates
    for (int taskNum = 0; taskNum < 5; taskNum++) {
      // obtain the maximum match value from template matching
      double match =
          imageProcessor_.templateMatching(warp, templs_.at(taskNum));
      if (match > max) {
        max = match;
      }
    }
  } while (max < 0.6);

  std::cout << "Matched template: " << task_ << std::endl;
}

void Robot::performTask() {
  std::cout << "Performing task: " << task_ << std::endl;
  switch (task_) {
  case Task::LED_BLINK:
    taskExecutor_.blinkLED();
    break;
    // case :
  default:
    break;
  }
  task_ = Task::NONE;
}

void Robot::pidControl(Color color) {
  cv::Mat mask;
  // create a mask that extracts black color
  imageProcessor_.createMask(frame_, color, mask);
}
