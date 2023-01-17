/*
 * game.c
 *
 *  Created on: 12. jan. 2023
 *      Author: louiss
 */

#include "game.h"


void clear_game_state(game_state_t state) {

	*state.screen = GAME_SCREEN;
	*state.score = 0;
	*state.time = 0;
	*state.num_enemy = 0;
	*state.num_explosions = 0;
	*state.num_bullet = 0;
	*state.num_asteroid = 0;
	*state.num_powerups = 0;

	initialize_spaceship(state.player);

	for (int32_t a = 0; a < NPOWERUPS; a++) {
		state.powerups[a].active = 0;
	}


	for (int32_t b = 0; b < NBULLETS; b++) {
		state.bullets[b].active = 0;
	}


	for (int32_t c = 0; c < NASTEROIDS; c++) {
		state.asteroids[c].active = 0;
	}


	for (int32_t d = 0; d < NENEMIES; d++) {
		state.enemies[d].active = 0;
	}


	for (int32_t e = 0; e < NEXPLOSIONS; e++) {
		state.explosions[e].active = 0;
	}

}

void handle_user_input(game_state_t state) {

	update_spaceship(*state.accelerometer_input, state.player);

	// if joystick center is pressed then create bullet
	if (*state.joystick_input & JOYSTICK_CENTER) {
		set_led(0b100);
		spaceship_shoot(*state.player, state);
	} else {
		set_led(0b000);
	}

	// BOSS KEY
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
		for (uint8_t j = 0; j < NENEMIES; j++) {

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
					create_explotion(state.enemies[j].x + TO_FIX(6), state.enemies[j].y, state);
					add_score(10, state);
				}
			}
		}

		// PLAYER
		fix_t delta_x = abs(state.bullets[i].x - (state.player->x + TO_FIX(3)));
		fix_t delta_y = abs(state.bullets[i].y - (state.player->y + TO_FIX(5)));

		// NOT TESTED
		if (TO_INT(delta_x) < 3 && TO_INT(delta_y) < 5) {
			create_explotion(state.bullets[i].x, state.bullets[i].y, state);
			remove_bullet(&state.bullets[i]);
			// create function for this that includes handle for when die
			state.player->life--;
		}

	}
}

void handle_player_powerup_interaction(game_state_t state) {


	for (uint8_t i = 0; i < NPOWERUPS; i++) {
		if (!state.powerups[i].active) {
			continue;
		}

		fix_t delta_x = abs((state.player->x + TO_FIX(3)) - (state.powerups[i].x + TO_FIX(4)));
		fix_t delta_y = abs((state.player->y + TO_FIX(5)) - (state.powerups[i].y + TO_FIX(4)));

		if (TO_INT(delta_x) < 4 && TO_INT(delta_y) < 4) {
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

		for (uint8_t j = 0; j < NASTEROIDS; j++) {

			if (!state.asteroids[j].active) {
				continue;
			}

			int16_t dist_x = state.bullets[i].x - (state.asteroids[j].x + TO_FIX(3));
			int16_t dist_y = abs(state.bullets[i].y - state.asteroids[j].y);

			// test if gravity applies
			if ((abs(dist_x) < TO_FIX(10)) && (dist_y < TO_FIX(5))) {
				// update velocity to create gravity
				state.bullets[i].vx -= FIX_MULT(FIX_DIVD(TO_FIX(8), dist_x), 0x3);
			}

			if ((abs(dist_x) < TO_FIX(3)) && (dist_y < TO_FIX(5))) {
				// bullet hit
				remove_bullet(&state.bullets[i]);
				create_explotion(state.bullets[i].x, state.bullets[i].y, state);
				state.asteroids[j].life -= 1;

				if (state.asteroids[j].life == 0) {
					remove_asteoroid(&state.asteroids[j]);
					create_explotion(state.asteroids[j].x, state.asteroids[j].y, state);
					create_explotion(state.asteroids[j].x + TO_FIX(6), state.asteroids[j].y, state);
					add_score(10,state);
				}
			}
		}
	}
}

void handle_player_asteroid_interaction(game_state_t state) {
	for (uint8_t i = 0; i < NASTEROIDS; i++) {
		if (!state.asteroids[i].active) {
			continue;
		}

		fix_t delta_x = abs((state.player->x + TO_FIX(3)) - (state.asteroids[i].x + TO_FIX(4)));
		fix_t delta_y = abs((state.player->y + TO_FIX(5)) - (state.asteroids[i].y + TO_FIX(4)));

		if (TO_INT(delta_x) < 4 && TO_INT(delta_y) < 4) {
			create_explotion(state.player->x, state.player->y, state);
			state.asteroids[i].active = 0;
			state.player->life -= 3;
		}

	}
}
