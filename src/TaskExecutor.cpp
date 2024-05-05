#include <TaskExecutor.h>
#include <iostream>
#include <sys/time.h>
#include <wiringPi.h>

TaskExecutor::TaskExecutor() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}

void TaskExecutor::blinkLED() { std::cout << "LED Blinking" << std::endl; }

void TaskExecutor::playMusic() {}
void TaskExecutor::alarmFlash() {}

// ultrasonic sensor
float TaskExecutor::calcDistance() {
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

void TaskExecutor::setTask(Task &var, int num) {
  if (num < NONE) {
    var = static_cast<Task>(num);
  } else {
    std::cout << "Error: Task index out of bounds\n";
  }
}

// kick ball
void TaskExecutor::kickBall() {}
// red stop green move
void TaskExecutor::trafficLight() {}
