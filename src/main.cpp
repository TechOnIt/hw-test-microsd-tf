#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#define CS 5

void setup()
{
    Serial.begin(115200);

    SPI.begin(18, 19, 23, CS);

    if (!SD.begin(CS, SPI, 1000000))
    {
        Serial.println("SD Failed!");
        return;
    }
    else
        Serial.println("SD OK!");

    File file = SD.open("/test.txt", FILE_WRITE);

    if (file)
    {
        file.println("2026/10/02 20:08 - Temp: 27.77 - Hum: 33.12%");
        file.println("2026/10/02 20:13 - Temp: 27.75 - Hum: 33.10%");
        file.println("2026/10/02 20:18 - Temp: 27.72 - Hum: 33.08%");
        file.close();

        Serial.println("Write OK!");
    }
    else
        Serial.println("File open failed!");
}

void loop()
{
}
