#include "Camera.h"
#include <RobotSystem.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <wiringPi.h>

using Task = TaskExecutor::Task;
using Color = ImageProcessor::Color;

// Constructor implementation
Robot::Robot() : camera_(), imageProcessor_(), hmi_() {
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
  double max = -1;
  camera_.moveCamera(90);
  bool existMatch = false;

  do {

    cv::Mat mask;
    cv::Mat warp;
    takeImage();
    imageProcessor_.createMask(frame_, Color::PINK, mask);

    imageProcessor_.warpPerspective(mask, warp);

    if (warp.dims == 0) {
      existMatch = false;
      break;
    }
    existMatch = true;

    // loop through all templates
    for (int taskNum = 0; taskNum < Task::NONE; taskNum++) {
      // obtain the maximum match value from template matching
      double match =
          imageProcessor_.templateMatching(warp, templs_.at(taskNum));
      if (match > max) {
        max = match;
        taskExecutor_.setTask(task_, taskNum);
      }
    }

  } while (max < 0.6);

  if (existMatch == false) {
    std::cout << "No match found" << task_ << std::endl;
  }

  std::cout << "Matched template: " << task_ << std::endl;
}

void Robot::performTask() {
  std::cout << "Performing task: " << task_ << std::endl;
  switch (task_) {
    // led blink (alarm flash)
  case Task::LED_BLINK: {
    taskExecutor_.blinkLED();
    hmi_.lcdPrintTask("Alarm Flash");
  } break;

    // count shapes
  case Task::SHAPES1:
  case Task::SHAPES2:
  case Task::SHAPES3: {
    auto [t_count, s_count, c_count] = imageProcessor_.countShapes(frame_);
    hmi_.lcdPrintTaskShape(t_count, s_count, c_count);
  } break;

    // play music
  case Task::MUSIC: {
    taskExecutor_.playMusic();
    hmi_.lcdPrintTask("Music");
  } break;

  // approach and stop
  case Task::APPROACH_AND_STOP: {
    float distance = 50;
    while (distance > 5) {
      taskExecutor_.calcDistance();
      hmi_.lcdPrintTaskApproach(distance);
    }
  } break;

  // kick ball
  case Task::KICK_FOOTBALL: {
    taskExecutor_.kickBall();
    hmi_.lcdPrintTask("Kick Football");
  } break;

  // traffic light
  case Task::TRAFFIC_LIGHTS: {
    taskExecutor_.trafficLight();
    hmi_.lcdPrintTask("Traffic Light");
  } break;

  default:
    break;
  }
  task_ = Task::NONE;
}

// TODO: finish logic for pid
void Robot::pidControl(Color color) {
  cv::Mat mask;
  // create a mask that extracts black color
  imageProcessor_.createMask(frame_, color, mask);
}
