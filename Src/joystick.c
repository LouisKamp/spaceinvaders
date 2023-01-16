


#include "joystick.h"


joystick_input_t read_joystick() {

	uint8_t result = 0;

	uint8_t pin_right = 0;
	uint8_t pin_up = 4;
	uint8_t pin_center = 5;
	uint8_t pin_left = 1;
	uint8_t pin_down = 0;
	uint8_t spawn = 2;

	uint16_t val_right = GPIOC->IDR & (0x0001 << pin_right);
	uint16_t val_up = GPIOA->IDR & (0x0001 << pin_up);
	uint16_t val_center = GPIOB->IDR & (0x0001 << pin_center);
	uint16_t val_left = GPIOC->IDR & (0x0001 << pin_left);
	uint16_t val_down = GPIOB->IDR & (0x0001 << pin_down);

	uint16_t val_spawn_check = GPIOC->IDR & (0x0001 << spawn); //Read from pin PC2

	result |= (val_up > 0) << 0;
	result |= (val_down > 0) << 1;
	result |= (val_left > 0) << 2;
	result |= (val_right > 0) << 3;
	result |= (val_center > 0) << 4;

	result |= (val_spawn_check > 0) << 2;


	return result;

}


// slave address for accelerometer: 1001100

color_t input_to_color(joystick_input_t joystick_input) {

	uint8_t color = 0;

	// UP
	if (joystick_input & JOYSTICK_UP) {
		color |= (0x0001 << 0);
	}

	// LEFT
	if (joystick_input & JOYSTICK_LEFT) {
		color |= (0x0001 << 1);
	}

	// RIGHT
	if (joystick_input & JOYSTICK_RIGHT) {
		color |= (0x0001 << 2);
	}


	return color;

}

