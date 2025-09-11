# Simple Setup for arduino-esp32 as ESP-IDF Components

>[!IMPORTANT]
> This is for **Standard ESP32 Chip**. But you can set-target to another (Read below).
> 
> We need an **Internet Connection** to automatically download the managed_components.

## Get Started
Follow the intructions command below.
- Run ESP-IDF 
- Clone and navigate the project folder.
  ```bash
  git clone https://github.com/bokumentation/ESP32-Arduino-as-Components-Starter.git
  cd ESP32-Arduino-as-Components-Starter/examples/arduino_style
  ```
- Build then flash to the esp32.
  ```bash
  idf.py build
  idf.py -p COMx flash monitor
  ```
  > [!NOTE]
  > Change the `x` to your actual port. By default are COM3 (In case my projects. Check int the device manager).
- Now you LED should blinking.

---
### If you're using another esp32 chip
- Delete the `idf_component.yml` in the `main` folder.
- Then run these esp-idf command below.
    ```bash
    idf.py set-target <your_esp_type>
    idf.py menuconfig
    ```
- Navigate to `Component config` -> `FreeRTOS` -> `Kernel` -> `configTICK_RATE_HZ`. Set it to 1000. Then press `enter` and save.
- Then back to the top menu again, navigate to `Component config -> Diagnostics -> Use external log wrapper`. Enter (it will `[*]`) then save. Exit the menuconfig.
- Then, add arduino as components.
    ```bash
    idf.py add-dependency "espressif/arduino-esp32^3.3.0"
    ```
- Now we can build and flash it.    
    ```bash
    idf.py build
    idf.py -p COMx flash monitor
    ```

>[!NOTE]
> Change the `x` to your actual port. By default are COM3 (In case my projects. Check int the device manager).

--- 
### Some note if you're planning to use Arduino as Components: 
Before you run `idf.py add-dependency "espressif/arduino-esp32^3.3.0"`, You need to set `CONFIG_FREERTOS_HZ=1000` (currently 100 by default) by using `idf.py menuconfig` then navigate to `Component config` -> `FreeRTOS` -> `Kernel` -> `configTICK_RATE_HZ`. The tickHZ problem now is gone.

After i compiled some `Wifi.h` code, the compiler told me about undefined reference to `__wrap_esp_log_write` and `__wrap_esp_log_writev`. Turn out, we need to enable external log wrapper at menunconfig `Component config -> Diagnostics -> Use external log wrapper`. 

---
### The Style
There is two option, by using `void setup()` and `loop()` like Arduino's does, or by using `extern "C" void app_main()` like the esp-idf. Here the example from their documentation.

#### Arduino IDE Style
We need to turn on the `Autostart Arduino setup and loop boot` on the `idf.py menuconfig`. We can see the `Arduino option` in menuconfig after added the `arduino-esp` as components.

```cpp
//file: main.cpp
#include "Arduino.h"

void setup(){
  Serial.begin(115200);
  while(!Serial){
    ; // wait for serial port to connect
  }
}

void loop(){
    Serial.println("loop");
    delay(1000);
}
```

#### ESP-IDF Style
If you wanna use this, just turn off the `Autostart Arduino setup and loop boot` on the `idf.py menuconfig`.
```cpp
//file: main.cpp
#include "Arduino.h"

extern "C" void app_main()
{
  initArduino();

  // Arduino-like setup()
  Serial.begin(115200);
  while(!Serial){
    ; // wait for serial port to connect
  }

  // Arduino-like loop()
  while(true){
    Serial.println("loop");
  }

  // WARNING: if program reaches end of function app_main() the MCU will restart.
}
```

---
