/*
 * bullet.c
 *
 *  Created on: 10. jan. 2023
 *      Author: Casper
 */

#include "bullet.h"

void initialize_bullet(fix_t x, fix_t y, fix_t vx, fix_t vy, bullet_t* bullet) {
	//initialize the bullets coordinates.
	bullet->y = y;
	bullet->x = x;
	bullet->vx = vx;
	bullet->vy = vy;
	bullet->active = 1;
}


void draw_bullet(bullet_t bullet, uint8_t* buffer) {
	//Draw bullet my press Center on joystick
	if (bullet.active) {
		lcd_write_pixel(TO_INT(bullet.x), TO_INT(bullet.y), buffer);
	}
}

void remove_bullet(bullet_t* bullet) {
	bullet->active = 0;
}


void update_bullet(bullet_t* bullet) {
	if (bullet->active) {
		bullet->x += bullet->vx;
		bullet->y += bullet->vy;

		// check if bullet are out of picture
		if (127 < TO_INT(bullet->y) || TO_INT(bullet->y) < 0 || TO_INT(bullet->x) < 0 || 31 < TO_INT(bullet->x)) {
			// deactivate if out
			remove_bullet(bullet);
		}
	}
}

void create_bullet(fix_t x, fix_t y, fix_t vx, fix_t vy, game_state_t state) {
	bullet_t* new_bullet = &state.bullets[*state.num_bullet % NBULLETS];
	*state.num_bullet += 1;
	initialize_bullet(x, y, vx, vy, new_bullet);
}


void draw_all_bullets(bullet_t* bullets, uint8_t* buffer) {
	for (uint8_t i = 0; i < NBULLETS; i++) {
		draw_bullet(bullets[i], buffer);
	}
}


void update_all_bullets(game_state_t state) {
	for (uint8_t i = 0; i < NBULLETS; i++) {
		update_bullet(&state.bullets[i]);
	}
}



