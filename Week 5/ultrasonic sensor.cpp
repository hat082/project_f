#include <cstdio>
#include <cstdlib>
#include <lcd.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#define TRIG 4
#define ECHO 5
#define TIMEOUT_MICROS 30000L  // 30 milliseconds timeout
#define DEFAULT_DISTANCE 50.0f // Default distance in cm
#define THRESHOLD 23.1
// bcm
#define rs 29
#define e 28
#define d4 25
#define d5 24
#define d6 23
#define d7 22

int lcd_;

float calcDistance();
void lcdPrintTaskApproach(int distance);

int main() {
  wiringPiSetup();
  int robot = serialOpen("/dev/ttyAMA0", 57600); // returns int, -1 for error
  char cmd[50];
  lcd_ = lcdInit(2, 16, 4, rs, e, d4, d5, d6, d7, 0, 0, 0, 0);
  lcdPosition(lcd_, 0, 0);

  sprintf(cmd, "#Baffff %03d %03d %03d %03d", 23, 30, 31, 30);
  serialPuts(robot, cmd);
  while (1) {
    // if the distance is within threshold
    int distance = calcDistance();
    if (distance < THRESHOLD) {
      sprintf(cmd, "#ha");
      delay(100);
      system("omxplayer music.mp4");
      break;
    }
    // lcd print distance
    lcdPrintTaskApproach(distance);
  }
  return 0;
}

void lcdPrintTaskApproach(int distance) {
  lcdClear(lcd_);
  lcdPosition(lcd_, 0, 0);
  lcdPuts(lcd_, "Task: Approach");
  lcdPosition(lcd_, 0, 1);
  lcdPrintf(lcd_, "D: %d", distance);
}

float calcDistance() {
  long durationMicros;
  float distance;
  unsigned long startTime;
  unsigned long echoBegin;

  // Trigger the sensor by setting the trigger pin high for 10 microseconds
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Wait for the echo pin to go high, indicating the start of the echo
  startTime = micros();
  while (digitalRead(ECHO) == LOW) {
    if (micros() - startTime > TIMEOUT_MICROS) {
      return DEFAULT_DISTANCE; // Return the default distance on timeout
    }
  }

  // Record the start time of the echo
  echoBegin = micros();

  // Wait for the echo pin to go low, indicating the end of the echo
  while (digitalRead(ECHO) == HIGH) {
    if (micros() - echoBegin > TIMEOUT_MICROS) {
      return DEFAULT_DISTANCE; // Return the default distance on timeout
    }
  }

  // Calculate the duration of the echo in microseconds
  durationMicros = micros() - echoBegin;

  // The speed of sound is approximately 29.1 cm per microsecond in fresh air at
  // 20°C Since the sound wave goes out and comes back, we divide by 2
  distance = (float)durationMicros / 58.1f;

  return distance;
}
