#include <lcd.h>
#include <string>

#define rs 29
#define e 28
#define d4 25
#define d5 24
#define d6 23
#define d7 22

class HMI {

public:
  HMI();

  // lcd print task for count shapes
  void lcdPrintTaskShape(int t_count, int s_count, int c_count);

  void lcdPrintTaskApproach(int distance);

  void lcdPrintTask(const std::string &message);

private:
  int lcd_;
};
