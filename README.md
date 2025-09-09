# Setup arduino-esp32 as ESP-IDF Components

Note: This is for standard ESP32 chip. But you can set-target to another. Read below.
Important:  We need internet connection to automatically download the managed_components.

Clone this repo then just run:
```bash
idf.py build
idf.py -p COMx flash monitor
```
Note:
- change the `x` to your actual port. By default are COM3.

---
### If you're using another esp32 chip
- Open idf_component.yml on the `main` folder.
- Delete the line of `espressif/arduino-esp32: ^3.3.0`. This is prevent the `idf.py` to include it.
- Then we can run these below.
    ```bash
    idf.py set-target esp32c3
    idf.py menuconfig
    ```
- Navigate to `Component config` -> `FreeRTOS` -> `Kernel` -> `configTICK_RATE_HZ`. Set it to 1000. Then press `enter` and save.
- Then we can add arduino as components.
    ```
    idf.py add-dependency "espressif/arduino-esp32^3.3.0"

- Now we can build and flash it.    
    ```bash
    idf.py build
    idf.py -p COMx flash monitor
    ```

--- 
### Some note if you're planning to use Arduino as Components: 
Before you run `idf.py add-dependency "espressif/arduino-esp32^3.3.0"`, You need to set `CONFIG_FREERTOS_HZ=1000` (currently 100 by default) by using `idf.py menuconfig` then navigate to `Component config` -> `FreeRTOS` -> `Kernel` -> `configTICK_RATE_HZ`. Save it then enjoy.
