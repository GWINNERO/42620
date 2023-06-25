#include "stm32f30x_conf.h" // STM32 config
#include "ansi_S.h"
#ifndef JOYSTICK_H_
#define JOYSTICK_H_

int16_t readJoystick();
void intiJoystick();

typedef struct{
	int8_t up, down, left , right, center;
} reJoy_s;

typedef struct{
	int8_t up, down, left , right, center;
} copyJoy_s;


<<<<<<< Updated upstream

=======
volatile reJoy_s key;
>>>>>>> Stashed changes
volatile reJoy_s joy;
volatile copyJoy_s CJoy;

#endif /* JOYSTICK_H_ */
