

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "types.h"
#include "gpio.h"
#include "led.h"
#include "LUTsin.h"
#include "ansi.h"
#include "lcd.h"
#include "fixed_point.h"
#include "joystick.h"
#include "bullet.h"


void initialize_spaceship(spaceship_t* s);
void draw_spaceship(spaceship_t* s, uint8_t* buffer);
void  draw_spaceship_health( game_state_t state);
void remove_spaceship(spaceship_t* s);
int8_t make_spaceship_weapon(spaceship_t* s);
void start_weapon(spaceship_t* s);
void draw_weapon(spaceship_t* s);
void remove_weapon(spaceship_t* s);
void update_spaceship_weapon(spaceship_t* s);
void update_spaceship(joystick_input_t input, spaceship_t* s);
void spaceship_shoot(spaceship_t* spaceship, game_state_t state);




#endif // SPACESHIP_H

