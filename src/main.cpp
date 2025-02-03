#include <Arduino.h>

// Conditional compilation to define the LED pin
#ifdef ARDUINO_AVR_NANO  // For Arduino Nano (ATmega328)
  #define LED 13  // Built-in LED on pin 13
#elif defined(ESP8266)   // For ESP8266 (ESP12E)
  #define LED LED_BUILTIN  // Built-in LED on GPIO2 (NodeMCU)
#else
  #define LED 13  // Default to pin 13 if the platform is unknown
#endif

void setup() {
  Serial.begin(9600);
  Serial.println("Restarted");

  pinMode(LED, OUTPUT);  // Set LED pin as output
}

void loop() {
  static int ledState = 0;

  ledState = !ledState;
  digitalWrite(LED, ledState);  // Toggle the LED
  Serial.println("Hello World!");
  delay(1000);  // Wait for 1 second
}
