
#include "ssd1306.h"
#include "i2cmaster.h"
#include <avr/io.h>

#define SSD1306_ADDR 0x78

#define SSD1306_LCDWIDTH            128
#define SSD1306_LCDHEIGHT           64
#define SSD1306_SETCONTRAST         0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON        0xA5
#define SSD1306_NORMALDISPLAY       0xA6
#define SSD1306_INVERTDISPLAY       0xA7
#define SSD1306_DISPLAYOFF          0xAE
#define SSD1306_DISPLAYON           0xAF
#define SSD1306_SETDISPLAYOFFSET    0xD3
#define SSD1306_SETCOMPINS          0xDA
#define SSD1306_SETVCOMDETECT       0xDB
#define SSD1306_SETDISPLAYCLOCKDIV  0xD5
#define SSD1306_SETPRECHARGE        0xD9
#define SSD1306_SETMULTIPLEX        0xA8
#define SSD1306_SETLOWCOLUMN        0x00
#define SSD1306_SETHIGHCOLUMN       0x10
#define SSD1306_SETSTARTLINE        0x40
#define SSD1306_MEMORYMODE          0x20
#define SSD1306_COLUMNADDR          0x21
#define SSD1306_PAGEADDR            0x22
#define SSD1306_COMSCANINC          0xC0
#define SSD1306_COMSCANDEC          0xC8
#define SSD1306_SEGREMAP            0xA0
#define SSD1306_CHARGEPUMP          0x8D
#define SSD1306_EXTERNALVCC         0x1
#define SSD1306_SWITCHCAPVCC        0x2

// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A

uint8_t sprite_black_block[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_half_black_block[] = {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80};

uint8_t sprite_eye_top[] = {0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 0x07};
uint8_t sprite_eye_bot[] = {0xE0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xE0};

uint8_t sprite_eye_top_left[] = {0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x0F, 0x07, 0x07};
uint8_t sprite_eye_mid_left[] = {0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t sprite_eye_bot_left[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF0, 0xE0, 0xE0};

uint8_t sprite_eye_top_right[] = {0x07, 0x07, 0x0F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_mid_right[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_bot_right[] = {0xE0, 0xE0, 0xF0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF};

uint8_t sprite_diagonal_y0[]  = {0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0, 0xE0};

uint8_t sprite_lid_right1[] = {0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00};
uint8_t sprite_lid_right2[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x01};
uint8_t sprite_lid_right3[] = {0x7F, 0x3F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00};






void ssd1306_init()
{
   i2c_init();
   
       /* write 0x75 to eeprom address 0x05 (Byte Write) */

   
 // Init sequence for 128x64 OLED module
    ssd1306_command(SSD1306_DISPLAYOFF);                    // 0xAE

    ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
    ssd1306_command(0x80);                 // the suggested ratio 0x80
   
    ssd1306_command(SSD1306_SETMULTIPLEX);                  // 0xA8
    //ssd1306_command(0x3F);
    ssd1306_command(64-1);
   
    ssd1306_command(SSD1306_SETDISPLAYOFFSET);              // 0xD3
    ssd1306_command(0x0);                                   // no offset
   
    ssd1306_command(SSD1306_SETSTARTLINE);// | 0x0);        // line #0
   
    ssd1306_command(SSD1306_CHARGEPUMP);                    // 0x8D
    ssd1306_command(0x14);                                  // using internal VCC
   
    ssd1306_command(SSD1306_MEMORYMODE);                    // 0x20
    ssd1306_command(0x00);                                  // 0x00 horizontal addressing
   
    ssd1306_command(SSD1306_SEGREMAP | 0x1);                // rotate screen 180
   
    ssd1306_command(SSD1306_COMSCANDEC);                    // rotate screen 180
   
    ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
    ssd1306_command(0x12);
   
    ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
    ssd1306_command(0xCF);
   
    ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xd9
    ssd1306_command(0xF1);
   
    ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
    ssd1306_command(0x40);
   
    ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
   
    ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6
 
   ssd1306_command(SSD1306_DEACTIVATE_SCROLL);
 
    ssd1306_command(SSD1306_DISPLAYON);                     //switch on OLED     
    
   ssd1306_clear();
   
   ssd1306_test();
}



void ssd1306_clear()
{
   ssd1306_command(SSD1306_COLUMNADDR);
   ssd1306_command(0);
   ssd1306_command(SSD1306_LCDWIDTH-1);

   ssd1306_command(SSD1306_PAGEADDR);
   ssd1306_command(0);
   ssd1306_command(7);
   
   
   
   
   uint8_t column = 0;
   uint8_t line   = 0;
   
   for( column=0; column < SSD1306_LCDWIDTH; column++ )
   {
      
      for( line=0; line < 8; line++ )
      {
         ssd1306_data(0x00);
      }
      
      
   }
   
   
}


uint8_t *ssd1306_sprite_y_offset(uint8_t y_offset, uint8_t *sprite)
{
   uint8_t i;
   
   uint8_t mask = 0xFF;
   
   mask = mask >> y_offset; 
   mask = ~mask;
   
   
   for( i=0; i < 8; i++)
   {
      sprite[i] = (sprite[i] >> y_offset);
      sprite[i] |= mask;
   }
   
   return sprite;   
}



void ssd1306_test()
{
   
   ssd1306_draw_sprite_with_offset(2, 6, sprite_diagonal_y0, 0, 4);
     
   ssd1306_draw_sprite_with_offset(3, 5, sprite_diagonal_y0, 0, -1);
   ssd1306_draw_sprite_with_offset(3, 6, sprite_black_block, 0, 0);

   ssd1306_draw_sprite_with_offset(4, 5, sprite_diagonal_y0, 0, 2);
   ssd1306_draw_sprite_with_offset(4, 6, sprite_black_block, 0, 0);
   
   ssd1306_draw_sprite_with_offset(5, 5, sprite_diagonal_y0, 0, 5);
   ssd1306_draw_sprite_with_offset(5, 6, sprite_black_block, 0, 0);
   
   ssd1306_draw_sprite_with_offset(6, 4, sprite_diagonal_y0, 0, 0);
   ssd1306_draw_sprite_with_offset(6, 5, sprite_black_block, 0, 0);
   ssd1306_draw_sprite_with_offset(6, 6, sprite_black_block, 0, 0);
   
   ssd1306_draw_sprite_with_offset(7, 4, sprite_diagonal_y0, 0, 3);
   ssd1306_draw_sprite_with_offset(7, 5, sprite_black_block, 0, 0);
   ssd1306_draw_sprite_with_offset(7, 6, sprite_black_block, 0, 0);
   
   ssd1306_draw_sprite_with_offset(8, 3, sprite_diagonal_y0, 0, -2);
   ssd1306_draw_sprite_with_offset(8, 4, sprite_diagonal_y0, 0, 6);
   ssd1306_draw_sprite_with_offset(8, 5, sprite_black_block, 0, 0);
   ssd1306_draw_sprite_with_offset(8, 6, sprite_black_block, 0, 0);
    
   ssd1306_draw_sprite_with_offset(9, 3, sprite_diagonal_y0, 0, 1);
   ssd1306_draw_sprite_with_offset(9, 4, sprite_black_block, 0, 0);
   ssd1306_draw_sprite_with_offset(9, 5, sprite_black_block, 0, 0);
   ssd1306_draw_sprite_with_offset(9, 6, sprite_black_block, 0, 0);
   
   ssd1306_draw_sprite_with_offset(10, 3, sprite_diagonal_y0, 0, 4);
   ssd1306_draw_sprite_with_offset(10, 4, sprite_black_block, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 5, sprite_black_block, 0, 0);   
   ssd1306_draw_sprite_with_offset(10, 6, sprite_black_block, 0, 0);   
 
   ssd1306_draw_sprite_with_offset(11, 2, sprite_diagonal_y0, 0, -1);
   ssd1306_draw_sprite_with_offset(11, 3, sprite_black_block, 0, 0);
   ssd1306_draw_sprite_with_offset(11, 4, sprite_black_block, 0, 0);
   ssd1306_draw_sprite_with_offset(11, 5, sprite_black_block, 0, 0);   
   ssd1306_draw_sprite_with_offset(11, 6, sprite_black_block, 0, 0); 
   
   ssd1306_draw_sprite_with_offset(12, 2, sprite_diagonal_y0, 0, 2);
   ssd1306_draw_sprite_with_offset(12, 3, sprite_black_block, 0, 0);
   ssd1306_draw_sprite_with_offset(12, 4, sprite_black_block, 0, 0);
   ssd1306_draw_sprite_with_offset(12, 5, sprite_black_block, 0, 0);   
   ssd1306_draw_sprite_with_offset(12, 6, sprite_lid_right1, 0, 0); 
   
   ssd1306_draw_sprite_with_offset(13, 2, sprite_diagonal_y0, 0, 5);
   ssd1306_draw_sprite_with_offset(13, 3, sprite_black_block, 0, 0);
   ssd1306_draw_sprite_with_offset(13, 4, sprite_lid_right2, 0, 0);
   ssd1306_draw_sprite_with_offset(13, 5, sprite_lid_right3, 0, 0);   
   
   ssd1306_draw_eye(0,0);
   
}


void ssd1306_draw_eye(uint8_t x_offset, uint8_t y_offset)
{
   ssd1306_draw_sprite_with_offset( 9, 4, sprite_eye_top_left, 0, 0);
   ssd1306_draw_sprite_with_offset( 9, 5, sprite_eye_mid_left, 0, 0);
   ssd1306_draw_sprite_with_offset( 9, 6, sprite_eye_bot_left, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 4, sprite_eye_top_right, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 5, sprite_eye_mid_right, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 6, sprite_eye_bot_right, 0, 0);
}


void ssd1306_draw_pixel(uint8_t x, uint8_t y)
{

   ssd1306_command(SSD1306_COLUMNADDR);
   ssd1306_command(x);
   ssd1306_command(x+1);

   ssd1306_command(SSD1306_PAGEADDR);
   ssd1306_command(y);
   ssd1306_command(y+1);

   

// ssd1306_command(0x01);
   ssd1306_data(0b10101010);

}


void ssd1306_command(uint8_t cmd)
{
   i2c_start(SSD1306_ADDR+I2C_WRITE);       // set device address and write mode
   i2c_write(0x00); // This is Command
   i2c_write(cmd);
   i2c_stop();
}


void ssd1306_draw_sprite_with_offset(uint8_t x_grid, uint8_t y_grid, uint8_t *sprite, int8_t x_offset, int8_t y_offset)
{
   
   uint8_t i;
   uint8_t buffer[8];
   uint8_t mask = 0xFF;
   
   memcpy(buffer, sprite, 8);
   
   
   if( y_offset > 0)
   {
      mask = (mask >> y_offset); 
      mask = ~mask;

      for( i=0; i < 8; i++)
      {
            buffer[i] = (buffer[i] >> y_offset);
            buffer[i] |= mask;   
      }
   }
   else
   {
      y_offset *= (-1);
      
      mask = (mask << y_offset); 
      mask = ~mask;

      for( i=0; i < 8; i++)
      {
            buffer[i] = (buffer[i] << y_offset);
            //buffer[i] |= mask;   
      }
   }
   
   ssd1306_draw_sprite(x_grid, y_grid, buffer);
   
   
   
}

void ssd1306_draw_sprite(uint8_t x_grid, uint8_t y_grid, uint8_t *sprite)
{
   if( x_grid > 16 )
   {
      x_grid = 16;
   }
   if( y_grid > 7 )
   {
      y_grid = 7;
   }
   
   uint8_t x = x_grid * 8;
   uint8_t y = y_grid;
   
   ssd1306_command(SSD1306_COLUMNADDR);
   ssd1306_command(x);
   ssd1306_command(x+7);

   ssd1306_command(SSD1306_PAGEADDR);
   ssd1306_command(y);
   ssd1306_command(y);
   
   uint8_t i=0;
   
   for(i=0; i<8; i++)
   {
      ssd1306_data(sprite[i]);
   }
   
   
   
}


void ssd1306_data(uint8_t data)
{
   i2c_start(SSD1306_ADDR+I2C_WRITE);       // set device address and write mode
   i2c_write(0X40); // This byte is DATA
   i2c_write(data);
   i2c_stop();
}
