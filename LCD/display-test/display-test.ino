#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS   4
#define TFT_RST  5 
#define TFT_DC   6

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

uint16_t width = 100;
uint16_t height = 100;
char buffer[100];

void setup(void) {
  Serial.begin(115200);
  tft.setSPISpeed(400000);
  tft.invertDisplay(false);
  tft.setRotation(1);
}

void loop(){
  tft.init(width, height);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(1);
  tft.setTextWrap(true);
  sprintf(buffer, "%dx%d\n", width, height);
  tft.print(buffer);
  delay(500);

  // Uncomment for width/height test
  //width++;
  //height++;
}

