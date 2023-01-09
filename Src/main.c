#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "gpio.h"
#include "led.h"
#include "lcd.h"

int main(void)
{
	lcd_init();
	lcd_clear();
	//lcd_write_string();

	while(1){}
}
