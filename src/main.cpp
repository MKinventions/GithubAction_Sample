#include <Arduino.h>

// #define ESP8266
// #define ARDUINO_NANO
#define ARDUINO_UNO

#if defined(ESP8266)
#define LED 16
#elif defined(ARDUINO_NANO) | defined(ARDUINO_UNO)
#define LED 13
#else
#error "Please Select Proper MCU."
#endif


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
