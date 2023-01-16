

#include "interrupts.h"

void init_interupts() {

	RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;


	TIM2->CR1 |= 0x0 << 11; // Configure timer 2
	TIM2->CR1 |= 0x00 << 8;
	TIM2->CR1 |= 0x0 << 7;
	TIM2->CR1 |= 0x0 << 5;
	TIM2->CR1 |= 0x0 << 4;
	TIM2->CR1 |= 0x0 << 3;
	TIM2->CR1 |= 0x0 << 2;
	TIM2->CR1 |= 0x0 << 1;
	TIM2->CR1 |= 0x1 << 0;
	// TIM2->CR1 |= 0x1 << 0;

	TIM2->ARR = 63999999/20; // Set reload value
	TIM2->PSC = 0; // Set prescale value

	TIM2->DIER |= 0x0001; // Enable timer 2 interrupts
	uint8_t priority = 0;
	NVIC_SetPriority(TIM2_IRQn, priority); // Set interrupt priority
	NVIC_EnableIRQ(TIM2_IRQn); // Enable interrupt

}

void enemyspawn_configure() {
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;  // Enable clock for TIM3

	TIM3->CR1 |= 0x0 << 11; // Configure timer 3
	TIM3->CR1 |= 0x00 << 8;
	TIM3->CR1 |= 0x0 << 7;
	TIM3->CR1 |= 0x0 << 5;
	TIM3->CR1 |= 0x0 << 4;
	TIM3->CR1 |= 0x0 << 3;
	TIM3->CR1 |= 0x0 << 2;
	TIM3->CR1 |= 0x0 << 1;
	TIM3->CR1 |= 0x1 << 0 ;


	TIM3 ->PSC =0 ;
	TIM3 -> DIER |= TIM_DIER_UIE;
	NVIC_SetPriority(TIM3_IRQn,0);
	NVIC_EnableIRQ(TIM3_IRQn);
}


void timer3_configure() {
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;  // Enable clock for TIM3

	TIM3->CR1 |= 0x0 << 11; // Configure timer 3
	TIM3->CR1 |= 0x00 << 8;
	TIM3->CR1 |= 0x0 << 7;
	TIM3->CR1 |= 0x0 << 6;
	TIM3->CR1 |= 0x0 << 4;
	TIM3->CR1 |= 0x0 << 3;
	TIM3->CR1 |= 0x0 << 2;
	TIM3->CR1 |= 0x0 << 1;


	TIM3->ARR = 63999999;
	TIM3 ->PSC =0;
	TIM3->DIER |= 0x0001;
	NVIC_SetPriority(TIM3_IRQn,0);
	NVIC_EnableIRQ( TIM3_IRQn);

}

void TIM3_IRQHandler(void) {
	//Do whatever you want here, but make sure it doesn’t take too much time

	TIM3->SR &= ~0x0001; // Clear interrupt bit

}




