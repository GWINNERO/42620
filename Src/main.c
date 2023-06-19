#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi_S.h"
#include "joystick.h"
//#include "timer.h"


int main(void)
{
	uart_init(250000);
	clrscr();
	intiJoystick();
	startWindow(1,1,184,58);
//	initLed();
//	initTimer();
//	refreshRate = 5;
	duck_t duck1;
	spaceship_t SS;
	spaceship(2,27,91,31);
	playerInSpaceR(1,23,24);
	SS.ud = 0;
	int ud =0, lr =0, a = 0, b=0;
	while(1){

		readJoystick();
		gotoxy(10,9);
		printf("%d%d%d%d%d",joy.left,joy.right,joy.up,joy.down,joy.center);

		gotoxy(10,10);
		printf("Duck rl = %d",joy.left);
		gotoxy(10,11);
		printf("U/D = %d",joy.right);
		fire(2,27+SS.ud,91,31+SS.ud);


		if(duck1.ud == SS.ud) {
		goDuck1UP(22,24,&ud,&lr,&duck1);
		}

		if(duck1.ud == SS.ud + 4 || duck1.ud == SS.ud - 4){
		goDuck1MID(22,24,&ud,&lr,&duck1);
		if(duck1.rl == 55 && joy.right && !CJoy.right){
			canonFire(SS.ud);
		}
		}

		if(duck1.ud == SS.ud+8) {
		goDuck1USD(22,24,&ud,&lr,&duck1);
		}

		if(duck1.rl == 5 && joy.up && !CJoy.up && SS.ud == duck1.ud+1){
		spaceshipDelete(2,27+SS.ud,91,31+SS.ud);
		fireDelete(2,27+SS.ud,91,31+SS.ud);
		SS.ud = duck1.ud;
		spaceship(2,27+SS.ud,91,31+SS.ud);
		}

		if(duck1.rl == 5 && joy.up && !CJoy.up && SS.ud == duck1.ud-9){
		spaceshipDelete(2,27+SS.ud,91,31+SS.ud);
		fireDelete(2,27+SS.ud,91,31+SS.ud);
		SS.ud = duck1.ud-8;
		spaceship(2,27+SS.ud,91,31+SS.ud);
		}

		if(duck1.ud == SS.ud-1 || duck1.ud == SS.ud+9 || duck1.rl == 65) {
			duckExplotion(22,24,&ud,&lr);
		}

//			b++;
//			if(b>6) {
//				b = 0;
//			}
//			a++;
//			if(a>4) {
//				a = 0;
//			}
//			collision(a,b,SS.ud);


		copyJoystick();


	}
}
