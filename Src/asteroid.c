/*
 * asteroid.c
 *
 *  Created on: 12. jan. 2023
 *      Author: Casper
 */

#include "asteroid.h"

void initialize_asteroid(fix_t x, fix_t y, asteroid_t* a) {
	a->x = TO_FIX(x);
	a->y = TO_FIX(y);
	a->vx = TO_FIX(0);
	a->vy = TO_FIX(-1);
	a->life = 8;
	a->active = 1;
}

void draw_asteroid(asteroid_t asteroid, uint8_t* buffer) {
	if (asteroid.active) {
		int32_t mat[7][6] = { {0,1,1,1,1,0}, {1,0,1,1,1,1}, {1,1,1,1,0,1}, {1,1,1,1,1,1},{1,1,0,1,1,1},{0,1,1,1,1,0} };
		lcd_write_custom(6, 6, mat, TO_INT(asteroid.x), TO_INT(asteroid.y), buffer);
	}
}

void update_asteroid(asteroid_t* a) {
	if (a->active) {
		a->x += a->vx;
		a->y += a->vy;

		// check if asteorid are out of picture
		if (a->y < 0) {
			// deactivate if out
			a->active = 0;
		}
	}
}

void create_asteroid(fix_t x, fix_t y, game_state_t state) {
	asteroid_t* new_asteroid = &state.asteroids[*state.num_asteroid % NASTEROIDS];
	*state.num_asteroid += 1;
	initialize_asteroid(x, y, new_asteroid);
}

void draw_all_asteroids(asteroid_t* asteroids, uint8_t* buffer) {
	for (uint8_t i = 0; i < NASTEROIDS; i++) {
		draw_asteroid(asteroids[i], buffer);
	}
}

void remove_asteoroid(asteroid_t* asteroid) {
	asteroid->active = 0;
}

void update_all_asteroids(game_state_t state) {
	for (uint8_t i = 0; i < NASTEROIDS; i++) {
		update_asteroid(&state.asteroids[i]);
	}
}


