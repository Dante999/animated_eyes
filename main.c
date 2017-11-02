
#include <avr/io.h>
#include "eye.h"
#include <avr/delay.h>
#include "ssd1306.h"


int main()
{



	eye_init();
	//eye_draw_lids();
	//eye_draw_pupil();


	eye_draw(0, 0);


	while(1)
	{

		eye_draw(0, 0);
		_delay_ms(1000);
        ssd1306_clear();
		_delay_ms(50);
	/*
        eye_draw_lids();

        eye_draw_pupil();
        _delay_ms(1000);

        eye_draw_pupil_right();
        _delay_ms(1000);

        eye_draw_pupil();
        _delay_ms(2000);

        eye_draw_pupil_left();
        _delay_ms(2000);


        ssd1306_clear();

    */

	}

}
