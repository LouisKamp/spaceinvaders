



#include "gpio.h"



// init pins for LED and on board joystick
void init_pins() {

	// SETUP
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
	RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
	RCC->AHBENR |= RCC_AHBPeriph_GPIOC;

	// PB8 for I2C
	//PB9 for I2C

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

	// PC1 = LEFT/Shoot on Joystick SW2
	uint8_t pin_left = 1;
	GPIOC->MODER &= ~(0x00000003 << (pin_left * 2));
	GPIOC->PUPDR &= ~(0x00000003 << (pin_left * 2));
	// uint16_t val_left = GPIOC->IDR & (0x0001 << pin_left);

	// PB0 = DOWN
	uint8_t pin_down = 0;
	GPIOB->MODER &= ~(0x00000003 << (pin_down * 2));
	GPIOB->PUPDR &= ~(0x00000003 << (pin_down * 2));
	// uint16_t val_down = GPIOB->IDR & (0x0001 << pin_down);

	// PC2 = Shoot/SW2
	uint8_t shoot = 2;
	GPIOC->MODER &= ~(0x00000003 << (shoot * 2));
	GPIOC->PUPDR &= ~(0x00000003 << (shoot * 2));
	GPIOC->PUPDR &= ~(0x00000003 << (shoot * 2)); // Clear push/pull register
	GPIOC->PUPDR |= (0x00000002 << (shoot * 2));

	// uint16_t val = GPIOC->IDR & (0x0001 << shoot ); //Read from pin PC2

	// PC3 = Switch/SW1
	uint8_t switch_W = 3;
	GPIOC->MODER &= ~(0x00000003 << (switch_W * 2));
	GPIOC->PUPDR &= ~(0x00000003 << (switch_W * 2));
	GPIOC->PUPDR &= ~(0x00000003 << (switch_W * 2)); // Clear push/pull register
	GPIOC->PUPDR |= (0x00000002 << (switch_W * 2));

	//	uint16_t val = GPIOC->IDR & (0x0001 << switch_W ); //Read from pin PC3



	//PinA0
	uint8_t pinA0_joystick_ADC = 1;
	GPIOA->MODER &= ~(0x00000003 << (pinA0_joystick_ADC * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000000 << (pinA0_joystick_ADC * 2));
	GPIOA->PUPDR &= ~(0x00000003 << (pinA0_joystick_ADC * 2)); // Clear push/pull register
	GPIOA->PUPDR |= (0x00000002 << (pinA0_joystick_ADC * 2));

	//PinA1
	uint8_t pinA1_joystick_ADC = 1;
	GPIOA->MODER &= ~(0x00000003 << (pinA1_joystick_ADC * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000000 << (pinA1_joystick_ADC * 2));
	GPIOA->PUPDR &= ~(0x00000003 << (pinA1_joystick_ADC * 2)); // Clear push/pull register
	GPIOA->PUPDR |= (0x00000002 << (pinA1_joystick_ADC * 2));

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

void configADC() {
	//Analog-to-Digital Conversion
	RCC->CFGR2 &= ~RCC_CFGR2_ADCPRE12; // Clear ADC12 prescaler bits
	RCC->CFGR2 |= RCC_CFGR2_ADCPRE12_DIV6; // Set ADC12 prescaler to 6
	RCC->AHBENR |= RCC_AHBPeriph_ADC12; // Enable clock for ADC12

	ADC1->CR = 0x00000000; // Clear CR register
	ADC1->CFGR &= 0xFDFFC007; // Clear ADC1 config register
	ADC1->SQR1 &= ~ADC_SQR1_L; // Clear regular sequence register 1

	ADC1->CR |= 0x10000000; // Enable internal ADC voltage regulator
	for (int i = 0; i < 1000; i++) {} // Wait for about 16 microseconds

	ADC1->CR |= 0x80000000; // Start ADC1 calibration
	while (!(ADC1->CR & 0x80000000)); // Wait for calibration to finish
	for (int i = 0; i < 100; i++) {} // Wait for a little while

	ADC1->CR |= 0x00000001; // Enable ADC1 (0x01 - Enable, 0x02 - Disable)
	while (!(ADC1->ISR & 0x00000001)); // Wait until ready

	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5);

	ADC_StartConversion(ADC1); // Start ADC read
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read
}


