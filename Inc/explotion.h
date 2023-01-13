/*
 * explotion.h
 *
 *  Created on: 13. jan. 2023
 *      Author: louiss
 */

#ifndef EXPLOTION_H_
#define EXPLOTION_H_

#define NEXPLOTIONS 50

#include "types.h"
#include "lcd.h"
#include "fixed_point.h"

void init_explotion(fix_t x, fix_t y,explotion_t * explotion);
void remove_explotion(explotion_t * explotion);
void draw_explotion(explotion_t * explotion, uint8_t *buffer);
void draw_all_explotions(game_state_t state);
void update_all_explotions(game_state_t state) ;
void create_explotion(fix_t x, fix_t y, game_state_t state);
void update_explotion(explotion_t * explotion);

#endif /* EXPLOTION_H_ */
