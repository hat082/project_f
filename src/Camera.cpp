#include <Camera.h>
#include <opencv2/opencv.hpp>
#include <softPwm.h>
#include <wiringPi.h>

Camera::Camera() : yRatio_(1), heightRatio_(1), servoPin_(25), cameraPos_(90) {
  // Initialization code with resolution parameter
  // Open the default camera
  // if (!cap_.open(0)) {
  if (!cap_.open("/home/hat082/cpp_projects/pid_improved/video.mp4")) {
    // Handle the error if the camera cannot be opened
    std::cerr << "ERROR: Could not open camera" << std::endl;
    // You may want to throw an exception or handle the error as per your
    // application's needs
  }
}

// Destructor to release the camera
Camera::~Camera() {
  if (cap_.isOpened()) {
    cap_.release();
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

int capture_15_secs() {
  // Define the video capture object
  cv::VideoCapture cap(0);

  // Check if the camera is opened successfully
  if (!cap.isOpened()) {
    std::cerr << "Error: Camera could not be opened." << std::endl;
    return -1;
  }

  // Define the codec and create VideoWriter object
  cv::VideoWriter video;
  std::string videoFile = "output.avi"; // Name of the output video file
  int frameWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
  int frameHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
  double fps = cap.get(cv::CAP_PROP_FPS);

  // These parameters can be adjusted to control the video size and quality
  int fourcc = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
  video.open(videoFile, fourcc, fps, cv::Size(frameWidth, frameHeight), true);

  if (!video.isOpened()) {
    std::cerr << "Error: Could not open the video writer." << std::endl;
    return -1;
  }

  // Record for 10-15 seconds
  int64_t startTick = cv::getTickCount();
  double timeElapsed;
  const int64_t timeLimitTick =
      cv::getTickFrequency() * 10; // 10 seconds in ticks

  cv::Mat frame;
  while (true) {
    // Capture frame-by-frame
    if (!cap.read(frame)) {
      std::cerr << "Error: Could not read a frame from camera." << std::endl;
      break;
    }

    // Write the frame to the video file
    video.write(frame);

    // Calculate time taken
    timeElapsed = (cv::getTickCount() - startTick) / cv::getTickFrequency();
    if (timeElapsed >= 15) { // Stop after 10 seconds
      break;
    }
  }

  // Release the video capture and writer objects
  cap.release();
  video.release();

  std::cout << "Video recorded and saved as " << videoFile << std::endl;

  return 0;
}

