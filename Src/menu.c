#include "ansi.h"
#include "joystick.h"
#include "LCD.h"

void menu(int *players, int *dif) {
	draw_main_menu();
	int selection = 1;
	int gameinit = 0;
	*players = 0;
	*dif = 0;

	while (gameinit == 0) {
		readJoystick();
		if (joy.up == 1) {
			while (joy.up == 1) {
				readJoystick();
			}
			if (selection > 1 && selection <= 4 ) {
				selection--;
			}
		}

		if (joy.down == 1) {
			while (joy.down == 1) {
				readJoystick();
			}
			if (selection >= 1 && selection < 4 ) {
				selection++;
			}
		}
		if (selection == 1) {
			lcd_write_string("  ", 2, 1);
			lcd_write_string("->", 1, 1);
			if (joy.center == 1) {
				while (joy.center == 1) {
					readJoystick();
				}
				*players = player_selection();
			}
		}
		if (selection == 2) {
			lcd_write_string("  ", 1, 1);
			lcd_write_string("  ", 3, 1);
			lcd_write_string("->", 2, 1);
			if (joy.center == 1) {
				while (joy.center == 1) {
					readJoystick();
				}
				*dif = difficulty();
			}
		}
		if (selection == 3) {
			lcd_write_string("  ", 2, 1);
			lcd_write_string("  ", 4, 1);
			lcd_write_string("->", 3, 1);
			if (joy.center == 1) {
				while (joy.center == 1) {
					readJoystick();
				}
				help_menu();
			}
		}
		if (selection == 4) {
			lcd_write_string("  ", 3, 1);
			lcd_write_string("->", 4, 1);
			if (joy.center == 1) {
				while (joy.center == 1) {
					readJoystick();
				}
				gameinit = 1;
			}

		}

	}
	memset(buffer, 0x00, 512);
	t.mn = 2;
	t.sk = 0;
	t.state = 1;
}

int player_selection() {
	int x = 0;
	int a;
	lcd_write_string("                   ", 1, 12);
	while (x == 0) {
		readJoystick();

		if (joy.right == 1) {
			a = 1;
		} else if (joy.left == 1) {
			a = 0;
		}
		if (a == 0) {
			lcd_write_string("<1 Player>", 1, 12);
		} else if (a == 1) {
			lcd_write_string("<2 Player>", 1, 12);
		}
		if (joy.center == 1 ) {
			lcd_write_string("Player Selection", 1, 12);
			if (a == 0) {
				lcd_write_string("<P1>", 1, 108);
			} else if (a == 1) {
				lcd_write_string("<P2>", 1, 108);
			}
			x = 1;
		}
	}
	while (joy.center == 1 ) {
		readJoystick();
	}
	return a;
}


int difficulty() {
	int x = 0;
	int a = 0;
	lcd_write_string("                ", 2, 12);
	lcd_write_string("<Easy>", 2, 12);
	while (x == 0) {
		readJoystick();
		if (joy.right == 1 && a <= 1) {
			while (joy.right == 1) {
				readJoystick();
			}
			a++;
		} else if (joy.left == 1 && a >= 1) {
			while (joy.left == 1) {
				readJoystick();
			}
			a--;
		}
		if (a == 0 ) {
			lcd_write_string_no_push("        ", 2, 12);
			lcd_write_string("<easy>", 2, 12);
		} else if (a == 1 ) {
			lcd_write_string("<normal>", 2, 12);
		} else if (a == 2 ) {
			lcd_write_string_no_push("        ", 2, 12);
			lcd_write_string("<hard>", 2, 12);
		}
		if (joy.center == 1 ) {
			lcd_write_string("Difficulty", 2, 12);
			if (a == 0) {
				lcd_write_string("<easy>", 2, 98);
			} else if (a == 1) {
				lcd_write_string("<norm>", 2, 98);
			} else if (a == 2) {
				lcd_write_string("<hard>", 2, 98);
			}
			x = 1;
		}
	}
	while (joy.center == 1 ) {
		readJoystick();
	}
	return a;
}

void help_menu() {
	int x = 0;
	lcd_write_string("!Help window on screen!", 3, 12);
	windowSmp(5,5,80,35);
	gotoxy(10,7);
	printf("Player 1 uses the joystick to move and center to shoot");
	gotoxy(10,10);
	printf("Player 2 uses WASD to move and E to shoot");
}

void draw_main_menu() {
	lcd_write_string("Player Selection", 1, 12);
	lcd_write_string("<P1>", 1, 108);
	lcd_write_string("Difficulty", 2, 12);
	lcd_write_string("<easy>", 2, 98);
	lcd_write_string("Help Menu", 3, 12);
	lcd_write_string("Start Game", 4, 12);
	lcd_write_string("->", 1, 1);
}
