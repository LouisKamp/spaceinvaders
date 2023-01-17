/*
 * score.c
 *
 *  Created on: 17. jan. 2023
 *      Author: Casper
 */


#include "score.h"


void draw_score(uint32_t scrore, uint8_t* buffer) {
	char str[30] = {};
	sprintf(str, "Score: %i", scrore);
	lcd_write_string(str, 0, 50, buffer);
}

void add_score (uint8_t amount, game_state_t state) {
	*state.score += amount;
}
