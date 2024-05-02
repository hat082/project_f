#include <lcd.h>

#define rs 29
#define e 28
#define d4 25
#define d5 4
#define d6 23
#define d7 22

#define USS_TRIG 4
#define USS_ECHO 5

class HMI {
  HMI();
public:

private:
  int lcd_;
};
