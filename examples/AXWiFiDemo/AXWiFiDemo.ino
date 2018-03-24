#include "AXWIFI.h"
int i=0;
void setup() {
  ax.begin();
  // ax.SledTypeRGB();
  ax.SledTypeGRB();
  ax.beep();
  pinMode(D3,INPUT);
}

void loop() {
  ax.SledShow(0,32, 0, 0); 
  ax.SledShow(1,0, 0,32);
  
  ax.OledSetTextSize(2);
  ax.OledSetText(0,2,"AX-WiFi");
  ax.OledSetText(1,3,"%d",i++);
  ax.OledSetText(2,1,"Pi=%.3f",3.141);
  ax.OledShow();
  if(!digitalRead(D3)){
    ax.beep();
  }
}