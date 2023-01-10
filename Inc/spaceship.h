

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "gpio.h"
#include "led.h"
#include "LUTsin.h"
#include "ansi.h"
#include "lcd.h"
#include "fixed_point.h"

#define ESC 0x1B
#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )

typedef struct {
    fix_16_16_t x;
    fix_16_16_t y;
    fix_16_16_t vx;
    fix_16_16_t vy;
    uint8_t life;
    uint8_t weapon;
} spaceship_t;


void initialize_spaceship(spaceship_t* s);
void draw_spaceship(spaceship_t* s, uint8_t* buffer);
void remove_spaceship(spaceship_t* s);
int8_t make_spaceship_weapon(spaceship_t* s);
void start_weapon(spaceship_t* s);
void draw_weapon(spaceship_t* s);
void remove_weapon(spaceship_t* s);
void update_spaceship_weapon(spaceship_t* s);
void update_ship_right(spaceship_t* s);
void update_ship_left(spaceship_t* s);
//int8_t read_joystick(spaceship_t* s);




#endif // SPACESHIP_H

