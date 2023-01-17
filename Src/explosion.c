/*
 * explotion.c
 *
 *  Created on: 13. jan. 2023
 *      Author: louiss
 */


#include "explosion.h"

void init_explotion(fix_t x, fix_t y, explotion_t* explotion) {
	explotion->active = 1;
	explotion->state = 0;
	explotion->x = x;
	explotion->y = y;
}

void remove_explotion(explotion_t* explotion) {
	explotion->active = 0;
}

void draw_all_explosions(explotion_t* explosions, uint8_t* buffer) {
	for (uint16_t i = 0; i < NEXPLOSIONS; i++) {
		draw_explotion(explosions[i], buffer);
	}
}

void update_all_explosions(game_state_t state) {
	for (uint16_t i = 0; i < NEXPLOSIONS; i++) {
		update_explotion(&state.explosions[i]);
	}
}

void create_explotion(fix_t x, fix_t y, game_state_t state) {
	explotion_t* new_explotion = &state.explosions[*state.num_explosions % NEXPLOSIONS];
	*state.num_explosions += 1;

	init_explotion(x, y, new_explotion);
}

void draw_explotion(explotion_t explotion, uint8_t* buffer) {

	uint16_t x = TO_INT(explotion.x);
	uint16_t y = TO_INT(explotion.y);

	if (explotion.active) {
		if (explotion.state == 0) {
			lcd_write_pixel(x, y, buffer);
		}

		if (explotion.state == 1) {
			// top
			lcd_write_pixel(x - 1, y - 1, buffer);
			lcd_write_pixel(x - 1, y, buffer);
			lcd_write_pixel(x - 1, y + 1, buffer);

			//middle
			lcd_write_pixel(x, y - 1, buffer);
			lcd_write_pixel(x, y + 1, buffer);

			//bottom
			lcd_write_pixel(x + 1, y - 1, buffer);
			lcd_write_pixel(x + 1, y, buffer);
			lcd_write_pixel(x + 1, y + 1, buffer);

		}

		if (explotion.state == 2) {
			// top
			lcd_write_pixel(x - 2, y - 2, buffer);
			lcd_write_pixel(x - 2, y, buffer);
			lcd_write_pixel(x - 2, y + 2, buffer);

			//middle
			lcd_write_pixel(x, y - 2, buffer);
			lcd_write_pixel(x, y + 2, buffer);

			//bottom
			lcd_write_pixel(x + 2, y - 2, buffer);
			lcd_write_pixel(x + 2, y, buffer);
			lcd_write_pixel(x + 2, y + 2, buffer);

		}

		if (explotion.state == 3) {
			// top
			lcd_write_pixel(x - 3, y - 3, buffer);
			lcd_write_pixel(x - 3, y, buffer);
			lcd_write_pixel(x - 3, y + 3, buffer);

			//middle
			lcd_write_pixel(x, y - 3, buffer);
			lcd_write_pixel(x, y + 2, buffer);

			//bottom
			lcd_write_pixel(x + 3, y - 3, buffer);
			lcd_write_pixel(x + 3, y, buffer);
			lcd_write_pixel(x + 3, y + 3, buffer);
		}
	}
}

void update_explotion(explotion_t* explotion) {
	explotion->state = (explotion->state + 1) % 5;

	if (explotion->state == 4) {
		remove_explotion(explotion);
	}
}



