#include <ImageProcessor.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <utility>
#include <vector>

#include <dirent.h>

void ImageProcessor::loadTemplates(std::vector<cv::Mat> &templates) {
  // Load all PNG images under the ./templates/ directory
  // Grayscale images

  std::string directory = "/home/hat082/cpp_projects/pid_improved/templates/";
  DIR *dir;
  struct dirent *ent;
  std::vector<std::string> filenames; // Store the file names here

  if ((dir = opendir(directory.c_str())) != NULL) {
    while ((ent = readdir(dir)) != NULL) {
      std::string filename = ent->d_name;
      if (filename.length() >= 4 &&
          filename.substr(filename.length() - 4) == ".png") {
        filenames.push_back(filename); // Store the file names
      }
    }
    closedir(dir);

    // Sort the file names
    sort(filenames.begin(), filenames.end());

    // Load and process the images in sorted order
    for (const auto &filename : filenames) {
      cv::Mat image = cv::imread(directory + filename, cv::IMREAD_GRAYSCALE);
      if (!image.empty()) {
        resize(image, image, cv::Size(320, 240));
        templates.push_back(image);
        std::cout << "Successfully loaded: " << filename << std::endl;
      }
    }
  } else {
    std::cerr << "Error opening directory" << std::endl;
  }
}

std::pair<cv::Scalar, cv::Scalar>
ImageProcessor::getRangeFromColor(ImageProcessor::Color color) {
  switch (color) {
  case BLUE: {
    // Return a pair of cloned cv::Mat objects to avoid returning references to
    // local variables
    return std::make_pair(lower_blue_, upper_blue_);
  }
  case GREEN: {
    // Return a pair of cloned cv::Mat objects to avoid returning references to
    // local variables
    return std::make_pair(lower_green_, upper_green_);
  }
  case YELLOW: {
    // Return a pair of cloned cv::Mat objects to avoid returning references to
    // local variables
    return std::make_pair(lower_yellow_, upper_yellow_);
  }
  case RED: {
    // Return a pair of cloned cv::Mat objects to avoid returning references to
    // local variables
    return std::make_pair(lower_red_, upper_red_);
  }
  case PINK: {
    // Return a pair of cloned cv::Mat objects to avoid returning references to
    // local variables
    return std::make_pair(lower_pink_, upper_pink_);
  }
  case BLACK:
    return std::make_pair(lower_black_, upper_black_);
  default:
    // If you have a default behavior for other colors, implement it here.
    // Otherwise, you might want to handle this case differently, such as
    // throwing an exception.
    throw std::invalid_argument("Color not supported");
  }
}

void ImageProcessor::createMask(const cv::Mat &inputFrame, Color color,
                                cv::Mat &outputMask) {
  auto range = getRangeFromColor(color);
  cv::Mat hsv_frame;
  cv::cvtColor(inputFrame, hsv_frame, cv::COLOR_BGR2HSV);

  // Filter out the colors that are not in the range of HSV values of interest
  cv::Mat mask;

  cv::inRange(hsv_frame, range.first, range.second, mask);

  // Smooth the image to reduce noise
  int blurSize = 17; // Adjust the size of the blur kernel
  GaussianBlur(mask, mask, cv::Size(blurSize, blurSize), 0);

  // Apply morphological operations to remove small noise and fill in gaps in
  // the mask
  int dilationSize = 12; // Adjust the size of the dilation kernel
  cv::Mat kernel = getStructuringElement(cv::MORPH_RECT,
                                         cv::Size(dilationSize, dilationSize));
  dilate(mask, mask, kernel, cv::Point(-1, -1), 1);
  erode(mask, outputMask, kernel, cv::Point(-1, -1), 1);
}

int ImageProcessor::templateMatching(const cv::Mat &src, const cv::Mat &templ) {
  // Define the matching methods you want to use

  const int methods[] = {cv::TM_CCOEFF_NORMED};

  // methods arr, for testing different methods and comparing them
  // const int methods[] = {cv::TM_SQDIFF_NORMED, cv::TM_CCORR_NORMED,
  //                        cv::TM_CCOEFF_NORMED};
  // const int methods[] = {cv::TM_SQDIFF, cv::TM_SQDIFF_NORMED,
  //                        cv::TM_CCORR,  cv::TM_CCORR_NORMED,
  //                        cv::TM_CCOEFF, cv::TM_CCOEFF_NORMED};

  int methodCount = sizeof(methods) / sizeof(methods[0]);

  cv::Mat result;

  // imshow("template", template_);
  // imshow("frame", frame_);

  std::cout << "___Results___\n";

  // Loop over the methods and apply each one
  double minVal, maxVal;
  for (int i = 0; i < methodCount; i++) {
    // Clear the previous result
    result = cv::Mat::zeros(src.size(), CV_32F);

    // Apply the current matching method
    cv::matchTemplate(src, templ, result, methods[i]);

    // Find the location of the best match
    minMaxLoc(result, &minVal, &maxVal);

    std::cout << "Method " << methods[i] << ": MaxVal: " << maxVal
              << "\tMinVal: " << minVal << std::endl;
  }

  std::cout << "___Reference___\n";
  std::cout << "Method 1: "
            << "Range: (0, 1), 0: Min difference 1: Max difference\n"
            << "Method 3: "
            << "Range: (0, 1), 0: Max difference 1: Min difference\n"
            << "Method 5: "
            << "Range: (-1, 1), -1: Max difference 1: Min difference\n";
  return maxVal;
}

void ImageProcessor::warpPerspective(cv::Mat &mask, cv::Mat &warped) {

  // Find contours in the image
  std::vector<std::vector<cv::Point>> contours;
  cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

  int largest_i = 0;
  double max_area = 0.0;
  for (size_t i = 0; i < contours.size(); i++) {
    double area = contourArea(contours[i]);
    if (area > max_area) {
      max_area = area;
      largest_i = i;
    }
  }

  // Approximate the contour to a square (or another polygonal shape)
  std::vector<cv::Point2f> polygons;
  cv::approxPolyDP(contours[largest_i], polygons,
                   cv::arcLength(contours[largest_i], true) * 0.05, true);

  // Define source points (the order should be top-left, top-right,
  // bottom-right, bottom-left)
  std::vector<cv::Point2f> polygonPoints;
  if (polygons.size() == 4) { // Make sure we have a quadrilateral
    for (int i = 0; i < polygons.size(); i++) {
      polygonPoints.push_back(polygons.at(i));
      std::cout << polygons.at(i) << std::endl;
    }
  } else {
    std::cout << "Did not find a quadrilateral contour." << std::endl;
    return;
  }

  // Define destination points (top-left, top-right, bottom-right, bottom-left)
  // of the desired rectangle (assumed to be the same size as the original
  // image)
  std::vector<cv::Point2f> dstPoints;
  dstPoints.push_back(cv::Point2f(mask.cols, 0));
  dstPoints.push_back(cv::Point2f(0, 0));
  dstPoints.push_back(cv::Point2f(0, mask.rows));
  dstPoints.push_back(cv::Point2f(mask.cols, mask.rows));

  std::cout << cv::Point2f(0, 0) << std::endl;
  std::cout << cv::Point2f(mask.cols, 0) << std::endl;
  std::cout << cv::Point2f(mask.cols, mask.rows) << std::endl;
  std::cout << cv::Point2f(0, mask.rows) << std::endl;

  // Calculate the perspective transform matrix
  cv::Mat perspectiveMatrix =
      cv::getPerspectiveTransform(polygonPoints, dstPoints);

  // Apply the perspective warp to the original image
  cv::warpPerspective(mask, warped, perspectiveMatrix, mask.size());
}

std::tuple<int, int, int> ImageProcessor::countShapes(cv::Mat &frame) {

  auto start = std::chrono::steady_clock::now();
  int timeout = 100; // Timeout duration in seconds

  int threshold_value = 128;    // Threshold value for binary image
  double epsilon_factor = 0.03; // Approximation accuracy for contours
  int min_contour_area = 200;   // Minimum contour area to consider as a shape

  int t = 0; // Count for triangles
  int c = 0; // Count for circles
  int r = 0; // Count for rectangles

  // while seconds past is not over the timeout threshold
  // find and increment the count of each shape
  while (std::chrono::duration_cast<std::chrono::seconds>(
             std::chrono::steady_clock::now() - start)
             .count() < timeout) {

    if (frame.empty()) {
      std::cout << "Input frame invalid\n";
      break;
    }

    cv::Mat mask;
    // create a mask to extract the pink color
    createMask(frame, PINK, mask);

    // Find contours in the binary image
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    findContours(mask, contours, hierarchy, cv::RETR_TREE,
                 cv::CHAIN_APPROX_SIMPLE);

    // Iterate through each contour
    for (size_t i = 0; i < contours.size(); i++) {
      // Calculate the area of the contour
      double area = contourArea(contours[i]);

      // If the contour area is above a certain threshold
      if (area > min_contour_area) {
        std::vector<cv::Point> approx;
        // Obtain a sequence of points of contour
        approxPolyDP(contours[i], approx,
                     arcLength(contours[i], true) * epsilon_factor, true);

        // If there are 3 vertices, it's a triangle
        if (approx.size() == 3) {
          t++; // Increment triangle count
        }
        // If there are 4 vertices, it's a quadrilateral
        else if (approx.size() == 4) {
          r++; // Increment rectangle count
        }
        // If there are more than 6 vertices, consider it a circle
        else if (approx.size() > 6) {
          c++; // Increment circle count
        }
      }
    }

    // remove the the outmost square (which is the border of the image)
    --r;

    // Display the count of each pattern
    std::cout << "Number of triangles: " << t << std::endl;
    std::cout << "Number of rectangles: " << r << std::endl;
    std::cout << "Number of circles: " << c << std::endl;
  }

  return std::make_tuple(t, r, c);
}
