#ifndef __TIMER_H__
#define __TIMER_H__

#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"
#include "types.h"
#include "Interupt.h"

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
#define TIMER3 3
#define TIMER4 4
#define TIMER5 5

#define WTIMER0 0
#define WTIMER0 1
#define WTIMER0 2
#define WTIMER0 3
#define WTIMER0 4
#define WTIMER0 5

#define CONF32 0X0
#define CONFRTC 0X1
#define CONF16 0X4

#define AFLAG 0
#define BFLAG 1

#define ONESHOT 1
#define PERIODIC 2
#define CAPTURE 3

#define DOWN 0
#define UP 1

#define FREQUENCY 16000

//#define TIMERA 0
//#define TIMERB 1


void TimerIntrp(uint8 Timer, uint8 timerAorBFlag);
void TimerDisbale(uint8 Timer, uint8 ABFlag);
void TimerEnable(uint8 Timer, uint8 ABFlag);

void TimerClockConfig(uint8 Timer, uint8 Config ,uint8 ABFlag, uint8 Mode, uint8 UpDownFlag); 
//void TimerIntrp(uint8 Timer);

void TimerLoad(uint8 Timer, uint32 value ,uint8 ABFlag );
void TimerPreScale(uint8 Timer,uint16 value ,uint8 ABFlag );




#endif