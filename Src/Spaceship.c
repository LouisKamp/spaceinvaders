
#include "spaceship.h"

void initialize_spaceship(spaceship_t* s) {
	s->x = 20;
	s->y = 20;
	s->vx = 2;
	s->vy = 5;
	s->life = 2;
	s->weapon = s->y+2;
}
void draw_spaceship(spaceship_t* s, uint8_t* buffer) {
	lcd_write_char('>', s->x, s->y, buffer);
}

void remove_spaceship(spaceship_t* s) {
	getxy(s->y, s->x);
	printf("%c", 32);
	getxy((s->y + 1), s->x);
	printf("%c", 32);
	getxy((s->y + 1), (s->x + 2));
	printf("%c", 32);
	getxy((s->y + 1), (s->x - 2));
	printf("%c", 32);
	getxy((s->y + 2), (s->x));
}

int8_t make_spaceship_weapon(spaceship_t* s) {
	uint16_t shoot = GPIOC->IDR & (0x0001 << 2); //Read from pin PC2
	uint16_t switch_W = GPIOC->IDR & (0x0001 << 3); //Read from pin PC3
	if (switch_W) {
		while (1) {
			int weaponcolor[] = { 1,2,3 };
			const int* current_weapon = weaponcolor;

			if (current_weapon == &weaponcolor[0]) {
				set_led(0b100);
				current_weapon++;
				return shoot;
			}
			if (current_weapon == &weaponcolor[1]) {
				set_led(0b010);
				current_weapon++;
				return shoot;
			}
			if (current_weapon == &weaponcolor[2]) {
				set_led(0b001);
				current_weapon++;
				return shoot;
			}
			if (current_weapon == &weaponcolor[3])
			{
				current_weapon = weaponcolor;
				return shoot;
			}
		}
	}
	else {
		return shoot;
	}

}


void update_spaceship_weapon(spaceship_t* s) {
	s->weapon = s->weapon - 1;
}

void update_spaceship_postition(joystick_input_t input, spaceship_t* s) {
	// UP
	if ((input & (1 << 0)) && (0 < s->x)) {
		s->x--;
	}

	// DOWN
	if ((input & (1 << 1)) && (s->x < 25)) {
		s->x++;
	}

	// LEFT
	if ((input & (1 << 2)) && (0 < s->y)) {
		s->y--;
	}

	// RIGHT
	if ((input & (1 << 3)) && (s->y < 122)) {
		s->y++;
	}

}


//int8_t read_joystick(spaceship_t* s) {
//
//	uint16_t x = ADC_GetConversionValue(ADC1); // Read the ADC value
//	if (1500 < x && x < 4100) {
//		return 2;
//	}
//
//	if (14 < x && x < 1300) {
//		return 3;
//	}
//
//}
//
//int main (void) {
//	uart_init(115200); // Initialize USB serial emulation at 115200 baud
//	clear();
//	spaceship_t s;
//
//	initializeSpaceship(&s);
//	drawSpaceship(&s);
//
//	while(1){
//		init_pins();
//		configADC();
//		readjoystick(&s);
//
//		if (readjoystick(&s) == 2 ) {
//			removeSpaceship(&s);
//			update_ship_right(&s);
//			drawSpaceship(&s);
//		}
//		if (readjoystick(&s) == 3 ) {
//			removeSpaceship(&s);
//			update_ship_left(&s);
//			drawSpaceship(&s);
//		}
//		if (makeSpaceship_weapon(&s) == 2) {
//			int n = 0;
//			start_weapon(&s);
//			draw_weapon(&s);
//			while ( n < 20) {
//				remove_weapon(&s);
//				updateSpaceship_weapon(&s);
//				draw_weapon(&s);
//				n++;
//			}
//
//		}
//
//	}
//
//}

