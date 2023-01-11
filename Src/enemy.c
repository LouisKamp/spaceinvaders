/*
 * enemy.c
 *
 *  Created on: 11. jan. 2023
 *      Author: Casper
 */


#include "enemy.h"

void initialize_enemy(enemy_t *e) { //initialize the enemy coordinates.
	e->y = 20;
	e->x = 20 ;
	e->active = 1;
	e->vy =2;
	e->vx = 2;
	e->life = 1;
}
void draw_enemy(enemy_t *e, uint8_t *buffer) { //Draw enemy
	e->y+=e->vy;
	lcd_write_char('C', e->x, e->y, buffer);
}

void enemy_death( enemy_t *e,bullet_t *b, uint8_t *buffer) {
	if (e->y == b->y && e->x == b->y) {
		lcd_write_char(' ', e->x, e->y, buffer);

	}
}




