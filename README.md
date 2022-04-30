# ESP8266_OLED096
ESP8266 driving SSD1306 0.96 OLED display

This simple code shows how to connect an ESP8266 board to a SSD1306 0.96" OLED display, using Adafruit 1306 library[^1].

### SSD1306 Info
- The display has 4 wires: GND, VCC, SCL and SDA. All four wires will be connected to the MCU pins.
- We can use ESP8266's 3.3V output pin to power the display (on Arduino we'd use the 5V pin).
- Operating Temperature: -40 to +85 ºC
- Max current usage (at max contrast setting): 780 uA[^2]

### Pin connection
 DISPLAY OLED 0.96" <-> ESP8266  
                GND <-> G  
                VCC <-> 3.3V  
                SDA <-> D2 (GPIO 4)  
                SDC <-> D1 (GPIO 5)  
                

[^1]: https://github.com/adafruit/Adafruit_SSD1306.
[^2]: http://electronic.acca3.it/wp-content/uploads/2022/04/Solomon_Systech_SSD1306.pdf.                
