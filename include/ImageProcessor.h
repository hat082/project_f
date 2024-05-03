#include <opencv2/opencv.hpp>

class ImageProcessor {
public:
  enum Color { BLUE, GREEN, YELLOW, RED, PINK, BLACK };

private:
  const cv::Scalar lower_blue_ = cv::Scalar(71, 0, 0);
  const cv::Scalar upper_blue_ = cv::Scalar(119, 165, 255);

  const cv::Scalar lower_green_ = cv::Scalar(40, 50, 50);
  const cv::Scalar upper_green_ = cv::Scalar(80, 255, 255);

  const cv::Scalar lower_yellow_ = cv::Scalar(20, 100, 100);
  const cv::Scalar upper_yellow_ = cv::Scalar(40, 255, 255);

  const cv::Scalar lower_red_ = cv::Scalar(0, 100, 100);
  const cv::Scalar upper_red_ = cv::Scalar(10, 255, 255);

  const cv::Scalar lower_pink_ = cv::Scalar(170, 0, 100);
  const cv::Scalar upper_pink_ = cv::Scalar(179, 255, 235);

  const cv::Scalar lower_black_ = cv::Scalar(10, 0, 0);
  const cv::Scalar upper_black_ = cv::Scalar(89, 135, 85);

public:
  // Function to perform preprocessing steps
  // This function takes a frame of the video as input, performs preprocessing
  // steps, and returns a binary mask of the region of interest (black -> white,
  // other colors -> black)
  void createMask(const cv::Mat &inputFrame, Color color, cv::Mat &outputMask);

  /* map color enum to their corresponding scalar ranges so that they can be
   * accessed more easily usage: auto range = getRangeFromColor(Color color);
   *  range.first->lower bound
   *  range.second->upper bound
   */
  std::pair<cv::Scalar, cv::Scalar>
  getRangeFromColor(ImageProcessor::Color color);

  /**
   * @function templateMatching
   * @brief Performs template matching operations to find the location of the
   * best match of a template in the source image.
   *
   * @param src The source image in which to search for the template.
   * @param templ The template image to match against the source image.
   * @return The maximum match value indicating the best match between the
   * template and a region in the source image.
   *
   * This function compares the template image to overlapped regions of the
   * source image and returns the best match score based on the selected
   * matching method. It supports multiple matching methods and can output the
   * results for each method to help in choosing the most suitable one for a
   * given application.
   *
   * The matching methods are defined in an array and can be iterated over to
   * apply and compare different methods. The matching results are stored in a
   * matrix 'result', which is initialized to zeros before each method is
   * applied. After applying each method, the location of the best match is
   * found using the minMaxLoc function. The results are then printed to the
   * standard output, showing the maximum and minimum values for each method.
   *
   * The function provides a reference for the interpretation of the results,
   * explaining the meaning of the match values for different methods, which can
   * be helpful for understanding the output and choosing the appropriate
   * method.
   */
  int templateMatching(const cv::Mat &src, const cv::Mat &templ);

  // returns the warped version of the mask if found else return nothing
  void warpPerspective(cv::Mat &mask, cv::Mat &warped);

  void loadTemplates(std::vector<cv::Mat> &templates);

  // usage: auto [triangles, circles, rectangles] = countShapes(frame);
  std::tuple<int, int, int> countShapes(cv::Mat &frame);
};
