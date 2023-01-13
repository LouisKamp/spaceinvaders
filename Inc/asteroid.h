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

#define NASTEROID 1

void initialize_asteroid(asteroid_t *a);
void draw_asteroid(asteroid_t *a, uint8_t *buffer); //draw asteroid
void remove_asteroid (asteroid_t *a,bullet_t *b,uint8_t *buffer);


#endif /* ASTEROID_H_ */
