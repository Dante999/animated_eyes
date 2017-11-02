#include "eye.h"
#include <avr/io.h>
#include "ssd1306.h"


uint8_t sprite_eye_l0[] = {0x00, 0x00, 0x80, 0xC0, 0xF0, 0xF8, 0xFC, 0xFE};
uint8_t sprite_eye_l1[] = {0xF0, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_l2[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_l3[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_l4[] = {0x0F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_l5[] = {0x00, 0x00, 0x01, 0x03, 0x0F, 0x1F, 0x3F, 0x7F};

uint8_t sprite_eye_r0[] = {0xFE, 0xFC, 0xF8, 0xF0, 0xC0, 0x80, 0x00, 0x00};
uint8_t sprite_eye_r1[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF0};
uint8_t sprite_eye_r2[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_r3[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_r4[] = {0x0F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_r5[] = {0x00, 0x00, 0x01, 0x03, 0x0F, 0x1F, 0x3F, 0x7F};

uint8_t sprite_eye_c0[] = {0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE};
uint8_t sprite_eye_c1[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_c2[] = {0xFF, 0x03, 0x01, 0x00, 0x00, 0x01, 0x03, 0xFF};
uint8_t sprite_eye_c3[] = {0xFF, 0xC0, 0x80, 0x00, 0x00, 0x80, 0xC0, 0xFF};
uint8_t sprite_eye_c4[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_c5[] = {0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F};


uint8_t sprite_white_block[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t sprite_black_block[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_half_black_block[] = {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80};

uint8_t sprite_eye_top_left[] = {0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x0F, 0x07, 0x07};
uint8_t sprite_eye_mid_left[] = {0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t sprite_eye_bot_left[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF0, 0xE0, 0xE0};

uint8_t sprite_eye_top_right[] = {0x07, 0x07, 0x0F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_mid_right[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_bot_right[] = {0xE0, 0xE0, 0xF0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF};
// --------
uint8_t sprite_eye_top_left1[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x03};
uint8_t sprite_eye_mid_left1[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00};
uint8_t sprite_eye_bot_left1[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

uint8_t sprite_eye_top_right1[] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x1F};
uint8_t sprite_eye_mid_right1[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0};
uint8_t sprite_eye_bot_right1[] = {0xFE, 0xFC, 0xFC, 0xFC, 0xFC, 0xFE, 0xFF, 0xFF};
// --------
uint8_t sprite_eye_top_left2[] = {0xFF, 0x1F, 0x0F, 0x07, 0x07, 0x07, 0x07, 0x0F};
uint8_t sprite_eye_mid_left2[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t sprite_eye_bot_left2[] = {0xFF, 0xF8, 0xF0, 0xE0, 0xE0, 0xE0, 0xE0, 0xF0};

uint8_t sprite_eye_top_right2[] = {0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_mid_right2[] = {0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t sprite_eye_bot_right2[] = {0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};


uint8_t sprite_diagonal_y0[]  = {0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0, 0xE0};

uint8_t sprite_lid_right1[] = {0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00};
uint8_t sprite_lid_right2[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x01};
uint8_t sprite_lid_right3[] = {0x7F, 0x3F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00};


void eye_init()
{
    ssd1306_init();

}



eye_draw(uint8_t x_offset, uint8_t y_offset)
{

    ssd1306_draw_sprite(9, 1, sprite_eye_c0);
    ssd1306_draw_sprite(9, 2, sprite_eye_c1);
    ssd1306_draw_sprite(9, 3, sprite_eye_c2);
    ssd1306_draw_sprite(9, 4, sprite_eye_c3);
    ssd1306_draw_sprite(9, 5, sprite_eye_c4);
    ssd1306_draw_sprite(9, 6, sprite_eye_c5);

    ssd1306_draw_sprite(8, 1, sprite_eye_l0 );
    ssd1306_draw_sprite(8, 2, sprite_eye_l1 );
    ssd1306_draw_sprite(8, 3, sprite_eye_l2 );
    ssd1306_draw_sprite(8, 4, sprite_eye_l3 );
    ssd1306_draw_sprite(8, 5, sprite_eye_l4 );
    ssd1306_draw_sprite(8, 6, sprite_eye_l5 );

    ssd1306_draw_sprite_mirrored_vertical(10, 1, sprite_eye_l0 );
    ssd1306_draw_sprite_mirrored_vertical(10, 2, sprite_eye_l1 );
    ssd1306_draw_sprite_mirrored_vertical(10, 3, sprite_eye_l2 );
    ssd1306_draw_sprite_mirrored_vertical(10, 4, sprite_eye_l3 );
    ssd1306_draw_sprite_mirrored_vertical(10, 5, sprite_eye_l4 );
    ssd1306_draw_sprite_mirrored_vertical(10, 6, sprite_eye_l5 );
    /*
    ssd1306_draw_sprite_mirroed_horizontal(8-x_offset, 4-y_offset, sprite_eye_l2 );
    ssd1306_draw_sprite_mirroed_horizontal(8-x_offset, 5-y_offset, sprite_eye_l1 );
    ssd1306_draw_sprite_mirroed_horizontal(8-x_offset, 6-y_offset, sprite_eye_l0 );
*/





}
















void eye_draw_mid_lids()
{
    ssd1306_draw_sprite_with_offset(2, 6, sprite_white_block, 0, 0);

    ssd1306_draw_sprite_with_offset(3, 5, sprite_white_block, 0, 0);
    ssd1306_draw_sprite_with_offset(3, 6, sprite_diagonal_y0, 0, -1);

    ssd1306_draw_sprite_with_offset(4, 5, sprite_white_block, 0, 0);
    ssd1306_draw_sprite_with_offset(4, 6, sprite_diagonal_y0, 0, 2);

    ssd1306_draw_sprite_with_offset(5, 5, sprite_white_block, 0, 0);
    ssd1306_draw_sprite_with_offset(5, 6, sprite_diagonal_y0, 0, 5);

    ssd1306_draw_sprite_with_offset(6, 4, sprite_white_block, 0, 0);
    ssd1306_draw_sprite_with_offset(6, 5, sprite_diagonal_y0, 0, 0);
    //ssd1306_draw_sprite_with_offset(6, 6, sprite_black_block, 0, 0);

    ssd1306_draw_sprite_with_offset(7, 4, sprite_white_block, 0, 0);
    ssd1306_draw_sprite_with_offset(7, 5, sprite_diagonal_y0, 0, 3);
    //ssd1306_draw_sprite_with_offset(7, 6, sprite_black_block, 0, 0);

    ssd1306_draw_sprite_with_offset(8, 3, sprite_white_block, 0, 0);
    ssd1306_draw_sprite_with_offset(8, 4, sprite_diagonal_y0, 0, -2);
    ssd1306_draw_sprite_with_offset(8, 5, sprite_diagonal_y0, 0, 6);
    //ssd1306_draw_sprite_with_offset(8, 6, sprite_black_block, 0, 0);

    //
    ssd1306_draw_sprite_with_offset(9, 3, sprite_diagonal_y0, 0, 1);
    ssd1306_draw_sprite_with_offset(9, 4, sprite_black_block, 0, 0);
    ssd1306_draw_sprite_with_offset(9, 5, sprite_black_block, 0, 0);
    //ssd1306_draw_sprite_with_offset(9, 6, sprite_black_block, 0, 0);

    ssd1306_draw_sprite_with_offset(10, 3, sprite_diagonal_y0, 0, 4);
    ssd1306_draw_sprite_with_offset(10, 4, sprite_black_block, 0, 0);
    ssd1306_draw_sprite_with_offset(10, 5, sprite_black_block, 0, 0);
   // ssd1306_draw_sprite_with_offset(10, 6, sprite_black_block, 0, 0);

    ssd1306_draw_sprite_with_offset(11, 2, sprite_diagonal_y0, 0, -1);
    ssd1306_draw_sprite_with_offset(11, 3, sprite_black_block, 0, 0);
    ssd1306_draw_sprite_with_offset(11, 4, sprite_black_block, 0, 0);
    ssd1306_draw_sprite_with_offset(11, 5, sprite_black_block, 0, 0);
    //ssd1306_draw_sprite_with_offset(11, 6, sprite_black_block, 0, 0);

    ssd1306_draw_sprite_with_offset(12, 2, sprite_diagonal_y0, 0, 2);
    ssd1306_draw_sprite_with_offset(12, 3, sprite_black_block, 0, 0);
    ssd1306_draw_sprite_with_offset(12, 4, sprite_black_block, 0, 0);
    ssd1306_draw_sprite_with_offset(12, 5, sprite_black_block, 0, 0);
    //ssd1306_draw_sprite_with_offset(12, 6, sprite_lid_right1, 0, 0);

    ssd1306_draw_sprite_with_offset(13, 2, sprite_diagonal_y0, 0, 5);
    ssd1306_draw_sprite_with_offset(13, 3, sprite_black_block, 0, 0);
    ssd1306_draw_sprite_with_offset(13, 4, sprite_lid_right2, 0, 0);
    ssd1306_draw_sprite_with_offset(13, 5, sprite_lid_right3, 0, 0);
}




void eye_draw_lids()
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
}


void eye_draw_pupil()
{
   ssd1306_draw_sprite_with_offset( 9, 4, sprite_eye_top_left, 0, 0);
   ssd1306_draw_sprite_with_offset( 9, 5, sprite_eye_mid_left, 0, 0);
   ssd1306_draw_sprite_with_offset( 9, 6, sprite_eye_bot_left, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 4, sprite_eye_top_right, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 5, sprite_eye_mid_right, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 6, sprite_eye_bot_right, 0, 0);
}

void eye_draw_pupil_right()
{
   ssd1306_draw_sprite_with_offset( 9, 4, sprite_eye_top_left1, 0, 0);
   ssd1306_draw_sprite_with_offset( 9, 5, sprite_eye_mid_left1, 0, 0);
   ssd1306_draw_sprite_with_offset( 9, 6, sprite_eye_bot_left1, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 4, sprite_eye_top_right1, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 5, sprite_eye_mid_right1, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 6, sprite_eye_bot_right1, 0, 0);
}

void eye_draw_pupil_left()
{
   ssd1306_draw_sprite_with_offset( 9, 4, sprite_eye_top_left2, 0, 0);
   ssd1306_draw_sprite_with_offset( 9, 5, sprite_eye_mid_left2, 0, 0);
   ssd1306_draw_sprite_with_offset( 9, 6, sprite_eye_bot_left2, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 4, sprite_eye_top_right2, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 5, sprite_eye_mid_right2, 0, 0);
   ssd1306_draw_sprite_with_offset(10, 6, sprite_eye_bot_right2, 0, 0);
}
