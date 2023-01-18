/*
 * MakeScreens.c
 *
 *  Created on: 10. jan. 2023
 *      Author: Casper
 */

#include "screens.h"


void set_screen(uint8_t* screen, uint8_t screen_number) {
	(*screen) = screen_number;
}

void make_start_screen(char* str, game_state_t state) {
	// check if joystick is down
	if (*(state.joystick_input) & JOYSTICK_CENTER) {
		set_screen(state.screen, GAME_SCREEN);
	}

	if (*(state.joystick_input) & JOYSTICK_RIGHT) {
		set_screen(state.screen, HELP_SCREEN);
	}

	int n = 1;
	while (n <= 54) {
		lcd_write_string("_", 8, 32 + n, state.buffer);
		n++;
	}

	lcd_write_string("Help press ->", 24, 35, state.buffer);


	lcd_write_string("*", 1, 120, state.buffer);
	lcd_write_string("*", 1, 1, state.buffer);
	lcd_write_string("*", 23, 1, state.buffer);
	lcd_write_string("*", 23, 120, state.buffer);
	lcd_write_string("SPACE2000", 0, 40, state.buffer);
	lcd_write_string(str, 16, 20, state.buffer);
}
void make_help_screen(game_state_t state) {

	if (*(state.joystick_input) & JOYSTICK_LEFT) {
		set_screen(state.screen, START_SCREEN);
	}

	lcd_write_string("<- Back", 0, 3, state.buffer);
	lcd_write_string("Shoot on center", 9 - 2, 3, state.buffer);
	lcd_write_string("Tilt device to move ", 17 - 2, 3, state.buffer);
	lcd_write_string("HINT: gravity + asteroids", 25 - 2, 3, state.buffer);
}

void make_boss_screen(game_state_t state) {

	if (*(state.joystick_input) & JOYSTICK_RIGHT) {
		set_screen(state.screen, GAME_SCREEN);
	}


	uint16_t vals = 0;
	I2C_Read(0b10010001, 0x00, &vals, 2); // read temp from sensor


	uint16_t temp1 = vals >> 5;
	uint16_t temp2 = temp1 & ~(0b1 << 10);
	fix_t temp3 = TO_FIX(temp2);
	fix_t temp4 = FIX_DIVD(temp3, TO_FIX(8));

	char str[20] = {};

	sprintf(str, "Temp: %i degC", TO_INT(temp4));

	lcd_write_string(str, 0, 3, state.buffer);
	lcd_write_string("Uncertainty: +- 5 degC", 9, 3, state.buffer);
}

void make_gameover_screen(game_state_t state) {


	if (*state.joystick_input & JOYSTICK_CENTER) {
		clear_game_state(state);
	}

	lcd_write_string("Game over!", 0, 40, state.buffer);
	char str[10] = {};
	sprintf(str, "Score: %i", *state.score);

	lcd_write_string(str, 10, 45, state.buffer);
	lcd_write_string("Press down to play again", 20, 5, state.buffer);
}

void make_game_screen(game_state_t state) {
	// DRAW
	draw_all_enemies(state.enemies, state.buffer);
	draw_all_bullets(state.bullets, state.buffer);
	draw_all_explosions(state.explosions, state.buffer);
	draw_all_asteroids(state.asteroids, state.buffer);
	draw_all_powerups(state.powerups, state.buffer);
	draw_score(*state.score, state.buffer);
	draw_spaceship(*state.player, state.buffer);
	draw_spaceship_health(*state.player, state.buffer);


	// UPDATE
	update_all_bullets(state);
	update_all_enemies(state);
	update_all_explosions(state);
	update_all_asteroids(state);

	// CREATE
	handle_create_events(state);


	// HANDLE INTERACTIONS
	handle_bullet_enemy_interaction(state);
	handle_bullet_asteroid_interaction(state);
	handle_player_powerup_interaction(state);
	handle_player_asteroid_interaction(state);

	// USER INPUT
	handle_user_input(state);

	// check if gameover
	if (state.player->life <= 0) {
		set_screen(state.screen, GAMEOVER_SCREEN);
	}


}






