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
		for (uint8_t j = 0; j < NENEMY; j++) {
			int8_t dist_x = abs(state.bullets[i].x - state.enemies[j].x - 3);
			int8_t dist_y = abs(state.bullets[i].y - state.enemies[j].y);
			if ((dist_x) < 5 && dist_y < 5) {
				// bullet hit
				remove_bullet(&state.bullets[i]);
			}
		}
	}
}

