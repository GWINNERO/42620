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


	gotoxy(152,3);
	printf("%02d:%02d:%02d | %d | %03d", tid.min, tid.sek, tid.mil, tid.state,x);

	gotoxy(140,5);
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
	}

}

void resetTime(){
	tid.mil = 0;
	tid.sek = 0;
	tid.min = 2;
}

void timeControll(){
	readJoystick();

	if(joy.up){
		tid.state = 0;
	}
	else if (joy.down){
		tid.state = 1;
	}
	else if (joy.right){
		resetTime();
	}

}


