<<<<<<< Updated upstream
//#include "ansi_S.h"
//#include "timer.h"
//
////TIM15->CR1 to disable the timer and configure the mode.
////TIM15->ARR to set the reload value.
////TIM15->PSC to set the prescaler.
//// Write to TIM15->CR1 to enable the timer and begin counting
//
//void initTimer(){
//RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 15;
//TIM15->CR1 = 0x0000; // Configure timer 15
//TIM15->ARR = 0xF9FF; // Set reload value
//TIM15->PSC = 0x0009; // Set prescale value
//TIM15->DIER |= 0x0001; // Enable timer 15 interrupts
//TIM15->CR1 = 0x0001;
//NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0); // Set interrupt priority
//NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn); // Enable interrupt
//}
//
//
//
//
//
//
//
//
//
//void initTimer2(){
//RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;TIM15->CR1 = 0x0000; // Configure timer 15
//TIM2->CR1 = 0x0000;
//TIM2->ARR = 0xF9FF; // Set reload value
//TIM2->PSC = 0x0009; // Set prescale value
//TIM2->DIER |= 0x0001;
//
//
//TIM2->CCER &= ~TIM_CCER_CC3P; // Clear CCER register
//TIM2->CCER |= 0x00000001 << 8; // Enable OC3 output
//TIM2->CCMR2 &= ~TIM_CCMR2_OC3M; // Clear CCMR2 register
//TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;
//TIM2->CCMR2 |= TIM_OCMode_PWM1; // Set output mode to PWM1
//TIM2->CCMR2 &= ~TIM_CCMR2_OC3PE;
//TIM2->CCMR2 |= TIM_OCPreload_Enable;
//TIM2->CCR3 = 0xF9FF / 2; // Set duty cycle to 50 %
//
//
//
//NVIC_SetPriority(TIM2_IRQn, 1); // Set interrupt priority
//NVIC_EnableIRQ(TIM2_IRQn); // Enable interrupt
//
//TIM2->CR1 = 0x0001;
//}
//
//void initBuzz(){
//	// Set pin PA9 to output - BLUE LED
//	GPIOB->OSPEEDR &= ~(0x00000003 << (10 * 2)); // Clear speed register
//	GPIOB->OSPEEDR |= (0x00000002 << (10 * 2)); // set speed register
//	// 0x01 - 10  Hz
//	// 0x02 - 2 MHz
//	// 0x03 - 50 MHz
//	GPIOB->OTYPER &= ~(0x0001 << (10 * 1)); // Clear output type register
//	GPIOB->OTYPER |= (0x0000 << (10)); // Set output type register
//	// 0x00 - Push pull
//	// 0x01 - Open drain
//	GPIOB->MODER &= ~(0x00000003 << (10 * 2)); // Clear mode register
//	GPIOB->MODER |= (0x00000002 << (10 * 2)); // Set mode register
//	// 0x00 – Input
//	// 0x01 - Output
//	// 0x02 - Alternate Function
//	// 0x03 - Analog in/out
//
//	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_1);
//}
//
//
//
//void setFreq(uint16_t freq) {
//uint32_t reload = 64e6 / freq / (9 + 1) - 1;
//TIM2->ARR = reload; // Set auto reload value
//TIM2->CCR3 = reload/2; // Set compare register
//TIM2->EGR |= 0x01;
//}
//
//void TIM2_IRQHandler(void) {
//
//
////Do whatever you want here, but make sure it doesn’t take too much Time.
//TIM2->SR &= ~0x0001; // Clear interrupt bit
//}
//
//
//void TIM1_BRK_TIM15_IRQHandler(void) {
//
//	lcdUpdate++;
//
//		if (lcdUpdate >= refreshRate){
//			if (led.blu == 0){
//				led.blu = 1;
//			}
//			else if (led.blu == 1){
//				led.blu = 0;
//			}
//			lcdUpdate = 0;
//		}
//
//
//
////Do whatever you want here, but make sure it doesn’t take too much Time.
//TIM15->SR &= ~0x0001; // Clear interrupt bit
//}
//
=======
#include "ansi_S.h"
#include "timer.h"
#include "joystick.h"

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

	RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;
	TIM2->CR1 	= 0x0000; // Configure timer 2

	TIM2->CCER &= ~TIM_CCER_CC3P; // Clear CCER register
	TIM2->CCER |= 0x00000001 << 8; // Enable OC3 output
	TIM2->CCMR2 &= ~TIM_CCMR2_OC3M; // Clear CCMR2 register
	TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;
	TIM2->CCMR2 |= TIM_OCMode_PWM1; // Set output mode to PWM1
	TIM2->CCMR2 &= ~TIM_CCMR2_OC3PE;
	TIM2->CCMR2 |= TIM_OCPreload_Enable;
	TIM2->CCR3 = RELOAD_VALUE / 2; // Set duty cycle to 50 %

	TIM2->CR1 	= 0x0001; // Configure timer 2

	TIM2->ARR 	= 0xF9FF; // Set reload value
	TIM2->PSC 	= 0x0009; // Set prescale value
	TIM2->DIER	|= 0x0001;
	TIM2->SR	= 0x0000;

	NVIC_SetPriority(TIM2_IRQn, 1); // Set interrupt priority
	NVIC_EnableIRQ(TIM2_IRQn); // Enable interrupt
}

void TIM2_IRQHandler(void) {


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

		if (timeState == 0){
			timeState = 1;
		}
		else if (timeState == 1){
			timeState = 0;
		}
		lcdUpdate = 0;
	}

	if(tid.state){
		if (tid.mil <= 0){
			tid.mil = 99;
			tid.sek--;
		}
		if (tid.sek < 0){
			tid.sek = 59;
			tid.min--;
		}
		tid.mil--;
		if (tid.min < 0){
			tid.state = 0;
			tid.min = 0;
			tid.sek = 0;
			tid.mil = 0;
			setFreq(0);
			GameOver();
			while (1){

			}
		}

	}

//Do whatever you want here, but make sure it doesn’t take too much Time.
TIM15->SR &= ~0x0001; // Clear interrupt bit
}


void drawTime(){
	static int hp;
	int red = 0, green = 0, yellow = 0, x = tid.sek + (tid.min * 60);

	char greenS[] = "1G  1f 1G  1f 1G  1f 1G  1f 1G 1f 1D 1e 1f 1G  1f 1G  1f 1G  1f 1G  1f 1G 1f 1D1e1f 2c  1G 2c  1G 2c  1G 2c  1G 2c 1G 1g1g1G 2c  1G 2c  1G 2c  1G 2c  1G 2c 1G 1g1g1G  ";
	char yellowS[] = " 2G2G2G2A2B2B2A2G2G2A2B2B2A2G";
	char redS[] = " 3C3C3C3D3E3E3D3C3C3D3E3E3D3C";
	char doom[] = "2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a  2D 2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D  2a    2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D 2D 2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a      2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D  2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a     2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D 2D 2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 4f 4D 4f 4F 4d 4F 4A 4F 4d2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D  2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a     2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D  2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 4A 4F4D 4F4A 4F4A 4A 4F4A 4F4A  2G 2G 3G 2G 2G 3F 2G 2G 3e 2G 2G 3d 2G 2G 3D 3e 2G 2G 3G 2G 2G 3F 2G 2G 3e 2G 2G 3d     2G 2G 3G 2G 2G 3F 2G 2G 3e 2G 2G 3d 2G 2G 3D 3e 2G 2G 3G 2G 2G 3F 2G 2G  3b 3b 3b3G 4G 3b 3b 3G3b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D  2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a     2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D 2D 2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 3A 2A 2A 3G 2A 2A 3F 2a 2G 3e     2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D 2D 2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 4D4F 3F3A 4D3A 4F4D 4F4D 3F3A 4D4F 4A 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2a 2D 2D 2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D  2a    2D 2D 3D 2D 2D 3C 2D 2D 2b 2D 2D 2D2a 2D  2A 2b 2D 2D 3D 2D 2D 3C 2D 2D 4d3b 3f3A 4f4d 3G3A 4G4f 4d 4A4G3A 4f4d 2D 2D 3F 2D 2D 3f 2D 2D 3d 2D 2D 3C2D 2D  3C 3D 2D 2D 3F 2D 2D 3f 2D 2D 3D 2D 2D  3c    2D 2D 3F 2D 2D 3f 2D 2D 3d 2D 2D 3C     2D 2D 3F 2D 2D 3f 2D 2D 6D4A 4F 6D4D4A 4A4F 4D4F 4A4F 6D4A 4F4D 2G 2G 3b 2G 2G 3A 2G 2G 3g 2G 2G 3F 2G  3F 3G 2G 2G 3b 2G 2G 3A 2G 2G 3G 2G 2G  3F    2G 2G 3b 2G 2G 3A 2G 2G 3g 2G 2G 3F 2G 2G 3F 3G 2G 2G 3b 2G 2G 3A 2G 2G 4D4C 4D3b 3G3b 4D3b 4G4D 4D3b 4D3b 3G3b 2D 2D 3F 2D 2D 3f 2D 2D 3d 2D 2D 3C 2D  3C 3D 2D 2D 3F 2D 2D 3f 2D 2D 3D 2D   3c    2D 2D 3F 2D 2D 3f 2D 2D 3d 2D 2D 3C2D 2D  3C 3D 2D 2D 3F 2D 2D 3f 2D 2D 3D 2D 2D 3c     3c 3c 4F 3c 3c 4f 3c 3c 4D 3c 3c 4c 3c 3c 4c 4D 2A 2A 4f 2A 2A 4D 2A 2A 4d 2a 2G 3A     2D 2D 3F 2D 2D 3f 2D 2D 3d 2D 2D 3C 2D  3C 3D 2D 2D 3F 2D 2D 3f 2D 2D  4d 3G3A 3d3f 2A  4f4d3A 3f3G 3d  3D                     ";


	gotoxy(132,3);
	printf("%02d:%02d:%02d", tid.min, tid.sek, tid.mil);
//	gotoxy(2,3);
//	for (int i = 0; i < 40; i++){
//		printf("%c",32);
//	}

	gotoxy(142,3);
	tid.state ? blink(1): blink(0);
	if (x>=80){
		hp = 1;
		fgcolor(2); // green
		for (int i = 0; i < x-80; i++){
			printf("%c",178);
		}
		fgcolor(11); // yellow
		for (int i = x-80; i < 40; i++){
			printf("%c",178);
		}
	}
	else if (x>=40){
		hp = 2;
		fgcolor(11); // yellow
		for (int i = 0; i < x-40; i++){
			printf("%c",178);
		}
		fgcolor(1); // red
		for (int i = x-40; i < 40; i++){
			printf("%c",178);
		}
	}
	else if (x<40){
		hp = 3;

		led.red = tid.state;
		fgcolor(1); // red
		for (int i = 0; i < x; i++){
			printf("%c",178);
		}
		blink(0);
		for (int i = x; i < 40; i++){
			printf("%c",32);
		}
	}
	else if (x = 0){
		hp = 0;
	}

	blink(0);
	resetbgcolor();

	switch(hp){
		case 0:
			red = 0;
			green = 0;
			break;
		case 1:
			green = !tid.state | timeState;
			break;
		case 2:
			yellow = !tid.state | timeState;
			break;
		case 3:
			red = !tid.state | timeState;
			break;
	}

	led.gre = green | yellow;
	led.red = red | yellow;

	if (tid.state){
		if(green & timeState ){
			playTone(greenS);
		}
		else if(yellow & timeState ){
			playTone(yellowS);
		}
		else if(red & timeState){
			playTone(redS);
		}
	}
	else {
		setFreq(0);

		playTone(doom);


	}

}

void resetTime(){
	tid.mil = 0;
	tid.sek = 0;
	tid.min = 2;
}

//void timeControll(){
//	readJoystick();
//
//	if(joy.up){
//		tid.state = 0;
//	}
//	else if (joy.down){
//		tid.state = 1;
//	}
//	else if (joy.right){
//		resetTime();
//	}
//
//}


>>>>>>> Stashed changes
