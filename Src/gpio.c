



#include "gpio.h"



// init pins for LED and on board joystick
void init_pins() {

	// SETUP
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
	RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
	RCC->AHBENR |= RCC_AHBPeriph_GPIOC;


	// JOYSTICK


	// PC0 = RIGHT
	uint8_t pin_right = 0;
	GPIOC->MODER &= ~(0x00000003 << (pin_right * 2)); // Clear mode register GPIOA->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (pin_right * 2)); // Clear push/pull register GPIOA->PUPDR |= (0x00000002 << (0 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)
	// uint16_t val_right = GPIOC->IDR & (0x0001 << pin_right); //Read from pin PC0


	// PA4 = UP
	uint8_t pin_up = 4;
	GPIOA->MODER &= ~(0x00000003 << (pin_up * 2));
	GPIOA->PUPDR &= ~(0x00000003 << (pin_up * 2));
	// uint16_t val_up = GPIOA->IDR & (0x0001 << pin_up);

	// PB5 = CENTER
	uint8_t pin_center = 5;
	GPIOB->MODER &= ~(0x00000003 << (pin_center * 2));
	GPIOB->PUPDR &= ~(0x00000003 << (pin_center * 2));
	// uint16_t val_center = GPIOB->IDR & (0x0001 << pin_center);

	// PC1 = LEFT
	uint8_t pin_left = 1;
	GPIOC->MODER &= ~(0x00000003 << (pin_left * 2));
	GPIOC->PUPDR &= ~(0x00000003 << (pin_left * 2));
	// uint16_t val_left = GPIOC->IDR & (0x0001 << pin_left);

	// PB0 = DOWN
	uint8_t pin_down = 0;
	GPIOB->MODER &= ~(0x00000003 << (pin_down * 2));
	GPIOB->PUPDR &= ~(0x00000003 << (pin_down * 2));
	// uint16_t val_down = GPIOB->IDR & (0x0001 << pin_down);


	// LED
	// PB4 = RED
	uint8_t pin_red = 4;

	GPIOB->OSPEEDR &= ~(0x00000003 << (pin_red * 2)); // Clear speed register
	GPIOB->OSPEEDR |= (0x00000002 << (pin_red * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)

	GPIOB->OTYPER &= ~(0x0001 << (pin_red * 1)); // Clear output type register
	GPIOB->OTYPER |= (0x0000 << (pin_red * 1));  // Set output type register (0x00 -Push pull, 0x01 - Open drain)

	GPIOB->MODER &= ~(0x00000003 << (pin_red * 2)); // Clear mode register
	GPIOB->MODER |= (0x00000001 << (pin_red * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out);



	// PC7 = GREEN
	uint8_t pin_green = 7;

	GPIOC->OSPEEDR &= ~(0x00000003 << (pin_green * 2));
	GPIOC->OSPEEDR |= (0x00000002 << (pin_green * 2));

	GPIOC->OTYPER &= ~(0x0001 << (pin_green * 1));
	GPIOC->OTYPER |= (0x0000 << (pin_green * 1));

	GPIOC->MODER &= ~(0x00000003 << (pin_green * 2));
	GPIOC->MODER |= (0x00000001 << (pin_green * 2));



	// PA9 = BLUE
	uint8_t pin_blue = 9;

	GPIOA->OSPEEDR &= ~(0x00000003 << (pin_blue * 2));
	GPIOA->OSPEEDR |= (0x00000002 << (pin_blue * 2));

	GPIOA->OTYPER &= ~(0x0001 << (pin_blue * 1));
	GPIOA->OTYPER |= (0x0000 << (pin_blue * 1));

	GPIOA->MODER &= ~(0x00000003 << (pin_blue * 2));
	GPIOA->MODER |= (0x00000001 << (pin_blue * 2));
}

