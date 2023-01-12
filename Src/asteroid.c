/*
 * asteroid.c
 *
 *  Created on: 12. jan. 2023
 *      Author: Casper
 */

#include "asteroid.h"



void initialize_asteroid(asteroid_t *a) {
	a->x = 20;
	a->y = 120;
	a->vx = 5;
	a->vy = 2;
	a->active =1;
}
void draw_asteroid(asteroid_t *a, uint8_t *buffer) {
	a->y -= a->vy;
	lcd_write_char('O', a->x, a->y, buffer);
}
void remove_asteroid (asteroid_t *a,bullet_t *b,uint8_t *buffer) {
	if ((b->y == a->y) && (b->x == a->x)){
	}
}

