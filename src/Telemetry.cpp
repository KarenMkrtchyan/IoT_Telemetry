#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "utilities.h"

Adafruit_SSD1306 display(LCD_COLS, LCD_ROWS, &Wire, LCD_RESET);

void setup() {
    Wire.begin(LCD_SDA, LCD_SCL);
    if (!display.begin(SSD1306_SWITCHCAPVCC, LCD_ADDR)) {
        Serial.println("SSD1306 allocation/init failed. Check wiring/address.");
        for(;;);
    }

    display.clearDisplay();
    display.setTextSize(2);                 // 2x scale
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Hello,");
    display.println("ESP32 OLED!");
    display.display();    
}

void loop() {

}
