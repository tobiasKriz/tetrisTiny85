/*
   Tiny4kOLED - Drivers for SSD1306 controlled dot matrix OLED/PLED 128x32 displays

   Based on ssd1306xled, re-written and extended by Stephen Denne
   from 2017-04-25 at https://github.com/datacute/Tiny4kOLED

*/

// Choose your I2C implementation before including Tiny4kOLED.h
// The default is selected is Wire.h

// To use the Wire library:
//#include <Wire.h>

// To use the Adafruit's TinyWireM library:
#include <TinyWireM.h>

// To use the TinyI2C library from https://github.com/technoblogy/tiny-i2c
//#include <TinyI2CMaster.h>

// The blue OLED screen requires a long initialization on power on.
// The code to wait for it to be ready uses 20 bytes of program storage space
// If you are using a white OLED, this can be reclaimed by uncommenting
// the following line (before including Tiny4kOLED.h):
#define TINY4KOLED_QUICK_BEGIN

#include <Tiny4kOLED.h>
//#include "SolomonSystech.h"

// ============================================================================
bool block1[4][3] = {
  {0, 0, },
  {0, 0, 0},
  {1, 0, 0},
  {1, 1, 1}
};

bool gamestate[16][8] = {  
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 0
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 1
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 2
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 3
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 4
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 5
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 6
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 7
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 8
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 9
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 10
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 11
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 12
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 13
  {0, 0, 0, 0, 0, 0, 0, 0}, // Řádek 14
  {1, 1, 1, 1, 1, 1, 1, 1}  // Poslední řádek (řádek 15)
};



int temp = 0;
int cursorX = 4;
int cursorY = 8;
void setup() {
  // put your setup code here, to run once:

  oled.begin(128, 64, sizeof(tiny4koled_init_128x64r), tiny4koled_init_128x64r);
 


pinMode(3, OUTPUT);


  oled.clear();
  oled.setFont(FONT8X16);
  oled.setInverse(true);
   oled.on();
 
    for (int i = 15;i >= 0 ;i--){
       for (int k = 7;k >= 0 ;k--){
                oled.setCursor(i*8-8,k);
                
    if(gamestate[i][k] == 1){
 
       oled.print("$");

    }
    else{
  
      //oled.print(" ");
    }
       }
  
  }
 }

void loop() {

  int temp = analogRead(A2);
  

 

//oled.setFont(FONT6X8);oled.setCursor(10, 6);oled.print(temp);oled.setCursor(30, 6);oled.print(cursorY);oled.setFont(FONT8X16);
//oled.setCursor(40, 1);oled.print(strela);oled.setCursor(40, 1);oled.print("  ");

  

//PRAVE TLACITKO
  if (temp >830 && temp < 845) {
        

   for (int i = 3;i >= 0 ;i--){
    for (int k = 2;k >= 0 ;k--){
  oled.setCursor(cursorY + i*8,cursorX-k);
  oled.print(" ");
    }
   }
cursorX++; 

  }
//LEVE TLACITKO  
  if (temp > 505 && temp < 515) {
   for (int i = 3;i >= 0 ;i--){
    for (int k = 2;k >= 0 ;k--){
  oled.setCursor(cursorY + i*8,cursorX-k);
  oled.print(" ");
  
   }
   }
  cursorX--;  


  }
 //STREDNI TLACITKO
  if (temp >695 && temp < 705) {
   

       
  }
 


  


  for (int i = 3;i >= 0 ;i--){
  for (int k = 2;k >= 0 ;k--){
        oled.setCursor(cursorY + i*8,cursorX - k);
  if(block1[i][k] == 1){
//delay(300);
     oled.print("$");
  }
  else{

    //oled.print(" ");
  }


}
}
if((gamestate[cursorY/8+5][cursorX] == 1 && block1[3][0] == 1)||(gamestate[cursorY/8+5][cursorX-1] == 1 && block1[3][1] == 1)||(gamestate[cursorY/8+5][cursorX-2] == 1 && block1[3][2] == 1)){
  oled.setInverse(false);
   for (int i = 3;i >= 0 ;i--){
     for (int k = 2;k >= 0 ;k--){
    if(block1[i][k] == 1){
      gamestate[cursorY/8+i+1][cursorX-k] = 1;
    }else{
      gamestate[cursorY/8+i+1][cursorX-k] = 0;
      }
     }
   }
   cursorY = 0;
}else{
  oled.setInverse(true);
  cursorY = cursorY+8; 
}

 
delay(500);


}


   
  
 
