/*
 * MakeScreens.c
 *
 *  Created on: 10. jan. 2023
 *      Author: Casper
 */

#include "screens.h"

void make_start_screen(char* str, game_state_t state) {
	// check if joystick is down
	if (*(state.joystick_input) & (0x01<<4)) {
		*(state.screen) = 1;
	}

	int n=1;
	while( n <= 54 ) {
		lcd_write_string("_",8,32+n,state.buffer);
		lcd_write_string("_",21,32+n,state.buffer);
		n++;
	}
	lcd_write_string("*",1,120, state.buffer);
	lcd_write_string("*",1,1, state.buffer);
	lcd_write_string("*",23,1, state.buffer);
	lcd_write_string("*",23,120, state.buffer);
	lcd_write_string("SPACE2000",0,40, state.buffer);
	lcd_write_string(str,16,20, state.buffer);
}
void make_help_screen(char* str, game_state_t state) {
	lcd_write_string(str,1,38, state.buffer);
}

void help_info_screen(game_state_t state) {
	lcd_write_string("Shoot on center",1,3, state.buffer);
	lcd_write_string("Move Down ",20,3, state.buffer);
}

void make_game_screen(game_state_t state) {
	update_spaceship_postition(*state.joystick_input, state.player);
	draw_spaceship(state.player, state.buffer);

	for (uint8_t i = 0; i < NBULLETS; i++) {
		draw_bullet(&state.bullets[i], state.buffer);
	}

	if (*state.joystick_input & (0x01 << 4)) { // if joystick center is pressed
		initialize_bullet(state.player, &state.bullets[0]);
	}
}




