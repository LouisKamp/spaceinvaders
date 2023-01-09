#define ESC 0x1B
#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#include "stm32f30x_conf.h" // STM32 config
#include "stm32f30x_rcc.h"
#include "30010_io.h" // Input/output library for this course
#include "gpio.h"
#include "led.h"
#include "LUTsin.h" //
#include "ansi.h"


typedef struct {
	uint8_t x,y,vx,vy,life,weapon;
} spaceship_t;

void initializeSpaceship(spaceship_t *s){
	s->x = 60;
	s->y = 40;
	s->vx = 2 ;
	s->vy = 5 ;
	s->life = 2;
	s->weapon = s->y-1;
}
void drawSpaceship(spaceship_t *s) {
	getxy(s->y,s->x);
	printf("%c",94);
	getxy((s->y+1),s->x);
	fgcolor(15);
	printf("%c",219);
	getxy((s->y+1),(s->x+2));
	printf("%c",62);
	getxy((s->y+1),(s->x-2));
	printf("%c",60);
	getxy((s->y+2),(s->x));
}

void removeSpaceship (spaceship_t *s) {
	getxy(s->y,s->x);
	printf("%c",32);
	getxy((s->y+1),s->x);
	printf("%c",32);
	getxy((s->y+1),(s->x+2));
	printf("%c",32);
	getxy((s->y+1),(s->x-2));
	printf("%c",32);
	getxy((s->y+2),(s->x));
}

int8_t makeSpaceship_weapon() {
	uint16_t val = GPIOC->IDR & (0x0001 << 1); //Read from pin PC1
	if (val) {
		printf("%c",45);
		return val;
	}
}

void start_weapon(spaceship_t *s) {
	s->weapon = s->y-1;
}
void draw_weapon(spaceship_t *s){
	getxy((s->weapon),s->x);
	fgcolor(5);
	printf("%c",42);
}
void remove_weapon(spaceship_t *s){
	getxy((s->weapon),s->x);
	printf("%c",32);
}

void updateSpaceship_weapon(spaceship_t *s) {
	s->weapon= s-> weapon-1;
}

void update_ship_right(spaceship_t *s) {
	int k = 1;
	s->x = s->x + 1*k;
	s-> y = s-> y;

}
void update_ship_left(spaceship_t *s) {
	int k = 1;
	s->x = s->x - 1*k;
	s-> y = s-> y;
}

void initialize_ports_ship(){
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable Clock GPIO for PORT A
	//PinA0
	GPIOA->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000000 << (0 * 2));
	GPIOA->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
	GPIOA->PUPDR |= (0x00000002 << (0 * 2));

	//PinA1
	GPIOA->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000000 << (1 * 2));
	GPIOA->PUPDR &= ~(0x00000003 << (1 * 2)); // Clear push/pull register
	GPIOA->PUPDR |= (0x00000002 << (1 * 2));

	RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable Clock GPIO for PORT C

	GPIOC->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
	GPIOC->MODER |= (0x00000000 << ( 1* 2));
	GPIOC->PUPDR &= ~(0x00000003 << (1 * 2)); // Clear push/pull register
	GPIOC->PUPDR |= (0x00000002 << (1* 2));

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
	for (int i = 0 ; i < 1000 ; i++) {} // Wait for about 16 microseconds

	ADC1->CR |= 0x80000000; // Start ADC1 calibration
	while (!(ADC1->CR & 0x80000000)); // Wait for calibration to finish
	for (int i = 0 ; i < 100 ; i++) {} // Wait for a little while

	ADC1->CR |= 0x00000001; // Enable ADC1 (0x01 - Enable, 0x02 - Disable)
	while (!(ADC1->ISR & 0x00000001)); // Wait until ready

	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5);

	ADC_StartConversion(ADC1); // Start ADC read
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read
}


int8_t readjoystick(spaceship_t *s){

	uint16_t x = ADC_GetConversionValue(ADC1); // Read the ADC value
	printf("Value = %02ld\n", x);
	if ( 1450 < x && x < 4100) {
		return 2;
	}

	if ( 14 < x && x < 1450) {
		return 3;
	}

}

int main (void) {
	uart_init(115200); // Initialize USB serial emulation at 115200 baud
	clear();
	spaceship_t s;

	initializeSpaceship(&s);
	//drawSpaceship(&s);

	while(1){
		initialize_ports_ship();
		configADC();
		readjoystick(&s);

		if (readjoystick(&s) == 2 ) {
			removeSpaceship(&s);
			update_ship_right(&s);
			drawSpaceship(&s);
		}
		if (readjoystick(&s) == 3 ) {
			removeSpaceship(&s);
			update_ship_left(&s);
			drawSpaceship(&s);
		}
		if (makeSpaceship_weapon(&s) == 2) {
			int n = 0;
			start_weapon(&s);
			draw_weapon(&s);
			while ( n < 20) {
				remove_weapon(&s);
				updateSpaceship_weapon(&s);
				draw_weapon(&s);
				n++;
			}

		}

	}

}

