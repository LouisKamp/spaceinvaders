


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

joystick_input_t read_accelerometer() {
	int8_t tilt = (I2C_Read(0b10011001, 0x03, 0, 1) >> 2) & (0b111);

	uint8_t result = 0;

	result |= (tilt == 0b101) << 0; // UP
	result |= (tilt == 0b110) << 1; // DOWN
	result |= (tilt == 0b001) << 2; // LEFT
	result |= (tilt == 0b010) << 3; // RIGHT
	return result;
}

// tests if input has specific key active
uint8_t is_input(joystick_input_t input, uint8_t test_key) {
	return input & test_key;
}

