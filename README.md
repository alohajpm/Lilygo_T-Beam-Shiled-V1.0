# Lilygo_T-Beam-Shiled-V1.0
I removed the screen from my T-Beam (US Meshtastic V1.2) and installed the T-Beam-Shiled-V1.0; Only to find that there was no code to be found!? This isn't great, and I had the radio working and then messed it up so if someone wants to go from here please do! I would call this a solid starting point.

![IMG_6888](https://github.com/user-attachments/assets/86f6fcbf-fbe0-4341-adbf-2b6d6d2f485a)

# T-Beam Setup Guide

## Prerequisites
- Arduino IDE installed
- ESP32 board support package installed
- Required libraries:
  - RadioLib
  - TFT_eSPI
  - TinyGPSPlus
  - AceButton
  - XPowersLib

## Step-by-Step Setup

### 1. Install ESP32 Board Support
1. Open Arduino IDE
2. Go to File > Preferences
3. Add the following URL to "Additional Board Manager URLs":
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Go to Tools > Board > Boards Manager
5. Search for "esp32" and install "ESP32 by Espressif Systems"

### 2. Install Required Libraries
Go to Tools > Manage Libraries and install:
- RadioLib by Jan Gromeš
- TFT_eSPI by Bodmer
- TinyGPSPlus by Mikal Hart
- AceButton by Brian T. Park
- XPowersLib by Lewis He

### 3. Configure TFT_eSPI Library
1. Navigate to your Arduino libraries folder:
   - Windows: `Documents/Arduino/libraries/TFT_eSPI`
   - Linux: `~/Arduino/libraries/TFT_eSPI`
   - macOS: `~/Documents/Arduino/libraries/TFT_eSPI`
2. Replace the contents of `User_Setup.h` with the provided configuration:
   ```cpp
   #define USER_SETUP_INFO "User_Setup"
   #define ST7796_DRIVER

   // Pin configuration
   #define TFT_MISO -1    // Not connected
   #define TFT_MOSI 14    // IO14
   #define TFT_SCLK 15    // IO15
   #define TFT_CS   25    // IO25
   #define TFT_DC   13    // IO13
   #define TFT_RST   2    // IO02
   #define TFT_BL    4    // IO04

   #define TFT_WIDTH  275
   #define TFT_HEIGHT 480

   #define LOAD_GLCD
   #define LOAD_FONT2
   #define LOAD_FONT4
   #define SMOOTH_FONT

   #define SPI_FREQUENCY  27000000
   #define USE_HSPI_PORT

   #define TFT_INVERSION_ON
   #define SPI_READ_FREQUENCY  20000000
   #define SPI_TOUCH_FREQUENCY 2500000
   ```

### 4. Board Configuration
1. Select the correct board in Arduino IDE:
   - Tools > Board > ESP32 Arduino > TTGO T-Beam
2. Set the following options:
   - Upload Speed: 921600
   - CPU Frequency: 240MHz
   - Flash Frequency: 80MHz
   - Flash Mode: QIO
   - Flash Size: 4MB
   - Partition Scheme: Default
   - Core Debug Level: None
   - PSRAM: Disabled

### 5. Upload the Code
1. Clone or download the project files
2. Open the main sketch (TBeamFactory.ino) in Arduino IDE
3. Make sure all required files are in the sketch folder:
   - utilities.h
   - LoRaBoards.h
   - LoRaBoards.cpp
4. Connect your T-Beam via USB
5. Select the correct port in Tools > Port
6. Click Upload

## Troubleshooting

### Radio Issues
If the radio fails to initialize:
1. Check all SPI connections are correct
2. Verify the power management settings in LoRaBoards.cpp
3. Monitor the serial output for specific error codes

### Display Issues
1. Verify the TFT_eSPI configuration matches your hardware
2. Check the display power connections
3. Try reducing SPI_FREQUENCY if display is unstable

### GPS Issues
1. Check the GPS serial connection pins
2. Verify GPS_BAUD_RATE matches your module
3. Ensure clear view of sky for satellite reception

## Hardware Pin Configuration
- See utilities.h for complete pin mapping
- Default radio pins for T-BEAM_SX1276:
  ```cpp
  RADIO_SCLK_PIN: 5
  RADIO_MISO_PIN: 19
  RADIO_MOSI_PIN: 27
  RADIO_CS_PIN: 18
  RADIO_RST_PIN: 23
  RADIO_DIO0_PIN: 26
  RADIO_DIO1_PIN: 33
  ```

## Support
For additional help:
1. Check the serial monitor output for detailed debugging information
2. Verify all hardware connections
3. Ensure proper power supply to the board
