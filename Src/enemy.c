/*
 * enemy.c
 *
 *  Created on: 11. jan. 2023
 *      Author: Casper
 */


#include "enemy.h"

void initialize_enemy(enemy_t *e) { //initialize the enemy coordinates.
	e->y = TO_FIX(50);
	e->x = TO_FIX(20);
	e->vy = TO_FIX(-1);
	e->vx = TO_FIX(-1);
	e->active = 1;
	e->life = 1;
}


void update_all_enemies(game_state_t state) {
	for (uint8_t i = 0; i < NENEMY; i++) {
		update_enemy(&state.enemies[i]);
	}
}

void draw_enemy(enemy_t *e, uint8_t *buffer) {
	if (e->active) {
		lcd_write_char('C', TO_INT(e->x), TO_INT(e->y), buffer);
	}
}

void draw_all_enemies(game_state_t state) {
	for (uint8_t i = 0; i< NENEMY; i++) {
		draw_enemy(&state.enemies[i], state.buffer);
	}
}

void update_enemy(enemy_t * enemy) {
	if (enemy->active) {
		enemy->x += enemy->vx;
		enemy->y += enemy->vy;
	}
}
void remove_enemy(enemy_t * enemy) {
	enemy->active = 0;
}






