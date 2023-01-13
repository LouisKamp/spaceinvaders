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
		spaceship_shoot(state.player, state);
	}




}
