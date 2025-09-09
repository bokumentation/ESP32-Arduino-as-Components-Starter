//file: main.cpp

#include "Arduino.h"

#ifdef ARDUINO_ARCH_ESP32
#include "esp32-hal-log.h"
#endif

const int ledPin = 2;

void setup(){
  Serial.begin(115200);
  while(!Serial){
    ; // wait for serial port to connect
  }
  pinMode(ledPin, OUTPUT);
}

void loop(){
    digitalWrite(ledPin, HIGH);
    Serial.println("LED HIGH");
    delay(1000);
    digitalWrite(ledPin, LOW);
    Serial.println("LED LOW");
    delay(1000);
}