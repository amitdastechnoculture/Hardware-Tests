#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 

 void setup(void) {
   u8g2.begin();
}

  void loop(void) {
   u8g2.clearBuffer();					// clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawStr(8,29,"Techno");	// write something to the internal memory
   u8g2.sendBuffer();					// transfer internal memory to the display
   delay(3000);

   u8g2.clearBuffer();         // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawStr(31,24,"Culture");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(800);

   u8g2.clearBuffer();         // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawStr(10,29,"Research");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(800);

   u8g2.clearBuffer();         // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawStr(4,29,"Organization");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(2000);

   
}
