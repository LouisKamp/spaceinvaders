/*
 * enemy.c
 *
 *  Created on: 11. jan. 2023
 *      Author: Casper
 */


#include "enemy.h"

void initialize_enemy(fix_t x , fix_t y ,enemy_t *e) { //initialize the enemy coordinates.
	e->y = TO_FIX(y);
	e->x = TO_FIX(x);
	e->vy = TO_FIX(-1);
	e->vx = TO_FIX(0);
	e->active = 1;
	e->life = 5;
}

void update_all_enemies(game_state_t state) {
	for (uint8_t i = 0; i < NENEMY; i++) {
		update_enemy(&state.enemies[i]);
	}
}

void draw_enemy(enemy_t *e, uint8_t *buffer) {
	if (e->active) {
		//lcd_write_char('C', TO_INT(e->x), TO_INT(e->y), buffer);
		int32_t mat[8][6] = { {0,0,0,1,0,0}, {0,0,1,1,1,0}, {0,1,0,1,1,1}, {1,0,0,1,0,1}, {1,0,0,1,1,1}, {0,1,0,1,1,1}, {0,0,1,1,1,0},{0,0,0,1,0,0}};
		lcd_write_custom(8, 6, mat, TO_INT(e->x), TO_INT(e->y), buffer);
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
		if (TO_INT(enemy->y) < 0 ||  TO_INT(enemy->y) > 127 || TO_INT(enemy->x) > 40 || TO_INT(enemy->x) < 0 ) {
			// deactivate if out
			enemy->active = 0;
		}

	}
}
void remove_enemy(enemy_t * enemy) {
	enemy->active = 0;
}

void create_enemy ( game_state_t state) {
	if (*state.time % TO_COUNT_TIME(10) == 0 ) {
		fix_t x = rand() % 20 + 1 ;
		fix_t y = rand() % 80 + 40;
		enemy_t * new_enemies = &state.enemies[*state.num_enemy % NENEMY];
		*state.num_enemy += 1;
		initialize_enemy(x,y ,new_enemies);

	}

}










