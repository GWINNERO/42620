#include "ansi_S.h"
#include "timer.h"

//TIM15->CR1 to disable the timer and configure the mode.
//TIM15->ARR to set the reload value.
//TIM15->PSC to set the prescaler.
// Write to TIM15->CR1 to enable the timer and begin counting

void initTimer(){
RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 15;
TIM15->CR1 = 0x0000; // Configure timer 15
TIM15->ARR = 0xF9FF; // Set reload value
TIM15->PSC = 0x0009; // Set prescale value
TIM15->DIER |= 0x0001; // Enable timer 15 interrupts
TIM15->CR1 = 0x0001;
NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0); // Set interrupt priority
NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn); // Enable interrupt
}









void initTimer2(){
RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;TIM15->CR1 = 0x0000; // Configure timer 15
TIM2->CR1 = 0x0000;
TIM2->ARR = 0xF9FF; // Set reload value
TIM2->PSC = 0x0009; // Set prescale value
TIM2->DIER |= 0x0001;


TIM2->CCER &= ~TIM_CCER_CC3P; // Clear CCER register
TIM2->CCER |= 0x00000001 << 8; // Enable OC3 output
TIM2->CCMR2 &= ~TIM_CCMR2_OC3M; // Clear CCMR2 register
TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;
TIM2->CCMR2 |= TIM_OCMode_PWM1; // Set output mode to PWM1
TIM2->CCMR2 &= ~TIM_CCMR2_OC3PE;
TIM2->CCMR2 |= TIM_OCPreload_Enable;
TIM2->CCR3 = 0xF9FF / 2; // Set duty cycle to 50 %



NVIC_SetPriority(TIM2_IRQn, 1); // Set interrupt priority
NVIC_EnableIRQ(TIM2_IRQn); // Enable interrupt

TIM2->CR1 = 0x0001;
}

void initBuzz(){
	// Set pin PA9 to output - BLUE LED
	GPIOB->OSPEEDR &= ~(0x00000003 << (10 * 2)); // Clear speed register
	GPIOB->OSPEEDR |= (0x00000002 << (10 * 2)); // set speed register
	// 0x01 - 10  Hz
	// 0x02 - 2 MHz
	// 0x03 - 50 MHz
	GPIOB->OTYPER &= ~(0x0001 << (10 * 1)); // Clear output type register
	GPIOB->OTYPER |= (0x0000 << (10)); // Set output type register
	// 0x00 - Push pull
	// 0x01 - Open drain
	GPIOB->MODER &= ~(0x00000003 << (10 * 2)); // Clear mode register
	GPIOB->MODER |= (0x00000002 << (10 * 2)); // Set mode register
	// 0x00 – Input
	// 0x01 - Output
	// 0x02 - Alternate Function
	// 0x03 - Analog in/out

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_1);
}



void setFreq(uint16_t freq) {
uint32_t reload = 64e6 / freq / (9 + 1) - 1;
TIM2->ARR = reload; // Set auto reload value
TIM2->CCR3 = reload/2; // Set compare register
TIM2->EGR |= 0x01;
}

void TIM2_IRQHandler(void) {
/*
	static int i;
	gotoxy(1,4);
	printf("This is Tim2: %d",i);
	i++;
*/

//Do whatever you want here, but make sure it doesn’t take too much Time.
TIM2->SR &= ~0x0001; // Clear interrupt bit
}

void initTimerStop(){
NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn); // Enable interrupt
TIM15->CR1 = 0x0000; // Configure timer 15
}
void initTimerStart(){
NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn); // Enable interrupt
TIM15->CR1 = 0x0001; // Configure timer 15
}
void TIM1_BRK_TIM15_IRQHandler(void) {

	lcdUpdate++;

	if (lcdUpdate >= refreshRate){
		if (led.blu == 0){
			led.blu = 1;
		}
		else if (led.blu == 1){
			led.blu = 0;
		}

		lcdUpdate = 0;
	}


	if (tid.state == 1) {
		if (tid.mil == 0){
			tid.mil = 99;
			tid.sek--;
		}
		if (tid.min > 0 && tid.sek == 0){
			tid.mil--;
			tid.sek = 59;
		}
		if (tid.sek > 0){
			tid.sek--;
		}
		if (tid.sek == 0 && tid.min == 0) {
			tid.state = 0;
		}
	}





//Do whatever you want here, but make sure it doesn’t take too much Time.
TIM15->SR &= ~0x0001; // Clear interrupt bit
}

