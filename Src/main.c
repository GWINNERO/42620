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

	memset(buffer, 0x00, 512);
	initTimer();

//	char navn[] = "Player 1 Player 2 Player 3 Player 4                      ";
//	int slicelen = strlen(navn) * 5;
//	int	p = 128;

	refreshRate = 20;

	int player_mode;
	int difficulty;

	menu(&player_mode, &difficulty);
	gotoxy(10,15);
	printf("%d%d", player_mode, difficulty);

	int alarm = 1;
	int alarm_off = 0;
	draw_gameplay_start();



	while (1) {
		if (lcdUpdate == 0){
			while (lcdUpdate == 0) {
			}
			score = score + 2;
			draw_score();
		}
		if (alarm == 1) {
			alarm_off += LCD_alarm();
			if (alarm_off == 5) {
				alarm_off = 0;
				alarm = 0;
			}
		}
		if (alarm == 0) {
			LCD_timer();
		}
		readJoystick();
		writeLed();
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







