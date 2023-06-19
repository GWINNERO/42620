#pragma once
#define ESC 0x1B

#include "stdint.h"
#include "stdio.h"
#include "stm32f30x_conf.h"

typedef struct{
	int8_t ud, rl;
} duck_t;

typedef struct{
	int8_t ud;
} spaceship_t;

typedef struct{
	int red, blu, gre;
} led_s;

volatile led_s led;

volatile int lcdUpdate, refreshRate;

void clreol();
void clrscr();
void fat(int state);
void resetbgcolor();
void underline(int state);
void gotoxy(int c, int r);
void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void spaceship(int x1, int y1, int x2, int y2);
void startWindow(int x1, int y1, int x2, int y2);
void color(uint8_t foreground, uint8_t background);
void goDuck1(int x, int y, int *ud, int *rl,duck_t * D);

