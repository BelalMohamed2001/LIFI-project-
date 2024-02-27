#ifndef __INTERUPT_H__
#define __INTERUPT_H__

#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"
#include "types.h"

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

#define PORTA_IRQ 0
#define PORTB_IRQ 1
#define PORTC_IRQ 2
#define PORTD_IRQ 3
#define PORTE_IRQ 4
#define PORTF_IRQ 30

#define TIMER0AIRQ 19
#define TIMER0BIRQ 20
#define TIMER1AIRQ 21
#define TIMER1BIRQ 22
#define TIMER2AIRQ 23
#define TIMER2BIRQ 24
#define TIMER3AIRQ 35
#define TIMER3BIRQ 36
#define TIMER4AIRQ 70
#define TIMER4BIRQ 71
#define TIMER5AIRQ 92
#define TIMER5BIRQ 93

#define EDGE 0
#define LEVEL 1
#define FALLING_OR_LOW 0
#define RISING_OR_HIGH 1
#define BOTH_EDGES 1

#define MASK 0
#define UNMASK 1 


//void Interupt_Init(uint8 pin);

void Interupt_Enable(uint8 IRQ);
void Interupt_GPIO_Config(uint8 lvlFlag, uint8 risingOrHighFlag, uint8 bothEdgesFlag, uint8 maskFlag, uint8 port, uint8 pin);
void Interupt_Disable(uint8 IRQ);
void Interrupt_SetPriority(uint8 IRQ, uint8 priority);


#endif