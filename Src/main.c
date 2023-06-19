#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "timer.h"
#include "LCD.h"
#include "joystick.h"

int main(void) {

	// Setup communication with the PC
	uart_init(115200);
	clrscr();

	intiJoystick();
	initLed();
	lcd_init();
	writeLed();
	memset(buffer, 0x00, 512);
	initTimer();

//	char navn[] = "Player 1 Player 2 Player 3 Player 4                      ";
//	int slicelen = strlen(navn) * 5;
//	int	p = 128;
	refreshRate = 10;

	int a;
	int b;

	menu(&a, &b);
	gotoxy(10,10);
	printf("%d%d", a, b);
	//LCD_gameplay();


	while (1) {
		writeLed();

		if (lcdUpdate == 0){
			while (lcdUpdate == 0) {
			}
			score = score + 10;
			draw_gameplay_start();
		}
		//readJoystick();
		/*if(lcdUpdate == 0){
		lcd_update(navn, p);
		if ( slicelen <= 128) {
			if (p < 1){
			p = 128;
			}
		} else if ( slicelen > 128) {
			if (p < 1) {
			p = slicelen;
		}
		}
		p--;
		}*/


	}

}







