#include <wiringPi.h>

#define LED1 25
#define LED2 24
#define SIGNAL_PIN 23
#define BUTTON 22
#define IDENTIFIER_PIN 21 // Define the pin used for the identifier

void send_setup() {
  wiringPiSetup();
  pinMode(LED1, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(SIGNAL_PIN, OUTPUT);
}

void recieve_setup() {
  wiringPiSetup();
  pinMode(LED2, OUTPUT);
  pinMode(SIGNAL_PIN, INPUT);
}

void send_loop() {
  if (digitalRead(BUTTON) == HIGH) {
    digitalWrite(LED1, HIGH);
    delay(2000);
    digitalWrite(LED1, LOW);
    digitalWrite(SIGNAL_PIN, HIGH);
  }
}

void recieve_loop() {
  if (digitalRead(SIGNAL_PIN) == HIGH) {
    digitalWrite(LED2, HIGH);
    delay(2000);
    digitalWrite(LED2, LOW);
  }
}

int main() {
  wiringPiSetup();
  pinMode(IDENTIFIER_PIN, INPUT);
  if (digitalRead(IDENTIFIER_PIN) == HIGH) {
    send_setup();
    while (1) {
      send_loop();
    }
  } else {
    recieve_setup();
    while (1) {
      recieve_loop();
    }
  }
}
