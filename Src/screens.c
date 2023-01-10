/*
 * MakeScreens.c
 *
 *  Created on: 10. jan. 2023
 *      Author: Casper
 */

#include "screens.h"

void make_start_screen(char* str, uint8_t * buffer, uint8_t * game_state) {


	joystick_input_t input = read_joystick();

	// check if joystick is down
	if (input & (0x01<<4)) {
		*game_state = 1;
	}

	int n=1;
	while( n <= 54 ) {
		lcd_write_string("_",8,32+n,buffer);
		lcd_write_string("_",21,32+n,buffer);
		n++;
	}
	lcd_write_string("*",1,120, buffer);
	lcd_write_string("*",1,1, buffer);
	lcd_write_string("*",23,1, buffer);
	lcd_write_string("*",23,120, buffer);
	lcd_write_string("SPACE2000",0,40, buffer);
	lcd_write_string(str,16,20, buffer);
}
void make_help_screen(char* str, uint8_t * buffer, uint8_t * game_state) {
	lcd_write_string(str,1,38, buffer);
}

void help_info_screen(uint8_t * buffer, uint8_t * game_state) {
	lcd_write_string("Shoot on center",1,3, buffer);
	lcd_write_string("Move Down ",20,3, buffer);
	lcd_push_buffer(buffer);
}

void make_game_screen(spaceship_t * s, uint8_t * buffer, uint8_t * game_state) {
	joystick_input_t input = read_joystick();
	update_spaceship_postition(input, s);
	draw_spaceship(s, buffer);
}




