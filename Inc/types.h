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


typedef int16_t fix_t; // fixed point format: 11.5
typedef int32_t fix_2_14_t; // fixed point format: 2.14
typedef int32_t fix_16_16_t; // fixed point format: 2.14

typedef struct {
	fix_t x;
	fix_t y;
	uint8_t state;
	uint8_t active;
} explotion_t;


typedef struct {
	fix_t x;
	fix_t y;
	fix_t vx;
	fix_t vy;
	uint8_t active;
} bullet_t;

typedef struct {
	fix_t x;
	fix_t y;
	fix_t vx;
	fix_t vy;
	uint8_t active;
} asteroid_t;

typedef struct {
	fix_t x;
	fix_t y;
	fix_t vx;
	fix_t vy;
	uint8_t life;
	uint8_t weapon;
} spaceship_t;

typedef struct {
	fix_t x;
	fix_t y;
	fix_t vx;
	fix_t vy;
	uint8_t life;
	uint8_t active;
} enemy_t;

typedef struct {

	explotion_t * explosions;
	uint8_t * num_explosions;

	bullet_t* bullets;
	uint8_t* num_bullet;

	enemy_t* enemies;
	uint8_t* num_enemy;

	asteroid_t* asteroid;
	uint8_t* num_asteroid;

	spaceship_t* player;

	uint8_t* screen;

	uint8_t* buffer;

	joystick_input_t* joystick_input;
} game_state_t;


#endif /* TYPES_H_ */
