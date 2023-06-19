#ifndef TIMER_H_
#define TIMER_H_
void initTimer();
void TIM1_BRK_TIM15_IRQHandler(void);
void TIM2_IRQHandler(void);
void initTimerStop();
void initTimerStart();
void initTimer2();
void initBuzz();

#endif /* TIMER_H_ */
