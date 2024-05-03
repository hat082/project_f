#include <HMI.h>

#include <wiringPi.h>

HMI::HMI() {
  int lcd_ = lcdInit(2, 16, 4, rs, e, d4, d5, d6, d7, 0, 0, 0, 0);
  lcdPosition(lcd_, 0, 0);
}

void HMI::lcdPrintTask(const std::string& message) {
  lcdClear(lcd_);
  lcdPosition(lcd_, 0, 0);
  lcdPrintf(lcd_, "Task: %s", message.c_str());
}

void HMI::lcdPrintTaskShape(int t_count, int s_count, int c_count) {
  lcdClear(lcd_);
  lcdPosition(lcd_, 0, 0);
  lcdPuts(lcd_, "Task: Count Shape");
  lcdPosition(lcd_, 0, 1);
  lcdPrintf(lcd_, "T: %d S: %d C: %d", t_count, s_count, c_count);
}

void HMI::lcdPrintTaskApproach(int distance) {
  lcdClear(lcd_);
  lcdPosition(lcd_, 0, 0);
  lcdPuts(lcd_, "Task: Approach");
  lcdPosition(lcd_, 0, 1);
  lcdPrintf(lcd_, "D: %d", distance);
}

// void lcdPrintf(const std::string &format, ...) {
//   va_list args;
//   va_start(args, format);
//   // Code to print formatted message on the LCD using args
//   va_end(args);
// }
//
// template <typename... Args>
// void lcdPrintTask(const std::string &taskName, const Args &...args) {
//   lcdClear();
//   lcdPosition(0, 0);
//   lcdPuts(taskName);
//
//   if constexpr (sizeof...(args) > 0) {
//     lcdPosition(0, 1);
//     lcdPrintf(formatString(taskName, args...), args...);
//   }
// }

