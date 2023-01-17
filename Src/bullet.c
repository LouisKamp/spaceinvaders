/*
 * bullet.c
 *
 *  Created on: 10. jan. 2023
 *      Author: Casper
 */

#include "bullet.h"

void initialize_bullet(fix_t x, fix_t y, fix_t vx, fix_t vy, bullet_t *b) { //initialize the bullets coordinates.
	b->y = y;
	b->x = x;
	b->vx = vx;
	b->vy = vy;
	b->active = 1;
}
void draw_bullet(bullet_t *b, uint8_t *buffer) { //Draw bullet my press Center on joystick
	if (b->active) {
		lcd_write_pixel(TO_INT(b->x), TO_INT(b->y), buffer);
	}
}

void remove_bullet(bullet_t * b) {
	b->active = 0;
}


void update_bullet(bullet_t * b) {
	if (b->active) {
		b->x += b->vx;
		b->y += b->vy;

		// check if bullet are out of picture
		if (TO_INT(b->y) > 127 || TO_INT(b->y) < 0 || TO_INT(b->x) < 0 || TO_INT(b->x) > 32) {
			// deactivate if out
			b->active = 0;
		}
	}
}

void create_bullet(fix_t x, fix_t y, fix_t vx, fix_t vy, game_state_t state) {
	bullet_t * new_bullet = &state.bullets[*state.num_bullet % NBULLETS];
	*state.num_bullet += 1;
	initialize_bullet(x,y,vx,vy, new_bullet);
}
void draw_all_bullets(game_state_t state) {
	for (uint8_t i = 0; i < NBULLETS; i++) {
		draw_bullet(&state.bullets[i], state.buffer);
	}
}
void update_all_bullets(game_state_t state) {
	for (uint8_t i = 0; i < NBULLETS; i++) {
		update_bullet(&state.bullets[i]);
	}
}



