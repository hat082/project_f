#include <opencv2/opencv.hpp>

#include "Camera.h"
#include "GPIO.h"
#include "ImageProcessor.h"
#include "PIDController.h"
#include "SerialCommunicator.h"
#include "TaskExecutor.h"
#include "TemplateMatcher.h"
#include "UltrasonicSensor.h"

class Robot {
public:
  Robot(int cameraResolution);
  ~Robot();
  enum Task { LED_BLINK, NONE };

private:
  Camera camera_;
  // GPIO gpio_;
  // ImageProcessor imageProcessor_;
  // PIDController pidController_;
  // SerialCommunicator serialCommunicator_;
  // TaskExecutor taskExecutor_;
  // TemplateMatcher templateMatcher_;
  // UltrasonicSensor ultrasonicSensor_;

  enum Task task_;
  // cv::Mat frame_;

public:
  void takeImage();
  bool existPink();
  void moveCamera(int angle);
  void templateMatch();
  void performTask();
  void pidControl();
  void blinkLED();
};
