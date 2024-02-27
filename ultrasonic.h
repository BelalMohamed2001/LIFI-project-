#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include <stdint.h>

void Send_Trigger(void);
void Timer0ACapture_init(void);
void Delay_MicroSecond(int time);

#endif
