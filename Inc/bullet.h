/*
 * bullet.h
 *
 *  Created on: 10. jan. 2023
 *      Author: Casper
 */

#ifndef BULLET_H_
#define BULLET_H_

#define NBULLETS 50

#include "spaceship.h"
#include "led.h"
#include "lcd.h"
#include "gpio.h"
#include "joystick.h"

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t active;
} bullet_t;

void initialize_bullet(spaceship_t* s,bullet_t *b);
void draw_bullet(bullet_t * b, uint8_t *buffer); //Update bullet
void remove_bullet (spaceship_t* s,bullet_t *b,uint8_t *buffer);


#endif /* BULLET_H_ */
