
#define TRIG 4
#define ECHO 5
#define RED_LED 27
#define BLUE_LED 26
#define TIMEOUT_MICROS 30000L  // 30 milliseconds timeout
#define DEFAULT_DISTANCE 50.0f // Default distance in meters

class TaskExecutor {
public:
  TaskExecutor();
  enum Task {
    SHAPES1,
    SHAPES2,
    SHAPES3,
    BLUE,
    GREEN,
    RED,
    YELLOW,
    MUSIC,
    LED_BLINK,
    APPROACH_AND_STOP,
    KICK_FOOTBALL,
    TRAFFIC_LIGHTS,
    NONE
  };

public:
  void blinkLED();

  void playMusic();
  void alarmFlash();

  // ultrasonic sensor
  float calcDistance();
  // kick ball
  void kickBall();
  // red stop green move
  void trafficLight();
  // var is the variable that holds the current task
  void setTask(Task &var, int num);
};

float getDistance();
