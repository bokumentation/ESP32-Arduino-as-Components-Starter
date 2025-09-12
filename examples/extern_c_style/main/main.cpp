// file: main.cpp
#include "Arduino.h"

const int ledPin = 2;
static const char *pMY_TAG = "LED";

extern "C" void app_main() {
  initArduino(); // Initialize the Arduino core

  // Arduino-like setup()
  Serial.begin(115200);
  while (!Serial) {
    ; // Wait for serial port to connect
  }

  pinMode(ledPin, OUTPUT); // Initialize Pin as Output

  ESP_LOGI("TAG", "HELLO from ESP_LOG Info!");        // ESP-IDF Log Info
  Serial.println("HELLO from ARDUINO Serial Print!"); // Arduino Serial Print

  delay(3000);

  // Arduino-like loop()
  while (true) {
    digitalWrite(ledPin, HIGH); // Turn on LED
    ESP_LOGI(pMY_TAG, "ON");
    Serial.println("LED HIGH");
    delay(1000);

    digitalWrite(ledPin, LOW); // Turn off LED
    ESP_LOGI(pMY_TAG, "OFF");
    Serial.println("LED LOW");
    delay(1000);
  }

  // WARNING: If the program reaches the end of app_main(), the MCU will
  // restart.
}