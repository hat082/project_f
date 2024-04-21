#include "Camera.h"
#include "GPIO.h"
#include "ImageProcessor.h"
#include "PIDController.h"
#include "SerialCommunicator.h"
#include "TaskExecutor.h"
#include "TemplateMatcher.h"
#include "UltrasonicSensor.h"

class Robot {

private:
  Camera camera_;
  GPIO gpio_;
  ImageProcessor imageProcessor_;
  PIDController pidController_;
  SerialCommunicator serialCommunicator_;
  TaskExecutor taskExecutor_;
  TemplateMatcher templateMatcher_;
  UltrasonicSensor ultrasonicSensor_;
  enum Task { LED_BLINK, NONE } task_;

public:
  Robot();  // Constructor declaration
  ~Robot(); // Destructor declaration

  bool initialize();
  bool existPink();
  void moveCamera(int angle);
  void templateMatch();
  void blinkLED();
  void moveForward();
  void performTask();
  void pidControl();
};
