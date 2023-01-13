/*
 * MakeScreens.h
 *
 *  Created on: 10. jan. 2023
 *      Author: Casper
 */

#ifndef SCREENS_H_
#define SCREENS_H_


#include <types.h>
#include "lcd.h"
#include "spaceship.h"
#include "bullet.h"
#include "enemy.h"
#include "asteroid.h"
#include "game.h"



void make_start_screen(char* str, game_state_t state);
void make_help_screen(char* str, game_state_t state);
void help_info_screen(game_state_t state);
void make_game_screen(game_state_t state);

#endif /* SCREENS_H_ */