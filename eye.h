#ifndef _EYE_H
#define _EYE_H

#include <avr/io.h>

void eye_init();
void eye_draw(uint8_t x_offset, uint8_t y_offset);
void eye_draw_lids();
void eye_draw_pupil();
void eye_draw_pupil_right();
void eye_draw_pupil_left();
void eye_draw_mid_lids();

#endif
