// file: main.cpp
#include "Arduino.h"

extern "C" void app_main() {
  initArduino(); // Initialize the Arduino core

  // Arduino-like setup()
  Serial.begin(115200);
  while (!Serial) {
    ; // Wait for serial port to connect
  }

  // Arduino-like loop()
  while (true) {
    Serial.println("Looping...");
    delay(1000); // Wait for 1 second
  }

  // WARNING: If the program reaches the end of app_main(), the MCU will
  // restart.
}