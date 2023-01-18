/*
 * powerup.h
 *
 *  Created on: 16. jan. 2023
 *      Author: louiss
 */

#ifndef POWERUP_H_
#define POWERUP_H_

#include "stm32f30x_conf.h"
#include "types.h"
#include "fixed_point.h"

#define NPOWERUPS 50

void initialize_powerup(fix_t x, fix_t y, powerup_t* powerup);
void draw_powerup(powerup_t powerup, uint8_t* buffer);
void create_powerup(fix_t x, fix_t y, game_state_t state);
void draw_all_powerups(powerup_t* powerups, uint8_t* buffer);
void remove_powerup(powerup_t * powerup);


#endif /* POWERUP_H_ */
