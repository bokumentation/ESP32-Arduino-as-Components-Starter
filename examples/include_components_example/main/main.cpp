// file: main.cpp
#include "Arduino.h"
#include "my_components.h"

const int ledPin = 2;
static const char *pMY_TAG = "LED";

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    ; // wait for serial port to connect
  }

  pinMode(ledPin, OUTPUT); // Initialize Pin as Output
  
  hello_log_init(); // Call our library my_components
  
  ESP_LOGI("TAG", "HELLO from ESP_LOG Info!");        // ESP-IDF Log Info
  Serial.println("HELLO from ARDUINO Serial Print!"); // Arduino Serial Print

  delay(3000);
}

void loop()
{
  digitalWrite(ledPin, HIGH); // Turn on LED
  ESP_LOGI(pMY_TAG, "ON");
  Serial.println("LED HIGH");
  delay(1000);

  digitalWrite(ledPin, LOW); // Turn off LED
  ESP_LOGI(pMY_TAG, "OFF");
  Serial.println("LED LOW");
  delay(1000);
}
