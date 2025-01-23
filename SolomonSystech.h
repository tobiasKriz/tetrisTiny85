/*
 * Tiny4kOLED - Drivers for SSD1306 controlled dot matrix OLED/PLED 128x32 displays
 *
 * Based on ssd1306xled, re-written and extended by Stephen Denne
 * from 2017-04-25 at https://github.com/datacute/Tiny4kOLED
 *
 */

#ifndef SOLOMON_SYSTECH_H
#define SOLOMON_SYSTECH_H

// The SSD1306 is designed by SOLOMON SYSTECH.
// So to demonstrate drawing bitmaps, I chose their logo.

// The oled.bitmap method expects the array it is given, to be in flash memory
// The PROGMEM in the next line is important, it puts the array in flash memory

// Here's the data for the second "SOLOMON SYSTECH" image, 69 pixels wide x 4 pages
const uint8_t solomon_systech_text_bitmap[] PROGMEM = {
  0x78,0xFC,0xFE,0xC6,0xC6,0x9E,0x9C,0x18,0x00,0xE0,0xFC,0xFC,0x0E,0x06,0x0E,0xFC,0xFC,0xF8,0x00,0x00,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0xE0,0xFC,0xFC,0x0E,0x06,0x06,0xFC,0xFC,0xF8,0x00,0x00,0xFE,0xFE,0x3C,0xFC,0xE0,0x00,0xF0,0xFC,0x3C,0xFE,0xFC,0x00,0x00,0xF8,0xFC,0xFE,0x06,0x06,0x1E,0xFC,0xFC,0x00,0x00,0xFE,0xFE,0xFC,0x7C,0xE0,0x00,0xFE,0xFE,
  0x1C,0x1C,0x3C,0x31,0x31,0x3F,0x1F,0x0F,0x00,0x03,0x1F,0x1F,0x38,0x30,0x38,0x3F,0x1F,0x0F,0x00,0x00,0x3F,0x3F,0x38,0x38,0x38,0x38,0x10,0x03,0x1F,0x1F,0x38,0x30,0x30,0x3F,0x1F,0x0F,0x00,0x00,0x3F,0x3F,0x00,0x01,0x1F,0x3F,0x1F,0x00,0x00,0x3F,0x3F,0x00,0x00,0x0F,0x1F,0x3F,0x30,0x30,0x3C,0x1F,0x1F,0x00,0x00,0x3F,0x3F,0x1F,0x00,0x07,0x1F,0x3F,0x3F,
  0x00,0x00,0x00,0x00,0xF0,0xF8,0xD8,0x88,0x18,0x38,0x38,0x20,0x00,0x38,0xF8,0xF8,0xC0,0xC0,0xF8,0x78,0x18,0x00,0xF0,0xF8,0xF8,0x88,0x18,0x38,0x38,0x20,0x00,0x18,0x18,0xF8,0xF8,0xF8,0x18,0x18,0x00,0x00,0xF8,0xF8,0xB8,0x18,0x18,0x18,0x18,0x00,0xE0,0xF8,0xF8,0x18,0x08,0x18,0x78,0x70,0x00,0x00,0xF8,0xF8,0xF8,0x80,0x80,0xF8,0xF8,0xF8,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x39,0x79,0x63,0x63,0x67,0x7F,0x3E,0x1C,0x00,0x00,0x00,0x2F,0x7F,0x7F,0x03,0x00,0x00,0x00,0x38,0x79,0x73,0x63,0x67,0x7F,0x3E,0x1C,0x00,0x00,0x00,0x7F,0x7F,0x7F,0x00,0x00,0x00,0x00,0x7F,0x7F,0x73,0x63,0x63,0x63,0x61,0x00,0x1F,0x3F,0x7F,0x60,0x60,0x70,0x7C,0x3C,0x00,0x00,0x7F,0x7F,0x7F,0x03,0x03,0x7F,0x7F,0x7F,0x00,0x00,0x00
};
const uint8_t zbran[] PROGMEM = {
  0x01, 0xFE, 0xFC, 0x2C, 0x3C, 0x0C, 0x0C, 0x0C
};

/*

Update - I found an online converter that produces the required format: http://www.majer.ch/lcd/adf_bitmap.php
That's much easier than rotating images and transforming text!
So ignore the below.

An online tool was used in the creation of these images.
https://marlinfw.org/tools/u8glib/converter.html  

By rotating the images, the right data bytes were produced but in the wrong layout:

  0x00,0x00,0x1C,0x78, // ...................###...####...
  0x00,0x00,0x1C,0xFC, // ...................###..######..
  0x00,0x00,0x3C,0xFE, // ..................####..#######.
  0x00,0x00,0x31,0xC6, // ..................##...###...##.
  0x39,0xF0,0x31,0xC6, // ..###..#####......##...###...##.
  0x79,0xF8,0x3F,0x9E, // .####..######.....#######..####.
  0x63,0xD8,0x1F,0x9C, // .##...####.##......######..###..
  0x63,0x88,0x0F,0x18, // .##...###...#.......####...##...
  0x67,0x18,0x00,0x00, // .##..###...##...................
etc.

The columns were then converted into rows.

Perhaps an efficient bitmap drawing routine could be written,
that used bitmap data in the same format as u8glib,
but for now, in order to have a really small library,
more work has to go in to preparing the data.

*/

#endif
