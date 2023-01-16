/*
 * asteroid.c
 *
 *  Created on: 12. jan. 2023
 *      Author: Casper
 */

#include "asteroid.h"

void initialize_asteroid(fix_t x, fix_t y, asteroid_t *a) {
	a->x = x;
	a->y = y;
	a->vx = TO_FIX(0);
	a->vy = TO_FIX(-1);
	a->active = 1;
}

void draw_asteroid(asteroid_t *a, uint8_t *buffer) {
	if (a->active) {
		int32_t mat[7][6] = { {0,1,1,1,1,0}, {1,0,1,1,1,1}, {1,1,1,1,0,1}, {1,1,1,1,1,1},{1,1,0,1,1,1},{0,1,1,1,1,0}};
		lcd_write_custom(6, 6, mat, TO_INT(a->x), TO_INT(a->y), buffer);
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

void draw_all_asteroids(game_state_t state) {
	for (uint8_t i = 0; i < NASTEROID; i++) {
		draw_asteroid(&state.asteroid[i], state.buffer);
	}
}

void update_all_asteroid(game_state_t state) {
	for (uint8_t i = 0; i < NASTEROID; i++) {
		update_asteroid(&state.asteroid[i]);
	}
}


