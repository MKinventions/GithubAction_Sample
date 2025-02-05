#include <Arduino.h>
#include <EEPROM.h>

// Conditional compilation to define the LED pin
#ifdef ARDUINO_AVR_NANO        // For Arduino Nano (ATmega328)
#define LED 13                 // Built-in LED on pin 13
#elif defined(ARDUINO_AVR_UNO) // For Arduino Uno (ATmega328)
#define LED 13                 // Built-in LED on pin 13
#elif defined(esp12e)          // For ESP8266 (ESP12E)
#define LED LED_BUILTIN        // Built-in LED on GPIO2 (NodeMCU)
#elif defined(ESP32)           // For ESP32 (DevKit V1, WROOM, etc.)
#define LED 2                  // Built-in LED on GPIO2
#else
#define LED 13 // Default to pin 13 if the platform is unknown
#endif

const int addr1 = 10;
bool ledState = false;

void ledBlink();

void setup()
{
#if defined(ESP32)
  EEPROM.begin(512);
#endif

  Serial.begin(9600);
  Serial.println("Restarted");

  pinMode(LED, OUTPUT); // Set LED pin as output

  ledState = EEPROM.read(addr1);
  Serial.println("LedState:" + String(ledState));
}

void loop()
{

  ledBlink();
}

void ledBlink()
{
  ledState = !ledState;
  EEPROM.write(addr1, ledState);
#if defined(ESP32)
  EEPROM.commit();
#endif

  digitalWrite(LED, ledState); // Toggle the LED
  delay(1000);                 // Wait for 1 second
}