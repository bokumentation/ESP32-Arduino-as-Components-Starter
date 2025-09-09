//file: main.cpp
#include "Arduino.h"
#include "esp_log.h"

const int ledPin = 2;
static const char* pMY_TAG = "LED";

void setup(){
  Serial.begin(115200);
  while(!Serial){
    ; // wait for serial port to connect
  }
  pinMode(ledPin, OUTPUT);  // Initialize Pin as Output
}

void loop(){
  // Turn on LED
  digitalWrite(ledPin, HIGH);
  
  // Added LOG INFO
  ESP_LOGI(pMY_TAG, "ON");    // ESP-IDF LOG
  Serial.println("LED HIGH"); // Arduino Style
  
  delay(1000);
  
  // Turn off LED
  digitalWrite(ledPin, LOW);
  
  // Added LOG INFO
  ESP_LOGI(pMY_TAG, "OFF");   // ESP-IDF LOG
  Serial.println("LED LOW");  // Arduino Style
    
  delay(1000);
}