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
		init_pins();
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

