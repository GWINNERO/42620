#include "stm32f30x_conf.h"
#include "ansi_S.h"
#include "timer.h"
#include "joystick.h"


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

char ballin[] = " 2b 2b 2b 2b  3c";

void playTone(char s[]){
	static int i;
	int buzzTone = 0;

	int length = strlen(s);

	switch(s[i]){
	case '1':
		i++;
		switch(s[i]){
			case 'c':
				buzzTone = 33;
				break;
			case 'C':
				buzzTone = 35;
				break;

			case 'd':
				buzzTone = 37;
				break;
			case 'D':
				buzzTone = 39;
				break;

			case 'e':
				buzzTone = 41;
				break;

			case 'f':
				buzzTone = 44;
				break;
			case 'F':
				buzzTone = 46;
				break;

			case 'g':
				buzzTone = 49;
				break;
			case 'G':
				buzzTone = 52;
				break;

			case 'a':
				buzzTone = 55;
				break;
			case 'A':
				buzzTone = 58;
				break;

			case 'b':
				buzzTone = 62;
				break;
			default:
				buzzTone = 0;
				break;
		}
		break;
	case '2':
		i++;
		printf("%c",s[i]);
		switch(s[i]){
			case 'c':
				buzzTone = 65;
				break;
			case 'C':
				buzzTone = 69;
				break;

			case 'd':
				buzzTone = 73;
				break;
			case 'D':
				buzzTone = 78;
				break;

			case 'e':
				buzzTone = 82;
				break;

			case 'f':
				buzzTone = 87;
				break;
			case 'F':
				buzzTone = 93;
				break;

			case 'g':
				buzzTone = 98;
				break;
			case 'G':
				buzzTone = 104;
				break;

			case 'a':
				buzzTone = 110;
				break;
			case 'A':
				buzzTone = 117;
				break;

			case 'b':
				buzzTone = 123;
				break;
			default:
				buzzTone = 0;
				break;
		}
	break;

	case '3':
		i++;
		switch(s[i]){
			case 'c':
				buzzTone = 131;
				break;
			case 'C':
				buzzTone = 139;
				break;

			case 'd':
				buzzTone = 147;
				break;
			case 'D':
				buzzTone = 156;
				break;

			case 'e':
				buzzTone = 165;
				break;

			case 'f':
				buzzTone = 175;
				break;
			case 'F':
				buzzTone = 185;
				break;

			case 'g':
				buzzTone = 196;
				break;
			case 'G':
				buzzTone = 208;
				break;

			case 'a':
				buzzTone = 220;
				break;
			case 'A':
				buzzTone = 233;
				break;

			case 'b':
				buzzTone = 247;
				break;
			default:
				buzzTone = 0;
				break;
		}
		break;

	case '4':
		i++;
		switch(s[i]){
			case 'c':
				buzzTone = 262;
				break;
			case 'C':
				buzzTone = 277;
				break;

			case 'd':
				buzzTone = 294;
				break;
			case 'D':
				buzzTone = 311;
				break;

			case 'e':
				buzzTone = 330;
				break;

			case 'f':
				buzzTone = 349;
				break;
			case 'F':
				buzzTone = 370;
				break;

			case 'g':
				buzzTone = 392;
				break;
			case 'G':
				buzzTone = 415;
				break;

			case 'a':
				buzzTone = 440;
				break;
			case 'A':
				buzzTone = 466;
				break;

			case 'b':
				buzzTone = 494;
				break;
			default:
				buzzTone = 0;
				break;
		}
		break;

	case '5':
		i++;
		switch(s[i]){
			case 'c':
				buzzTone = 523;
				break;
			case 'C':
				buzzTone = 554;
				break;

			case 'd':
				buzzTone = 587;
				break;
			case 'D':
				buzzTone = 622;
				break;

			case 'e':
				buzzTone = 659;
				break;

			case 'f':
				buzzTone = 698;
				break;
			case 'F':
				buzzTone = 740;
				break;

			case 'g':
				buzzTone = 784;
				break;
			case 'G':
				buzzTone = 831;
				break;

			case 'a':
				buzzTone = 880;
				break;
			case 'A':
				buzzTone = 932;
				break;

			case 'b':
				buzzTone = 988;
				break;
			default:
				buzzTone = 0;
				break;
		}
		break;

	default:
		buzzTone = 0;
		break;
	}

	setFreq(buzzTone);
	gotoxy(1,8);
	printf("Input[%02d]: %c%c, Buzz: %04d | Length: %04d",i, s[i-1], s[i], buzzTone, length);

	if (i > length){
		i = 0;
	}

	i++;

}




void setFreq(uint16_t freq)
{
    // Calculate the new auto-reload value based on the desired frequency
    uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;

    // Set the new auto-reload value
    TIM2->ARR = reload;

    // Set compare register to maintain 50% duty cycle
    TIM2->CCR3 = reload / 2;

    // Generate an update event to apply the new settings
    TIM2->EGR |= TIM_EGR_UG;
}
