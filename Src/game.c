/*
 * game.c
 *
 *  Created on: 12. jan. 2023
 *      Author: louiss
 */

#include "game.h"

void handle_user_input(game_state_t state) {

	update_spaceship(*state.joystick_input, state.player);

	// if joystick center is pressed then create bullet
	if (*state.joystick_input & JOYSTICK_CENTER) {
		set_led(0b100);
		spaceship_shoot(state.player, state);
	}
	else {
		set_led(0b000);
	}


	if ((*(state.joystick_input) & JOYSTICK_CENTER) && (*(state.joystick_input) & JOYSTICK_LEFT) && (TO_INT(state.player->y) == 0)) {
		*(state.screen) = 3;
	}



}

void handle_bullet_enemy_interaction(game_state_t state) {
	for (uint8_t i = 0; i < NBULLETS; i++) {

		if (!state.bullets[i].active) {
			continue;
		}


		// ENEMY
		for (uint8_t j = 0; j < NENEMY; j++) {

			if (!state.enemies[j].active) {
				continue;
			}

			int16_t dist_x = abs(state.bullets[i].x - (state.enemies[j].x + TO_FIX(2)));
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

		// PLAYER
		fix_t delta_x = abs(state.bullets[i].x - (state.player->x + TO_FIX(3)));
		fix_t delta_y = abs(state.bullets[i].y - state.player->y);

		// NOT TESTED
		if (TO_INT(delta_x) < 3 && TO_INT(delta_y) < 5) {
			create_explotion(state.bullets[i].x, state.bullets[i].y, state);
			state.player->life--;
		}

	}
}

void handle_player_powerup_interaction(game_state_t state) {


	for (uint8_t i = 0; i < NPOWERUPS; i++) {
		if (!state.powerups[i].active) {
			continue;
		}

		fix_t delta_x = abs(state.powerups[i].x - state.player->x);
		fix_t delta_y = abs(state.powerups[i].y - state.player->y);

		if (TO_INT(delta_x) < 5 && TO_INT(delta_y) < 5 ) {
			state.player->state = 1;
			state.powerups[i].active = 0;
			state.player->countdown = TO_COUNT_TIME(10);
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
