#include <HMI.h>
#include <sys/time.h>
#include <time.h>
#include <wiringPi.h>

HMI::HMI() {
  int lcd_ = lcdInit(2, 16, 4, rs, e, d4, d5, d6, d7, 0, 0, 0, 0);
  lcdPosition(lcd_, 0, 0);
}

// lcdClear(lcd);
// lcdPosition(lcd, 0, 0);
// lcdPuts(lcd, "Recognising");
//  lcdPrintf(lcd, "2 ");

float getDistance() {
  struct timeval echoBegin, echoEnd;
  long durationMicros;
  float distance;

  // Trigger the sensor by setting the trigger pin high for 10 microseconds
  digitalWrite(USS_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(USS_TRIG, LOW);

  // Wait for the echo pin to go high, indicating the start of the echo
  while (digitalRead(USS_ECHO) == LOW)
    ;

  // Record the start time of the echo
  gettimeofday(&echoBegin, NULL);

  // Wait for the echo pin to go low, indicating the end of the echo
  while (digitalRead(USS_ECHO) == HIGH)
    ;

  // Record the end time of the echo
  gettimeofday(&echoEnd, NULL);

  // Calculate the duration of the echo in microseconds
  durationMicros = (echoEnd.tv_sec - echoBegin.tv_sec) * 1000000L +
                   (echoEnd.tv_usec - echoBegin.tv_usec);

  // Calculate the distance using the speed of sound and the duration of the
  // echo
  distance = ((float)durationMicros / 2) / 29.1f;

  return distance;
}
