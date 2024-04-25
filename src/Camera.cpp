#include <Camera.h>
#include <opencv2/opencv.hpp>
#include <softPwm.h>
#include <wiringPi.h>

Camera::Camera() : yRatio_(1), heightRatio_(1), servoPin_(25), cameraPos_(90){
  // Initialization code with resolution parameter
  // Open the default camera
  if (!cap_.open(0)) {
    // Handle the error if the camera cannot be opened
    std::cerr << "ERROR: Could not open camera" << std::endl;
    // You may want to throw an exception or handle the error as per your
    // application's needs
  }
}

// 0.5, 0.3 recommended for line tracking (default)
// 0, 1 recommended for template matching
cv::Mat Camera::captureImage(float yRatio, float heightRatio) {
  cv::Mat frame;
  cap_ >> frame;
  resize(frame, frame, cv::Size(320, 240));

  int x = 0;
  int y = frame.rows * yRatio;
  int width = frame.cols;
  int height = frame.rows * heightRatio;

  // printf("x: %d y: %d width: %d height: %d", x, y, width, height);
  cv::Rect roi(x, y, width, height);

  return frame(roi);
}

void Camera::moveCamera(int angle) {
  // if the cameraPos_ is already at the requested angle, dont do anything
  if (cameraPos_ == angle)
    return;
  else if (cameraPos_ == 0)
    softPwmWrite(servoPin_, 23);
  else if (cameraPos_ == 90)
    softPwmWrite(servoPin_, 15);
  delay(500);
  // turn off the servo motor so it doesn't shake
  softPwmWrite(servoPin_, 0);
}

// Destructor to release the camera
Camera::~Camera() {
  if (cap_.isOpened()) {
    cap_.release();
  }
}
