#include "ansi.h"
#include "LCD.h"
#include "timer.h"

void LCD_gameplay() {
	int alarm = 0;
	int a = 0;
	draw_gameplay_start();
	while (1) {
		if (alarm == 1) {
			LCD_alarm();
			alarm = 0;
		}
	}

}

void draw_gameplay_start() {
	lcd_write_string("Score:", 1, 36);
	for (int i = 0; i < 128; i++) {
		buffer[128 + i] = 0x01;
	}
}

void draw_score() {
	char score_str[8];
	sprintf(score_str, "%d", score);
	lcd_write_string(score_str, 1, 66);
}

void LCD_alarm_old() {
	int x = 0;
	int a = 0;
	while (x == 0) {
		if (lcdUpdate == 0) {
			lcd_write_string_custom(3, 1, 2, 58);
			lcd_write_string_custom(4, 1, 2, 63);
			lcd_write_string_custom(5, 1, 3, 58);
			lcd_write_string_custom(6, 1, 3, 63);
			lcd_write_string_custom(7, 1, 2, 68);
			lcd_write_string_custom(8, 1, 3, 68);
			lcd_write_string_custom(9, 1, 2, 53);
			lcd_write_string_custom(10, 1, 3, 53);
			lcd_write_string("hall breach !!!", 4, 26);
		}
		if (lcdUpdate == 50) {
			for (int i = 0; i < 128; i++) {
					buffer[128 + i] = 0x01;
			}
			lcd_write_string_custom(11, 25, 3, 0);
		}
		if (lcdUpdate == 95) {
			while (lcdUpdate == 95) {
			}
			printf("%d", a);
			a++;
		}
		if (a >= 5) {
			x = 1;
		}
	}
}

int LCD_alarm() {
	if (t.ml == 50) {
		while (t.ml == 50) {
		}
		lcd_write_string_custom(3, 1, 2, 58);
		lcd_write_string_custom(4, 1, 2, 63);
		lcd_write_string_custom(5, 1, 3, 58);
		lcd_write_string_custom(6, 1, 3, 63);
		lcd_write_string_custom(7, 1, 2, 68);
		lcd_write_string_custom(8, 1, 3, 68);
		lcd_write_string_custom(9, 1, 2, 53);
		lcd_write_string_custom(10, 1, 3, 53);
		lcd_write_string("hull breach !!!", 4, 26);
		return 0;
	}
	else if (t.ml == 95) {
		while (t.ml == 95) {
		}
		for (int i = 0; i < 128; i++) {
			buffer[128 + i] = 0x01;
		}
		lcd_write_string_custom(11, 51, 3, 0);
		return 1;
	} else {
		return 0;
	}
}

void LCD_timer() {
	char milisec_str[3];
	char sec_str[2];
	char min_str[2];
	sprintf(milisec_str, "%d", t.ml);
	sprintf(sec_str, "%d", t.sk);
	sprintf(min_str, "%d", t.mn);
	lcd_write_string_no_push("0:00", 3, 55);
	/*
	if (t.ml >= 10) {
		lcd_write_string_no_push(milisec_str, 3, 73);
	} else if (t.ml <= 9) {
		lcd_write_string_no_push(milisec_str, 3, 78);
	}
	*/
	if (t.sk >= 10) {
		lcd_write_string_no_push(sec_str, 3, 65);
	} else if (t.sk <= 9) {
		lcd_write_string_no_push(sec_str, 3, 70);
	}
	lcd_write_string_no_push(min_str, 3, 55);
	lcd_write_string(":", 3, 60);
}
