/*
 * asteroid.h
 *
 *  Created on: 12. jan. 2023
 *      Author: Casper
 */

#ifndef ASTEROID_H_
#define ASTEROID_H_

#include <types.h>
#include "bullet.h"
#include "led.h"
#include "lcd.h"
#include "gpio.h"
#include "joystick.h"
#include "types.h"

#define NASTEROID 5

void initialize_asteroid(fix_t x , fix_t y ,asteroid_t *a);
void draw_asteroid(asteroid_t *a, uint8_t *buffer); //draw asteroid
void draw_all_asteroids(game_state_t state);
void create_asteroid(uint8_t x, uint8_t y, game_state_t state);
void update_all_asteroid(game_state_t state);


#endif /* ASTEROID_H_ */
