/*
 * game.c
 *
 *  Created on: 12. jan. 2023
 *      Author: louiss
 */

#include "game.h"

void handle_user_input(game_state_t state) {

	update_spaceship_postition(*state.joystick_input, state.player);

	// if joystick center is pressed then create bullet
	if (*state.joystick_input & JOYSTICK_CENTER) {
		set_led(0b100);
		spaceship_shoot(state.player, state);
	}
	else {
		set_led(0b000);
	}
}

void handle_bullet_enemy_interaction(game_state_t state) {
	for (uint8_t i = 0; i < NBULLETS; i++) {

		if (!state.bullets[i].active) {
			continue;
		}

		for (uint8_t j = 0; j < NENEMY; j++) {

			if (!state.enemies[j].active) {
				continue;
			}

			int16_t dist_x = abs(state.bullets[i].x - state.enemies[j].x - TO_FIX(2));
			int16_t dist_y = abs(state.bullets[i].y - state.enemies[j].y);
			if ((dist_x < TO_FIX(5)) && (dist_y < TO_FIX(2))) {
				// bullet hit
				remove_bullet(&state.bullets[i]);
				create_explotion(state.bullets[i].x, state.bullets[i].y, state);
				state.enemies[j].life -= 1;

				if (state.enemies[j].life == 0) {
					remove_enemy(&state.enemies[j]);
					create_explotion(state.enemies[j].x, state.enemies[j].y, state);
					create_explotion(state.enemies[j].x+TO_FIX(6), state.enemies[j].y, state);
				}
			}
		}
	}
}


void handle_bullet_asteroid_interaction(game_state_t state) {
	for (uint8_t i = 0; i < NBULLETS; i++) {

		if (!state.bullets[i].active) {
			continue;
		}

		for (uint8_t j = 0; j < NASTEROID; j++) {

			if (!state.asteroid[j].active) {
				continue;
			}

			int16_t dist_x = state.bullets[i].x - (state.asteroid[j].x + TO_FIX(3));
			int16_t dist_y = abs(state.bullets[i].y - state.asteroid[j].y);

			if ((abs(dist_x) < TO_FIX(3)) && (dist_y < TO_FIX(5))) {
				// bullet hit
				remove_bullet(&state.bullets[i]);
				create_explotion(state.bullets[i].x, state.bullets[i].y, state);
			}


			if ((abs(dist_x) < TO_FIX(10)) && (dist_y < TO_FIX(5))) {
				// gravity
				state.bullets[i].vx -= FIX_MULT(FIX_DIVD(TO_FIX(8), dist_x), 0x3);
			}

		}
	}
}
