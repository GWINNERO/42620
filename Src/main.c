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
<<<<<<< Updated upstream
=======
	initLed();
	lcd_init();
	initTimer();
	initTimer2();

	refreshRate = 5;
	duck_t duck1;
	duck_t duck2;
	spaceship_t SS;
	int playermode, diff;
	memset(buffer,0x00,512);
	menu(&playermode,&diff);
	clrscr();
>>>>>>> Stashed changes
	startWindow(1,1,184,58);
//	initLed();
//	initTimer();
//	refreshRate = 5;
	duck_t duck1;
	spaceship_t SS;
	spaceship(2,27,91,31);
	playerInSpaceR(1,23,24);
<<<<<<< Updated upstream
	SS.ud = 0;
	int ud =0, lr =0, a = 0, b=0;
=======
	playerInSpaceUSDR(2,23,32);
	windowSmp(141,2,183,4);
	initAstro();
	SS.ud = 0;
	duck1.rl=0;
	duck1.ud=0;
	duck2.rl = 0;
	duck2.ud = 8;

	tid.min = 2;
	tid.sek = 0;
	tid.mil = 0;
	tid.state = 0;

	int alarm = 1;
	int alarm_off = 0;

	int i=0, keyW=0, keyA=0, keyS=0, keyD=0, keyE=0;
	uart_clear();
	char random;
	int buffer_lenght;
	int ud1 =0, lr1 =0, ud2 = 8, lr2 = 0, a = 1, b=1;
	int  one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
	draw_gameplay_start();
	initBuzz();
	setFreq(0);

>>>>>>> Stashed changes
	while(1){

		readJoystick();
<<<<<<< Updated upstream
		gotoxy(10,9);
		printf("%d%d%d%d%d",joy.left,joy.right,joy.up,joy.down,joy.center);

		gotoxy(10,10);
		printf("Duck rl = %d",joy.left);
		gotoxy(10,11);
		printf("U/D = %d",joy.right);
		fire(2,27+SS.ud,91,31+SS.ud);


		if(duck1.ud == SS.ud) {
		goDuck1UP(22,24,&ud,&lr,&duck1);
=======
		if (lcdUpdate == 0){
					while (lcdUpdate == 0) {
					}
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

		//Debug ship, players
//		gotoxy(10,10);
//		printf("Duck1 ud:%d  Duck1 rl:%d  Duck2 ud:%d Duck2 rl:%d   SS.ud = %d",duck1.ud, duck1.rl, duck2.ud, duck2.rl,SS.ud);

		fire(2,27+SS.ud,91,31+SS.ud);







		if(duck1.ud == SS.ud && Bup == 0 && !(Bship1 == 1 && duck1.rl == 35)) {
			goDuckUP1(1,22,24,&ud1,&lr1,&duck1);
			if (duck1.rl == 5 && duck2.ud == SS.ud && joy.up && Bup == 0){
				key.up = 1;
				goDuckUP2(2,22,24,&ud2,&lr2,&duck2);
				key.up = 0;
			}
			if (duck1.rl == 5 && duck2.ud == SS.ud + 4 && joy.up && Bup == 0){
				key.up = 1;
				goDuckMIDMove2(2,22,24,&ud2,&lr2,&duck2);
				key.up = 0;
			}
			if (duck1.rl == 5 && duck2.ud == SS.ud + 8 && joy.up && Bup == 0){
				key.up = 1;
				goDuckUSDMove2(2,22,24,&ud2,&lr2,&duck2);
				key.up = 0;
			}
>>>>>>> Stashed changes
		}
		if (Bship1 == 1 && duck1.rl == 35 && joy.up) {
			four++;
			if (four == 5) {
			gotoxy(57,27+SS.ud);
			bgcolor(1);
			printf("      ");
			bgcolor(0);
			four = 0;
			Bship1 = 0;
			score += 200;
		}
		}
		if(duck1.ud == SS.ud && Bup == 1 && duck1.rl == 5 && joy.up == 1) {
			one++;
			if (one == 5) {
			gotoxy(26,27+SS.ud);
			bgcolor(5);
			fgcolor(0);
			printf("  UP  ");
			bgcolor(0);
			one = 0;
			Bup = 0;
			score += 200;
		}
		}
		if(duck1.ud == SS.ud && Bup == 1 && duck1.rl != 5) {
			goDuckUP1(1,22,24,&ud1,&lr1,&duck1);
		}


		if(duck1.ud == SS.ud + 4 || duck1.ud == SS.ud - 4){
<<<<<<< Updated upstream
		goDuck1MID(22,24,&ud,&lr,&duck1);
		if(duck1.rl == 55 && joy.right && !CJoy.right){
			canonFire(SS.ud);
=======
		goDuckMID1(1,22,24,&ud1,&lr1,&duck1);
		if(duck1.rl == 55 && joy.right && !CJoy.right && Bcanon == 0){
			shoot(SS.ud);
>>>>>>> Stashed changes
		}
		if(duck1.rl == 55 && joy.right && !CJoy.right && Bcanon == 1){
			three++;
			if (three == 5) {
			gotoxy(83,29+SS.ud);
			fgcolor(0);
			bgcolor(7);
			printf(" CANON");
			bgcolor(0);
			three = 0;
			Bcanon = 0;
			score += 200;
			}
		}
		}

<<<<<<< Updated upstream
		if(duck1.ud == SS.ud+8) {
		goDuck1USD(22,24,&ud,&lr,&duck1);
=======
		if(duck1.ud == SS.ud+8 && Bdown == 0 && !(Bship2 == 1 && duck1.rl == 25) && !(Bship3 == 1 && duck1.rl == 55)) {
		goDuckUSD1(1,22,24,&ud1,&lr1,&duck1);
		if (duck1.rl == 5 && duck2.ud == SS.ud && joy.up && Bdown == 0){
			key.down = 1;
			goDuckUPMove2(2,22,24,&ud2,&lr2,&duck2);
			key.down = 0;
		}
		if (duck1.rl == 5 && duck2.ud == SS.ud + 4 && joy.up && Bdown == 0){
			key.down = 1;
			goDuckMIDMove2(2,22,24,&ud2,&lr2,&duck2);
			key.down = 0;
		}
		if (duck1.rl == 5 && duck2.ud == SS.ud + 8 && joy.up && Bdown == 0){
		key.down = 1;
		goDuckUSDMove2(2,22,24,&ud2,&lr2,&duck2);
		key.down = 0;
		}
>>>>>>> Stashed changes
		}
		if (Bship2 == 1 && duck1.rl == 25 && joy.up) {
			five++;
			if (five == 5) {
			gotoxy(46,31+SS.ud);
			bgcolor(1);
			printf("      ");
			bgcolor(0);
			five = 0;
			Bship2 = 0;
			score += 200;
		}
		}
		if (Bship3 == 1 && duck1.rl == 55 && joy.up) {
			six++;
			if (six == 5) {
			gotoxy(76,31+SS.ud);
			bgcolor(1);
			printf("      ");
			bgcolor(0);
			six = 0;
			Bship3 = 0;
			score += 200;
		}
		}

<<<<<<< Updated upstream
		if(duck1.rl == 5 && joy.up && !CJoy.up && SS.ud == duck1.ud+1){
=======
		if(duck1.ud == SS.ud + 8 && Bdown == 1 && duck1.rl == 5 && joy.up == 1) {
					two++;
					if (two == 5) {
					gotoxy(26,27+SS.ud);
					bgcolor(5);
					fgcolor(0);
					printf("  UP  ");
					bgcolor(0);
					two = 0;
					Bdown = 0;
					score += 200;
				}
				}
				if(duck1.ud == SS.ud + 8 && Bdown == 1 && duck1.rl != 5) {
					goDuckUSD1(1,22,24,&ud1,&lr1,&duck1);
				}

		if(duck1.rl == 5 && joy.up && !CJoy.up && SS.ud == duck1.ud+1 & SS.ud != -20 && Bup == 0){
>>>>>>> Stashed changes
		spaceshipDelete(2,27+SS.ud,91,31+SS.ud);
		fireDelete(2,27+SS.ud,91,31+SS.ud);
		SS.ud = duck1.ud;
		spaceship(2,27+SS.ud,91,31+SS.ud);
		}

<<<<<<< Updated upstream
		if(duck1.rl == 5 && joy.up && !CJoy.up && SS.ud == duck1.ud-9){
=======
		if(duck1.rl == 5 && joy.up && !CJoy.up && SS.ud == duck1.ud-9 && SS.ud != 21 && Bdown == 0){
>>>>>>> Stashed changes
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


<<<<<<< Updated upstream
		copyJoystick();


=======




		if(duck2.ud == SS.ud && Bup == 0 && !(Bship1 == 1 && duck2.rl == 35)) {
		goDuckUP2(2,22,24,&ud2,&lr2,&duck2);
		if (duck2.rl == 5 && duck1.ud == SS.ud && key.up && Bup == 0){
			joy.up = 1;
			goDuckUPMove1(1,22,24,&ud1,&lr1,&duck1);
			joy.up = 0;
		}
		if (duck2.rl == 5 && duck1.ud == SS.ud + 4 && key.up && Bup == 0){
			joy.up = 1;
			goDuckMIDMove2(1,22,24,&ud1,&lr1,&duck1);
			joy.up = 0;
		}
		if (duck2.rl == 5 && duck1.ud == SS.ud + 8 && key.up && Bup == 0){
			joy.up = 1;
			goDuckUSDMove2(1,22,24,&ud1,&lr1,&duck1);
			joy.up = 0;
		}
		}
		if (Bship1 == 1 && duck2.rl == 35 && key.up) {
			four++;
			if (four == 5) {
			gotoxy(57,27+SS.ud);
			bgcolor(1);
			printf("      ");
			bgcolor(0);
			four = 0;
			Bship1 = 0;
			score += 200;
		}
		}
		if(duck2.ud == SS.ud && Bup == 1 && duck2.rl == 5 && key.up == 1) {
			one++;
			if (one == 5) {
			gotoxy(26,27+SS.ud);
			bgcolor(5);
			fgcolor(0);
			printf("  UP  ");
			bgcolor(0);
			one = 0;
			Bup = 0;
			score += 200;
		}
		}
		if(duck2.ud == SS.ud && Bup == 1 && duck2.rl != 5) {
			goDuckUP2(2,22,24,&ud2,&lr2,&duck2);
		}



		if(duck2.ud == SS.ud + 4 || duck2.ud == SS.ud - 4){
		goDuckMID2(2,22,24,&ud2,&lr2,&duck2);
		if(duck2.rl == 55 && key.right && Bcanon == 0){
			shoot(SS.ud);
		}
		if(duck2.rl == 55 && key.right && Bcanon == 1){
			three++;
			if (three == 5) {
			gotoxy(83,29+SS.ud);
			fgcolor(0);
			bgcolor(7);
			printf(" CANON");
			bgcolor(0);
			three = 0;
			Bcanon = 0;
			score += 200;
			}
		}
		}

		if(duck2.ud == SS.ud+8 && Bdown == 0 && !(Bship2 == 1 && duck2.rl == 25) && !(Bship3 == 1 && duck2.rl == 55)) {
		goDuckUSD2(2,22,24,&ud2,&lr2,&duck2);
		if (duck2.rl == 5 && duck1.ud == SS.ud && key.up && Bdown == 0){
			joy.down = 1;
			goDuckUPMove2(1,22,24,&ud1,&lr1,&duck1);
			joy.down = 0;
		}
		if (duck2.rl == 5 && duck1.ud == SS.ud + 4 && key.up && Bdown == 0){
			joy.down = 1;
			goDuckMIDMove2(1,22,24,&ud1,&lr1,&duck1);
			joy.down = 0;
		}
		if (duck2.rl == 5 && duck1.ud == SS.ud + 8 && key.up && Bdown == 0){
		joy.down = 1;
		goDuckUSDMove2(1,22,24,&ud1,&lr1,&duck1);
		joy.down = 0;
		}
		}
		if (Bship2 == 1 && duck2.rl == 25 && key.up) {
			five++;
			if (five == 5) {
			gotoxy(46,31+SS.ud);
			bgcolor(1);
			printf("      ");
			bgcolor(0);
			five = 0;
			Bship2 = 0;
			score += 200;
		}
		}
		if (Bship3 == 1 && duck2.rl == 55 && key.up) {
			six++;
			if (six == 5) {
			gotoxy(76,31+SS.ud);
			bgcolor(1);
			printf("      ");
			bgcolor(0);
			six = 0;
			Bship3 = 0;
			score += 200;
		}
		}
		if(duck2.ud == SS.ud + 8 && Bdown == 1 && duck2.rl == 5 && key.up == 1) {
					two++;
					if (two == 5) {
					Bdown = 0;
					gotoxy(26,27+SS.ud);
					bgcolor(5);
					fgcolor(0);
					printf("  UP  ");
					bgcolor(0);
					two = 0;
					Bdown = 0;
					score += 200;
				}
				}
				if(duck2.ud == SS.ud + 8 && Bdown == 1 && duck2.rl != 5) {
					goDuckUSD2(2,22,24,&ud2,&lr2,&duck2);
				}

		if(duck2.rl == 5 && key.up && SS.ud == duck2.ud+1 && SS.ud != -20 && Bup == 0){
		spaceshipDelete(2,27+SS.ud,91,31+SS.ud);
		fireDelete(2,27+SS.ud,91,31+SS.ud);
		SS.ud -= 1;
		spaceship(2,27+SS.ud,91,31+SS.ud);
		}

		if(duck2.rl == 5 && key.up && SS.ud == duck2.ud-9 && SS.ud != 21 && Bdown == 0){
		spaceshipDelete(2,27+SS.ud,91,31+SS.ud);
		fireDelete(2,27+SS.ud,91,31+SS.ud);
		SS.ud += 1;
		spaceship(2,27+SS.ud,91,31+SS.ud);
		}

		if (key.up && duck2.rl != 5 && duck2.ud == SS.ud -1) {
		duckExplotion(22,24,&ud2,&lr2);
		playerInSpaceUSDR(2,23,32+SS.ud);
		ud2= SS.ud+8;
		lr2=0;
		duck2.ud = SS.ud+8;
		duck2.rl = 0;
		}
		if (duck2.rl == 65){
		duckExplotion(22,24,&ud2,&lr2);
		playerInSpaceUSDR(2,23,32+SS.ud);
		ud2= SS.ud+8;
		lr2=0;
		duck2.ud = SS.ud+8;
		duck2.rl = 0;
		}
		if (key.up && duck2.rl != 5 && duck2.ud == SS.ud + 9) {
		duckExplotion(22,24,&ud2,&lr2);
		playerInSpaceUSDR(2,23,32+SS.ud);
		ud2= SS.ud+8;
		lr2=0;
		duck2.ud = SS.ud+8;
		duck2.rl = 0;
		}

		buffer_lenght = uart_get_count();
//		gotoxy(30,10);
//		printf("%d", buffer_lenght);

		if (lcdUpdate > 0){
		//Keyboard input

		if (buffer_lenght > 0) {
			random = uart_get_char();
//			gotoxy(10,10);
//			printf("%c", random);
		}
		resetbgcolor();


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

		if (random == 'p'){

			while(1){
				clrscr();
				setFreq(0);
				random = uart_get_char();
				if (random == 'P'){
					break;
				}
			}
		}

		random = " ";
		}


			if(ast1.px-7 < 91 && ast1.py >= SS.ud+24 && ast1.py <= SS.ud+34){
			collision(a,b,SS.ud);
			tid.state = 1;
			ast1.state = 1;
			b++;
			if(b>6) {
				b = 0;
			}
			a++;
			if(a>4) {
				a = 0;
			}
			}

			//Debug a and B for Collision broke stuff stuff.
//			gotoxy(5,2);
//			printf("a:%d  b:%d",a,b);

		asteroidUpdate(SS.ud);
		copyJoystick();

		if(Bup == 0 && Bdown == 0 && Bcanon == 0 && Bship1 == 0 && Bship2 == 0 && Bship3 == 0) {
			tid.state = 0;
		}
		writeLed();
		score += 10;
>>>>>>> Stashed changes
	}
}
