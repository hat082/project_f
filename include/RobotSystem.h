#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

#include "Camera.h"
#include "GPIO.h"
#include "ImageProcessor.h"
#include "PIDController.h"
#include "SerialCommunicator.h"
#include "TaskExecutor.h"
#include "TemplateMatcher.h"
#include "UltrasonicSensor.h"
#include <HMI.h>

class Robot {
public:
  Robot();
  ~Robot();

private:
  Camera camera_;
  // GPIO gpio_;
  ImageProcessor imageProcessor_;
  // PIDController pidController_;
  // SerialCommunicator serialCommunicator_;
  TaskExecutor taskExecutor_;
  // TemplateMatcher templateMatcher_;
  // UltrasonicSensor ultrasonicSensor_;
  //
  HMI hmi_;

private:
  cv::Mat frame_;
  std::vector<cv::Mat> templs_;
  enum TaskExecutor::Task task_;

public:
  // takes an image with the camera module and store the frame in frame_ member
  void takeImage();
  bool existPink();
  void templateMatch();
  void performTask();
  void pidControl(ImageProcessor::Color color);
};
