

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

#endif // SPACESHIP_H

