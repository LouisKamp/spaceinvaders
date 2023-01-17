/*
 * score.c
 *
 *  Created on: 17. jan. 2023
 *      Author: Casper
 */


#include "score.h"


void draw_score( game_state_t state) {
	uint16_t temp = *state.score;
	char str[30] = {};
	sprintf(str, "Score: %i", temp);
	lcd_write_string(str, 0, 50,  state.buffer);
}

void update_score (game_state_t state) {
	*state.score +=10;
	draw_score(state);

}
