#ifndef _SSD1306_H
#define _SSD1306_H

#include <avr/io.h>






void ssd1306_init();
void ssd1306_draw_eye(uint8_t x_offset, uint8_t y_offset);
void ssd1306_command(uint8_t cmd);
void ssd1306_data(uint8_t data);
void ssd1306_clear();
void ssd1306_test();
void ssd1306_draw_pixel(uint8_t x, uint8_t y);
void ssd1306_draw_sprite(uint8_t x_grid, uint8_t y_grid, uint8_t *sprite);
void ssd1306_draw_sprite_with_offset(uint8_t x_grid, uint8_t y_grid, uint8_t *sprite, int8_t x_offset, int8_t y_offset);
#endif
