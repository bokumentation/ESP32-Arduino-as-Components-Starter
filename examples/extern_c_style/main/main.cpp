//file: main.cpp
#include "Arduino.h"

const int ledPin = 2;

extern "C" void app_main()
{
  initArduino();

  // Arduino-like setup()
  Serial.begin(115200);
  while(!Serial){
    ; // wait for serial port to connect
  }

  pinMode(ledPin, OUTPUT);

  // Arduino-like loop()
  while(true){
    digitalWrite(ledPin, HIGH);
    Serial.println("LED HIGH");
    delay(1000);
    digitalWrite(ledPin, LOW);
    Serial.println("LED LOW");
    delay(1000);
  }
}