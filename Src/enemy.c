/*
 * enemy.c
 *
 *  Created on: 11. jan. 2023
 *      Author: Casper
 */


#include "enemy.h"

#define ENEMY_SHOOT_COUTDOWN_TIME TO_COUNT_TIME(3)

void initialize_enemy(fix_t x, fix_t y, enemy_t* enemy) { //initialize the enemy coordinates.
	enemy->y = TO_FIX(y);
	enemy->x = TO_FIX(x);
	enemy->vy = -0b10000; // -0.5 in FIX_T
	enemy->vx = TO_FIX(0);
	enemy->active = 1;
	enemy->life = 5;
	enemy->countdown_shoot = ENEMY_SHOOT_COUTDOWN_TIME;
}

void update_all_enemies(game_state_t state) {
	for (uint8_t i = 0; i < NENEMIES; i++) {
		update_enemy(&state.enemies[i], state);
	}
}

void draw_enemy(enemy_t enemy, uint8_t* buffer) {
	if (enemy.active) {
		int32_t mat[8][6] = { {0,0,0,1,0,0}, {0,0,1,1,1,0}, {0,1,0,1,1,1}, {1,0,0,1,0,1}, {1,0,0,1,1,1}, {0,1,0,1,1,1}, {0,0,1,1,1,0},{0,0,0,1,0,0} };
		lcd_write_custom(8, 6, mat, TO_INT(enemy.x), TO_INT(enemy.y), buffer);
	}
}

void draw_all_enemies(enemy_t* enemies, uint8_t* buffer) {
	for (uint8_t i = 0; i < NENEMIES; i++) {
		draw_enemy(enemies[i], buffer);
	}
}

void update_enemy(enemy_t* enemy, game_state_t state) {
	if (enemy->active) {

		enemy->x += enemy->vx;
		enemy->y += enemy->vy;
		if (TO_INT(enemy->y) < 0 || TO_INT(enemy->y) > 127 || TO_INT(enemy->x) > 40 || TO_INT(enemy->x) < 0) {
			// deactivate if out
			enemy->active = 0;
		}

		enemy->countdown_shoot -= 1;
		if (enemy->countdown_shoot == 0) {
			create_bullet((enemy->x + TO_FIX(3)), (enemy->y - TO_FIX(5)), TO_FIX(0), TO_FIX(-1), state);
			enemy->countdown_shoot = ENEMY_SHOOT_COUTDOWN_TIME;
		}
	}
}

void remove_enemy(enemy_t* enemy) {
	enemy->active = 0;
}

void create_enemy(fix_t x, fix_t y, game_state_t state) {
	enemy_t* new_enemy = &state.enemies[*state.num_enemy % NENEMIES];

	*state.num_enemy += 1;
	initialize_enemy(x, y, new_enemy);
}










