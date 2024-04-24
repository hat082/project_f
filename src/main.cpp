#include "RobotSystem.h"
#include <cstdio>
#include <wiringPi.h>

int main() {
  // initialize robot
  Robot robot(1920);

  while (getchar() != '\n')
    ;

  // main execution loop
  while (true) {
    delay(1000);
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
      robot.pidControl();
    }
  }
  return 0;
}
