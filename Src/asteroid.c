/*
 * asteroid.c
 *
 *  Created on: 12. jan. 2023
 *      Author: Casper
 */

#include "asteroid.h"

void initialize_asteroid(fix_t x, fix_t y, fix_t vx, fix_t vy, asteroid_t* a) {
	a->x = TO_FIX(x);
	a->y = TO_FIX(y);
	a->vx = TO_FIX(vx);
	a->vy = (vy);
	a->life = 8;
	a->active = 1;
}

void draw_asteroid(asteroid_t asteroid, uint8_t* buffer) {
	if (asteroid.active) {
		int32_t mat[7][6] = { {0,1,1,1,1,0}, {1,0,1,1,1,1}, {1,1,1,1,0,1}, {1,1,1,1,1,1},{1,1,0,1,1,1},{0,1,1,1,1,0} };
		lcd_write_custom(6, 6, mat, TO_INT(asteroid.x), TO_INT(asteroid.y), buffer);
	}
}

void update_asteroid(asteroid_t* a,game_state_t state) {
	if (a->active) {

		a->x += a->vx;
		a->y += a->vy;
		if (TO_INT(a->y) < 0 || TO_INT(a->y) > 127 || TO_INT(a->x) > 40 || TO_INT(a->x) < 0) {
			// deactivate if out
			a->active = 0;
			state.player->life--;
		}
	}
}

void create_asteroid(fix_t x, fix_t y, game_state_t state) {
	asteroid_t* new_asteroid = &state.asteroids[*state.num_asteroid % NASTEROIDS];
	fix_t vy = (-0b10000) - ((*state.score)/2);
	fix_t vx = 0;
	*state.num_asteroid += 1;
	initialize_asteroid(x, y, vx, vy , new_asteroid);
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
		update_asteroid(&state.asteroids[i],state);
	}
}


