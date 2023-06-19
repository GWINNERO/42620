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
	memset(buffer, 0x00, 512);
	lcd_write_string("Score:", 1, 36);
	for (int i = 0; i < 128; i++) {
		buffer[128 + i] = 0x01;
	}
	char score_str[8];
	sprintf(score_str, "%d", score);
	lcd_write_string(score_str, 1, 66);
}

void LCD_alarm() {
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
		}
		if (lcdUpdate == 50) {
			for (int i = 0; i < 128; i++) {
					buffer[128 + i] = 0x01;
			}
			lcd_write_string_custom(11, 128, 3, 0);
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
