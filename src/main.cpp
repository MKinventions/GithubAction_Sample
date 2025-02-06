#include <Arduino.h>
#include <EEPROM.h>

const int addr1 = 10;
bool ledState = false;

void ledBlink(int delayTime);

void setup()
{
#if defined(ESP32)
  EEPROM.begin(512);
#endif

  Serial.begin(9600);
  Serial.println("Restarted");

  pinMode(LED, OUTPUT); // Set LED pin as output
  pinMode(BTN, INPUT_PULLUP);

  ledState = EEPROM.read(addr1);
  Serial.println("LedState:" + String(ledState));
}

void loop()
{
  bool buttonState = digitalRead(BTN);

  if (buttonState)
  {
    ledState = true;
  }else{
    ledState = false;
  }
  
  digitalWrite(LED, ledState);
  // ledBlink(100);
  
}

void ledBlink(int delayTime)
{
  ledState = !ledState;
  EEPROM.write(addr1, ledState);
#if defined(ESP32)
  EEPROM.commit();
#endif

  digitalWrite(LED, ledState); // Toggle the LED
  delay(delayTime);                 // Wait for 1 second
}