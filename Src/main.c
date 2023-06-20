#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi_S.h"
#include "joystick.h"
#include "timer.h"


int main(void)
{
	uart_init(250000);
	clrscr();
	intiJoystick();
	startWindow(1,1,184,58);
	initLed();
	initTimer();
	refreshRate = 5;
	duck_t duck1;
	duck_t duck2;
	spaceship_t SS;
	spaceship(2,27,91,31);
	playerInSpaceR(1,23,24);
	playerInSpaceUSDR(2,23,32);
	SS.ud = 0;
	duck1.rl=0;
	duck1.ud=0;
	duck2.rl = 0;
	duck2.ud = 8;

	tid.min = 10;
	tid.sek = 10;
	tid.mil = 0;
	tid.state = 1;

	int i=0, keyW=0, keyA=0, keyS=0, keyD=0, keyE=0;
	uart_clear();
	char random;
	int buffer_lenght;

	int ud1 =0, lr1 =0, ud2 = 8, lr2 = 0, a = 0, b=0;
	while(1){

		readJoystick();
		gotoxy(10,10);
		printf("Duck1 ud:%d  Duck1 rl:%d  Duck2 ud:%d Duck2 rl:%d   SS.ud = %d",duck1.ud, duck1.rl, duck2.ud, duck2.rl,SS.ud);

		fire(2,27+SS.ud,91,31+SS.ud);

		if(duck1.ud == SS.ud) {
			goDuckUP1(1,22,24,&ud1,&lr1,&duck1);
			if (duck1.rl == 5 && duck2.ud == SS.ud && joy.up){
				key.up = 1;
				goDuckUP2(2,22,24,&ud2,&lr2,&duck2);
				key.up = 0;
			}
			if (duck1.rl == 5 && duck2.ud == SS.ud + 4 && joy.up){
				key.up = 1;
				goDuckMIDMove2(2,22,24,&ud2,&lr2,&duck2);
				key.up = 0;
			}
			if (duck1.rl == 5 && duck2.ud == SS.ud + 8 && joy.up){
				key.up = 1;
				goDuckUSDMove2(2,22,24,&ud2,&lr2,&duck2);
				key.up = 0;
			}
		}

		if(duck1.ud == SS.ud + 4 || duck1.ud == SS.ud - 4){
		goDuckMID1(1,22,24,&ud1,&lr1,&duck1);
		if(duck1.rl == 55 && joy.right && !CJoy.right){
			canonFire(2,SS.ud);
		}
		}

		if(duck1.ud == SS.ud+8) {
		goDuckUSD1(1,22,24,&ud1,&lr1,&duck1);
		if (duck1.rl == 5 && duck2.ud == SS.ud && joy.up){
			key.down = 1;
			goDuckUPMove2(2,22,24,&ud2,&lr2,&duck2);
			key.down = 0;
		}
		if (duck1.rl == 5 && duck2.ud == SS.ud + 4 && joy.up){
			key.down = 1;
			goDuckMIDMove2(2,22,24,&ud2,&lr2,&duck2);
			key.down = 0;
		}
		if (duck1.rl == 5 && duck2.ud == SS.ud + 8 && joy.up){
			key.down = 1;
			goDuckUSDMove2(2,22,24,&ud2,&lr2,&duck2);
			key.down = 0;
		}
		}

		if(duck1.rl == 5 && joy.up && !CJoy.up && SS.ud == duck1.ud+1 & SS.ud != -20){
		spaceshipDelete(2,27+SS.ud,91,31+SS.ud);
		fireDelete(2,27+SS.ud,91,31+SS.ud);
		SS.ud -= 1;
		spaceship(2,27+SS.ud,91,31+SS.ud);
		}

		if(duck1.rl == 5 && joy.up && !CJoy.up && SS.ud == duck1.ud-9 && SS.ud != 21){
		spaceshipDelete(2,27+SS.ud,91,31+SS.ud);
		fireDelete(2,27+SS.ud,91,31+SS.ud);
		SS.ud += 1;
		spaceship(2,27+SS.ud,91,31+SS.ud);
		}

//		if (joy.up && duck1.rl != 5 && duck1.ud == SS.ud -1) {
//		duckExplotion(22,24,&ud1,&lr1);
//		playerInSpaceR(1,23,24);
//		ud1 = 0;
//		lr1 = 0;
//		duck1.ud = 0;
//		duck1.rl = 0;
//		}
//		if (duck1.rl == 65){
//		duckExplotion(22,24,&ud1,&lr1);
//		playerInSpaceR(1,23,24);
//		ud1 = 0;
//		lr1 = 0;
//		duck1.ud = 0;
//		duck1.rl = 0;
//		}
//		if (joy.up && duck1.rl != 5 && duck1.ud == SS.ud +9) {
//		duckExplotion(22,24,&ud1,&lr1);
//		playerInSpaceR(1,23,24);
//		ud1 = 0;
//		lr1 = 0;
//		duck1.ud = 0;
//		duck1.rl = 0;
//		}



		if(duck2.ud == SS.ud) {
		goDuckUP2(2,22,24,&ud2,&lr2,&duck2);
		if (duck2.rl == 5 && duck1.ud == SS.ud && key.up){
			joy.up = 1;
			goDuckUPMove1(1,22,24,&ud1,&lr1,&duck1);
			joy.up = 0;
		}
		if (duck2.rl == 5 && duck1.ud == SS.ud + 4 && key.up){
			joy.up = 1;
			goDuckMIDMove2(1,22,24,&ud1,&lr1,&duck1);
			joy.up = 0;
		}
		if (duck2.rl == 5 && duck1.ud == SS.ud + 8 && key.up){
			joy.up = 1;
			goDuckUSDMove2(1,22,24,&ud1,&lr1,&duck1);
			joy.up = 0;
		}
		}

		if(duck2.ud == SS.ud + 4 || duck2.ud == SS.ud - 4){
		goDuckMID2(2,22,24,&ud2,&lr2,&duck2);
		if(duck2.rl == 55 && key.right){
		canonFire(2,SS.ud);
		}
		}

		if(duck2.ud == SS.ud+8) {
		goDuckUSD2(2,22,24,&ud2,&lr2,&duck2);
		if (duck2.rl == 5 && duck1.ud == SS.ud && key.up){
			joy.down = 1;
			goDuckUPMove1(1,22,24,&ud1,&lr1,&duck1);
			joy.down = 0;
		}
		if (duck2.rl == 5 && duck1.ud == SS.ud + 4 && key.up){
			joy.down = 1;
			goDuckMIDMove2(1,22,24,&ud1,&lr1,&duck1);
			joy.down = 0;
		}
		if (duck2.rl == 5 && duck1.ud == SS.ud + 8 && key.up){
			joy.down = 1;
			goDuckUSDMove2(1,22,24,&ud1,&lr1,&duck1);
			joy.down = 0;
		}
		}

		if(duck2.rl == 5 && key.up && SS.ud == duck2.ud+1 && SS.ud != -20){
		spaceshipDelete(2,27+SS.ud,91,31+SS.ud);
		fireDelete(2,27+SS.ud,91,31+SS.ud);
		SS.ud -= 1;
		spaceship(2,27+SS.ud,91,31+SS.ud);
		}

		if(duck2.rl == 5 && key.up && SS.ud == duck2.ud-9 && SS.ud != 21){
		spaceshipDelete(2,27+SS.ud,91,31+SS.ud);
		fireDelete(2,27+SS.ud,91,31+SS.ud);
		SS.ud += 1;
		spaceship(2,27+SS.ud,91,31+SS.ud);
		}

//		if (key.up && duck2.rl != 5 && duck2.ud == SS.ud -1) {
//		duckExplotion(22,24,&ud2,&lr2);
//		playerInSpaceUSDR(2,23,32);
//		ud2=8;
//		lr2=0;
//		duck2.ud = 8;
//		duck2.rl = 0;
//		}
//		if (duck2.rl == 65){
//		duckExplotion(22,24,&ud2,&lr2);
//		playerInSpaceUSDR(2,23,32);
//		ud2=8;
//		lr2=0;
//		duck2.ud = 8;
//		duck2.rl = 0;
//		}
//		if (key.up && duck2.rl != 5 && duck2.ud == SS.ud + 9) {
//		duckExplotion(22,24,&ud2,&lr2);
//		playerInSpaceUSDR(2,23,32);
//		ud2=8;
//		lr2=0;
//		duck2.ud = 8;
//		duck2.rl = 0;
//		}

		buffer_lenght = uart_get_count();
		gotoxy(30,10);
		printf("%d", buffer_lenght);

		if (lcdUpdate > 0){
		//Keyboard input

		if (buffer_lenght > 0) {
			random = uart_get_char();
			gotoxy(10,10);
			printf("%c", random);
		}


		if (random == 'w'){
			key.up = 1;
		}
		else {key.up = 0;}

		if (random == 'a'){
			key.left = 1;
		}
		else {key.left = 0;}

		if (random == 's'){
			key.down = 1;
		}
		else {key.down = 0;}

		if (random == 'd'){
			key.right = 1;
		}
		else {key.right = 0;}

		if (random == 'e'){
			key.center = 1;
		}
		else {key.center = 0;}

		random = " ";
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

		writeLed();
	}
}
