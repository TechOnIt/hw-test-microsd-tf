# MicroSD / TF Module Test (ESP32)

A simple test project for reading and writing data to a MicroSD (TF) card module using the SPI interface with ESP32.

<p align="center">
  <img width="500" height="436" alt="dat-01-003-new-2" src="https://github.com/user-attachments/assets/472efa2e-5491-480e-8ac7-2f04e1e8c563" />
</p>

## Hardware

### Wiring

| MicroSD Module | ESP32   |
| -------------- | ------- |
| CS             | GPIO 5  |
| SCK            | GPIO 18 |
| MISO           | GPIO 19 |
| MOSI           | GPIO 23 |
| VCC            | 5V      |
| GND            | GND     |

> This module was tested successfully with a 5V power supply.
> 3.3V power did not work with this specific module.

## Dependencies

No external library is required.

The project uses built-in Arduino libraries:

```cpp
#include <SPI.h>
#include <SD.h>
```

## SPI Configuration

Custom SPI pins are configured as:

```cpp
SPI.begin(18, 19, 23, CS);
```

Parameters:

| SPI Signal | GPIO |
| ---------- | ---- |
| SCK        | 18   |
| MISO       | 19   |
| MOSI       | 23   |
| CS         | 5    |

## SD Card Initialization

The SD card is initialized with a custom SPI instance:

```cpp
SD.begin(CS, SPI, 1000000)
```

SPI frequency is set to:

```
1 MHz
```

## Test Functionality

The test performs:

1. Initialize SD card.
2. Create/open `/test.txt`.
3. Write sample sensor log data.
4. Close the file.

Example output file:

```text
2026/10/02 20:08 - Temp: 27.77 - Hum: 33.12%
2026/10/02 20:13 - Temp: 27.75 - Hum: 33.10%
2026/10/02 20:18 - Temp: 27.72 - Hum: 33.08%
```

## Serial Output

Successful run:

```text
SD OK!
Write OK!
```

If initialization fails:

```text
SD Failed!
```

## Notes

* MicroSD modules may require 5V power depending on their onboard regulator and level shifter.
* FAT32 formatted cards are recommended.
* For sensor logging projects, this module can be used as a simple data logger for temperature, humidity, and other measurements.
