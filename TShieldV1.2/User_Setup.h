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

// Correct resolution for ST7796
#define TFT_WIDTH  275
#define TFT_HEIGHT 480

// Fonts
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define SMOOTH_FONT

// Performance settings
#define SPI_FREQUENCY  27000000  // Reduced from 40MHz for stability
#define USE_HSPI_PORT

// Try adding these for stability
#define TFT_INVERSION_ON
#define SPI_READ_FREQUENCY  20000000
#define SPI_TOUCH_FREQUENCY 2500000
