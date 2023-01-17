/*
 * score.h
 *
 *  Created on: 17. jan. 2023
 *      Author: Casper
 */

#ifndef SCORE_H_
#define SCORE_H_

#include "types.h"
#include "lcd.h"
void draw_score(uint32_t score, uint8_t* buffer);
void add_score(uint8_t amount, game_state_t state);

#endif /* SCORE_H_ */
