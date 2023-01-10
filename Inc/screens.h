/*
 * MakeScreens.h
 *
 *  Created on: 10. jan. 2023
 *      Author: Casper
 */

#ifndef SCREENS_H_
#define SCREENS_H_


#include "lcd.h"
#include "spaceship.h"

void make_start_screen(char* str, uint8_t * buffer, uint8_t * game_state);
void make_help_screen(char* str, uint8_t * buffer, uint8_t * game_state);
void help_info_screen(uint8_t * buffer, uint8_t * game_state);
void make_game_screen(spaceship_t * s,uint8_t * buffer, uint8_t * game_state);

#endif /* SCREENS_H_ */
