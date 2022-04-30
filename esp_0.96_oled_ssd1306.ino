/**
 * ESP8266 with 0.96" SSD1306 OLED display
 * 
 * Scheda: ESP8266 Generic, 115200 baud
 * 
 * Connect ESP8266 to 5V USB power or use VIN pin to power
 * 
 * PINOUT
 * DISPLAY OLED 0.96" -> ESP8266
 *                GND -> G
 *                VCC -> 3.3V
 *                SDA -> D2 (GPIO 4)
 *                SDC -> D1 (GPIO 5)
 * 
 * Display driver used is Adafruit's SSD1306 v2.3.5.
 * 
 * @author Julian E.Spina (jes@acca3.it)               
 */
#include <SPI.h> 
#include <Adafruit_SSD1306.h>

// -------------------
// SSD1306 OLED SCREEN
// -------------------

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin or for ESP8266)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
void setup() {
  Serial.begin(115200);
  Serial.println(F("Startup..."));

  // SSD1306 display  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  Serial.println(F("SSD1306 init ok!"));

  // Screen init
  display.clearDisplay();
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  display.ssd1306_command(SSD1306_DISPLAYON); // (you can omit this command) SSD1306_DISPLAYON or SSD1306_DISPLAYOFF  
}

int count = 0;

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(count++);
  display.display(); 
  delay(100);
}
