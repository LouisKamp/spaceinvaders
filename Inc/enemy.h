/*
 * enemy.h
 *
 *  Created on: 11. jan. 2023
 *      Author: Casper
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#define NENEMY 5

#include "led.h"
#include "lcd.h"
#include "gpio.h"
#include "types.h"



void initialize_enemy(enemy_t *e);
void draw_enemy(enemy_t *e, uint8_t *buffer);
void draw_all_enemies(game_state_t state);
void updates_all_enemies(game_state_t state);

#endif /* ENEMY_H_ */