#ifndef _AXWIFI_H_
#define _AXWIFI_H_
#if defined(ESP8266)
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdarg.h>

class AXWIFI  {
 public:
    #define _NUMSLEDs  2
    #define _PINSLEDs  10
    Adafruit_NeoPixel Sled = Adafruit_NeoPixel(_NUMSLEDs,_PINSLEDs, NEO_GRB + NEO_KHZ800);
    Adafruit_SSD1306 Oled = Adafruit_SSD1306(-1);
    void begin(void),
		 clear(void),
         beep(void),
         SledTypeGRB(void),
         SledTypeRGB(void),
         SledShow(uint16_t n, uint8_t r, uint8_t g, uint8_t b),
         OledShow(uint8_t l, uint8_t c,char *fmt, ... ),
         OledSetText(uint8_t l, uint8_t c,char *fmt, ... ),
         OledShow(void),
         OledSetTextSize(int size);
 private:
    int __size;
};
extern AXWIFI AX;
#define ax AX
#define  sleds Sled
#define  oled Oled
#endif
#endif
