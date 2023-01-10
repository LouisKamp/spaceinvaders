#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "gpio.h"
#include "led.h"
#include "lcd.h"
#include "MakeScreens.h"

int main(void)
{
	make_start_screen("Start Game");
	//make_help_screen("Help!");
	//help_info_screen();

	while(1){}
}
