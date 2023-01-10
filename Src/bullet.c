/*
 * bullet.c
 *
 *  Created on: 10. jan. 2023
 *      Author: Casper
 */

#include "bullet.h"

void initialize_bullet(spaceship_t* s,bullet_t *b) { //initialize the bullets coordinates.
	b->y = s->y+3;
	b->x = s->x;
}
void draw_bullet(joystick_input_t input,bullet_t *b, uint8_t *buffer) { //Draw bullet my press Center on joystick
	if (input & (1 << 4) ) {
		set_led(0b100);
		while (b->y != 122) {
			lcd_write_char(' ', b->x, b->y, buffer);
			b->y++;
			lcd_write_char('-', b->x, b->y, buffer);
		}
	}
}
void remove_bullet (spaceship_t* s,bullet_t *b,uint8_t *buffer) { //Removes bullet so it wont stay on wall.
	if ( 122 == b->y) {
		b->y = s->y+3;
		b->x = s->x;
		set_led(0b001);
	}
}



