#include <Arduino.h>

#define LED 13

void setup() {
Serial.begin(9600);
Serial.println("Restarted");

pinMode(LED, OUTPUT);

}

void loop() {
static int ledState = 0;

ledState = !ledState;
digitalWrite(LED, ledState);
Serial.println("Hello World!");
delay(1000);
}
