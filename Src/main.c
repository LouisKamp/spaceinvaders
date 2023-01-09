#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "gpio.h"
#include "led.h"
#include "lcd.h"

int main(void)
{
	lcd_init();
	lcd_clear();

	uint8_t buffer[512] = {};
	lcd_write_string("H",27,-2, &buffer);

	lcd_push_buffer(&buffer);

	while(1){}
}
