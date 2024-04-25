#pragma once
#include <opencv2/opencv.hpp>

class Camera {
private:
  int resolution_;
  float yRatio_;
  float heightRatio_;
  cv::VideoCapture cap_;
  int servoPin_;
  int cameraPos_;

public:
  Camera();
  ~Camera();
  cv::Mat captureImage(float yRatio = 0.5f, float heightRatio = 0.3f);
  void moveCamera(int angle);
};
