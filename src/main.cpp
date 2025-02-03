#include <Arduino.h>


void setup() {
Serial.begin(9600);
Serial.println("Restarted");

}

void loop() {
Serial.println("Hello World!");
delay(1000);
}
