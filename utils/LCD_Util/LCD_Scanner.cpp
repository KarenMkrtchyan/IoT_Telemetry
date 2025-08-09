#include <Arduino.h>
#include <Wire.h>

void setup() {
    Serial.begin(115200);
    Wire.begin(21, 22); // SDA, SCL pins for most ESP32 dev boards

    Serial.println("I2C Scanner");
}

void loop() {
    byte error, address;
    int nDevices = 0;

    Serial.println("Scanning...");

    for (address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0) {
            Serial.print("I2C device found at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.print(address, HEX);
            Serial.println(" !");
            nDevices++;
        }
    }

    if (nDevices == 0)
        Serial.println("No I2C devices found");
    else
        Serial.println("Scan done");

    delay(2000); // wait 2 seconds between scans
}
