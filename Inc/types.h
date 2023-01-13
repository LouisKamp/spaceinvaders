/*
 * types.h
 *
 *  Created on: 10. jan. 2023
 *      Author: louiss
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <stdio.h>

typedef uint8_t joystick_input_t;

typedef struct {
    int32_t x, y;
} vector_t;


typedef uint32_t fix_16_16_t;
typedef uint32_t fix_2_14_t;


 typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t active;
    uint8_t vx;
    uint8_t vy;
} bullet_t;

typedef struct {
	uint8_t x;
	uint8_t y;
	uint8_t active;
	uint8_t vx;
	uint8_t vy;
} asteroid_t;

typedef struct {
    fix_16_16_t x;
    fix_16_16_t y;
    fix_16_16_t vx;
    fix_16_16_t vy;
    uint8_t life;
    uint8_t weapon;
} spaceship_t;

typedef struct {
	uint8_t x;
	uint8_t y;
	uint8_t vx;
	uint8_t vy;
	uint8_t life;
	uint8_t active;
} enemy_t;

typedef struct {

	bullet_t * bullets;
	uint8_t *num_bullet;

	enemy_t * enemies;
	uint8_t * num_enemy;

	asteroid_t * asteroid;
	uint8_t *num_asteroid;

	spaceship_t * player;

	uint8_t * screen;

	uint8_t * buffer;

	joystick_input_t * joystick_input;
} game_state_t;


#endif /* TYPES_H_ */
