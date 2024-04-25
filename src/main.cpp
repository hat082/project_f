#include "RobotSystem.h"
#include <cstdio>
#include <wiringPi.h>

using Color = ImageProcessor::Color;

int main() {
  // initialize robot
  Robot robot;

 char c;
  while (c != '\n') {
    if (c == 'q')
      return 0;
    c = getchar();
  }

  // main execution loop
  while (true) {
    // take image data
    robot.takeImage();
    // check if there existsPink
    // if yes,
    if (robot.existPink()) {
      // recognize image
      robot.templateMatch();
      // perform task
      robot.performTask();
    } else {
      // pid
      robot.pidControl(Color::BLACK);
    }
  }
  return 0;
}
