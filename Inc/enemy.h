/*
 * enemy.h
 *
 *  Created on: 11. jan. 2023
 *      Author: Casper
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#define NENEMIES 5

#include "led.h"
#include "lcd.h"
#include "gpio.h"
#include "types.h"
#include "fixed_point.h"
#include "interrupts.h"
#include "bullet.h"


void initialize_enemy(fix_t x, fix_t y,fix_t vx, fix_t vy , enemy_t* e);
void draw_enemy(enemy_t enemy, uint8_t* buffer);
void remove_enemy(enemy_t* enemy);
void draw_all_enemies(enemy_t* enemies, uint8_t* buffer);
void update_all_enemies(game_state_t state);
void update_enemy(enemy_t* enemy, game_state_t state);
void create_enemy(fix_t x, fix_t y , game_state_t state);


#endif /* ENEMY_H_ */
