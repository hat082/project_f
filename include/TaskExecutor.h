class TaskExecutor {
public:
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
  void countShapes();
  void blinkLED();

  void playMusic();
  void alarmFlash();

  // ultrasonic sensor
  void approachAndStop();
  // kick ball
  void kickBall();
  // red stop green move
  void trafficLight();
};
