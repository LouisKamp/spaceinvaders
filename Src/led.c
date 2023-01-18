/*
 * led.c
 *
 *  Created on: 5. jan. 2023
 *      Author: louiss
 */

#include "led.h"


 // returns a color_t where the bits are 2=R 0=G 0=B
void set_led(color_t color) {

	uint8_t pin_red = 4;
	uint8_t pin_green = 7;
	uint8_t pin_blue = 9;

	color = ~color;
	if (color & (1 << 2)) {
		GPIOB->ODR |= (0x0001 << pin_red);
	}
	else {
		GPIOB->ODR &= ~(0x0001 << pin_red);
	}

	if (color & (1 << 1)) {
		GPIOC->ODR |= (0x0001 << pin_green);
	}
	else {
		GPIOC->ODR &= ~(0x0001 << pin_green);
	}

	if (color & (1 << 0)) {
		GPIOA->ODR |= (0x0001 << pin_blue);
	}
	else {
		GPIOA->ODR &= ~(0x0001 << pin_blue);
	}
}

