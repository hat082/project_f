#include "RobotSystem.h"
#include <iostream>
#include <wiringPi.h>

int main() {

  // initialize robot
  Robot robot;

  if (!robot.initialize()) {
    std::cerr << "Failed to initialize the robot system." << std::endl;
    return -1;
  }

  // main execution loop
  while (true) {
    delay(1000);
    // take image data
    // check if there existsPink
    // if yes,
    if (robot.existPink()) {
      // recognize image
      robot.templateMatch();
      // perform task
      robot.performTask();
    } else {
      // pid
      robot.pidControl();
    }
  }
  return 0;
}
