// Copyright (c) M5Stack. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "AXWIFI.h"

void AXWIFI::begin() {
    Serial.begin(115200);
    Serial.flush();
    Serial.println("\nAXWIFI initializing...");
    pinMode(_PINSLEDs,OUTPUT);
    sleds.begin(); // This initializes the NeoPixel library.
    for(int i=0;i<_NUMSLEDs;i++){
     sleds.setPixelColor(i,sleds.Color(0, 0, 0)); //Adjust brightness, Color red 
    }
    sleds.show(); // Initialize all SLEDs to 'off'
    __size=1;
    Oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
    Oled.clearDisplay();   // Clear the buffer.
    Oled.setTextSize(1);
    Oled.setTextColor(WHITE,BLACK);
    Oled.setCursor(0,0);
}
void AXWIFI::clear() {
    AX.begin();
}
void AXWIFI::beep() {
    //pinMode(15,OUTPUT);
    analogWriteFreq(1000);
    analogWrite(15,255);
    delay(250);
    analogWrite(15,0);
    //tone(15,2000,250);
}
void AXWIFI::SledTypeGRB() {
    sleds.updateType(NEO_GRB + NEO_KHZ800);  
}
void AXWIFI::SledTypeRGB() {
    sleds.updateType(NEO_RGB + NEO_KHZ800);  
}
void AXWIFI::SledShow(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
      sleds.setPixelColor(n,r, g,b);
      sleds.show();
}
void AXWIFI::OledShow(uint8_t l, uint8_t c,char *fmt, ... ){
        char buf[128]; // resulting string limited to 128 chars
        va_list args;
        va_start (args, fmt );
        vsnprintf(buf, 128, fmt, args);
        va_end (args);
        //Serial.print(__size);
        Oled.setCursor(__size*6*c,__size*8*l);
        Oled.print(buf);
        Oled.display();
}
void AXWIFI::OledSetText(uint8_t l, uint8_t c,char *fmt, ... ){
        char buf[128]; // resulting string limited to 128 chars
        va_list args;
        va_start (args, fmt );
        vsnprintf(buf, 128, fmt, args);
        va_end (args);
        //Serial.print(__size);
        Oled.setCursor(__size*6*c,__size*8*l);
        Oled.print(buf);
}
void AXWIFI::OledShow(void){
        Oled.display();
}
void AXWIFI::OledSetTextSize(int size){
    __size = size;
    Oled.setTextSize(size);
}
AXWIFI AX;
