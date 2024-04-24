#pragma once
#include <opencv2/opencv.hpp>

class Camera {
private:
  int resolution_;

public:
  Camera(int resolution);
  void captureImage();
};
