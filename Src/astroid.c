#include "stdio.h"
#include "ansi_S.h"
#include "astroid.h"
#include "joystick.h"
#include "timer.h"

void initAstro(){
	bllt.px = 0;
	bllt.py = 0;
	bllt.vx = 0;
	bllt.vy = 0;

	ast1.px = 175;
	ast1.py = 29;
	ast1.vx = -1;
	ast1.vy = 0;

//	ast2.px = 40;
//	ast2.py = 39;
//	ast2.vx = -2;
//	ast2.vy = 0;


}


void asteroidUpdate(spaceship_t *S){
	moveBullet();
	asteroid1(S);
//	asteroid2();
}

void readjoy() {

	if (timeState) {
		if (joy.up) {
			ast1.py -= 1;
		} else if (joy.down) {
			ast1.py += 1;
		} else if (joy.left) {
			ast1.px -= 2;
		} else if (joy.right) {
			ast1.px += 2;
		}
	}
}


void shoot(spaceship_t S){
bllt.state = 1;
bllt.px = 92;
bllt.py = S.ud+29;
}

void moveBullet(){
	setFreq(0);
	if (bllt.state){
		drawBullet();
		setFreq(10);
	}

	//Debug Bullet
//	gotoxy(5,7);
//	printf("Bullet: %03d, %03d, %d", bllt.px, bllt.py, bllt.state);
}

void drawBullet(){
	gotoxy(bllt.px,bllt.py);

	for (int j=0;j<9;j++){
		printf("%c",32);
	}

	if (bllt.px < 183-9){
	bllt.px += 6;
	gotoxy(bllt.px,bllt.py);

	for(int i=0; i<3;i++){
		for (int j=0;j<3;j++){
			printf("%c",176+i);
		}
	}

//	printf("%c%c%c",176,177,178);
	if (bllt.px <= ast1.px+10 && bllt.px >= ast1.px && bllt.py >= ast1.py-3 && bllt.py <= ast1.py+3){
		for (int j=0;j<9;j++){
			printf("%c",32);
		}


		ast1.state = 1;
		ast1.vx -= 1;
		bllt.state = 0;
		setFreq(20);
//		gotoxy(5,6);
//		printf("Hit! %d",ast1.vx);
	}

	}
	else{

		for (int j=0;j<9;j++){
			printf("%c",32);
		}

		bllt.state = 0;
		bllt.px = 6;
	}





}

void asteroid1(spaceship_t ship){
	int pos = ship.ud+29;
	static int i;
	gotoxy(ast1.px,ast1.py+29);
	clearAsteroSmall(ast1.px, ast1.py);

	ast1.px += ast1.vx;

	switch(i){
		case 3:
			i = 0;

			ast1.py += ast1.vy;
			if(ast1.py > pos && ast1.vy != -1){
				ast1.vy -= 1;
			}else if (ast1.py < pos && ast1.vy != 1){
				ast1.vy += 1;
			}



			break;

		default:
			i++;
			break;
	}

	//Debug astroid
//	gotoxy(5,4);
//	printf("ast: %03d,%02d | %03d, %03d | pos: %d",ast1.px, ast1.py, ast1.vx, ast1.vy, pos);


	if (ast1.px <= 10 || ast1.py >= 60 || ast1.py < 5 || ast1.state){
		ast1.px = 178;

		ast1.py += 5;

		ast1.vy = 0;
		ast1.state = 0;
		setFreq(0);
	}


	drawAsteroidSmall(ast1.px, ast1.py);
}




void asteroid2(){

	gotoxy(ast2.px,ast2.py);
	printf("%c",32);
	drawAsteroidMedium(ast2.px, ast2.py);


	ast2.px = ast2.px + ast2.vx;
	ast2.py = ast2.py + ast2.vy;

	//Debug astroid
//	gotoxy(4,5);
//	printf("%03d,%02d | %d, %d",ast2.px, ast2.py, ast2.vx, ast2.vy);


	if (ast2.px <= 20){
		ast2.px = 110;
	}

	gotoxy(ast2.px,ast2.py);
	printf("%c",42);


}



void clearAsteroSmall(int16_t x, int16_t y) {
    gotoxy(x - 3, y - 2);
    printf("       ");
    gotoxy(x - 4, y - 1);
    printf("         ");
    gotoxy(x - 5, y);
    printf("           ");
    gotoxy(x - 4, y + 1);
    printf("         ");
    gotoxy(x - 3, y + 2);
    printf("       ");
}

void drawAsteroidSmall(int16_t x, int16_t y) {
    gotoxy(x - 3, y - 2);
    printf(".-~~~-.");

    gotoxy(x - 4, y - 1);
    printf("/ O     \\");

    gotoxy(x - 5, y);
    printf(":      o  :");

    gotoxy(x - 4, y + 1);
    printf("\\  O    /");

    gotoxy(x - 3, y + 2);
    printf("` ~~~ '");
}



void drawAsteroidMedium(int16_t x, int16_t y) {
    gotoxy(x - 8, y - 3);
    printf("    .-~~~-. ");

    gotoxy(x - 8, y - 2);
    printf(" .-`   O   `-. ");

    gotoxy(x - 8, y - 1);
    printf("/    o     O   \\ ");

    gotoxy(x - 8, y);
    printf(":     o     o   : ");

    gotoxy(x - 8, y + 1);
    printf(" \\    O     o   / ");

    gotoxy(x - 8, y + 2);
    printf("  `.   o    O .' ");

    gotoxy(x - 8, y + 3);
    printf("    `.-~~~~-.' ");
}

