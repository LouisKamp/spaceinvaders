/*
 * asteroid.c
 *
 *  Created on: 12. jan. 2023
 *      Author: Casper
 */

#include "asteroid.h"

void initialize_asteroid(uint8_t x, uint8_t y, asteroid_t *a) {
	a->x = 20;
	a->y = 120;
	a->vx = 5;
	a->vy = 2;
	a->active =1;
}
void draw_asteroid(asteroid_t *a, uint8_t *buffer) {
	if (a->active) {
		lcd_write_char('O', a->x, a->y, buffer);
	}
}
void update_asteroid(asteroid_t * a) {
	if (a->active) {
		a->x += a->vx;
		a->y += a->vy;

		// check if asteorid are out of picture
		if (a->y < 0 ) {
			// deactivate if out
			a->active = 0;
		}
	}
}
void create_asteroid(uint8_t x, uint8_t y, game_state_t state) {
	asteroid_t * new_asteroid = &state.asteroid[*state.num_asteroid % NASTEROID];
	*state.num_asteroid += 1;
	initialize_asteroid(x,y, new_asteroid);
}

void draw_all_asteroid(game_state_t state) {
	for (uint8_t i = 0; i < NASTEROID; i++) {
		draw_asteroid(&state.asteroid[i], state.buffer);
	}
}

void update_all_asteroid(game_state_t state) {
	for (uint8_t i = 0; i < NASTEROID; i++) {
		update_asteroid(&state.asteroid[i]);
	}
}


