#include "stm32f30x_conf.h" // STM32 config
#include "ansi_S.h"
#ifndef JOYSTICK_H_
#define JOYSTICK_H_

void readJoystick();
void intiJoystick();

typedef struct{
	int8_t up, down, left , right, center;
} reJoy_s;



volatile reJoy_s key;
volatile reJoy_s joy;
volatile reJoy_s CJoy;

#endif /* JOYSTICK_H_ */
