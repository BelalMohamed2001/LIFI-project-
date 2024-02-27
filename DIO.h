#ifndef __DIO_H__
#define __DIO_H__

#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"
#include "types.h"

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define INPUT 0
#define OUTPUT 1

void DIO_InitClock(int port);
void DIO_LockAndCommit(int port);
void DIO_SetInputPin(int port, int pin);
void DIO_SetOutputPin(int port, int pin);
void DIO_DigitalEnable(int port);

void DIO_Init(int port, int pin, int direction);

void DIO_WritePin(int port,int pin, int data);
void DIO_WritePort(int port,int data);

int DIO_ReadPin(int port,int pin);
int DIO_ReadPort(int port);

void GPIO_AlternateFunc(uint8 port, uint8 pin, uint8 func);

void DIO_Toggle(int port,int pin);

void delayUs(uint32 d);
void delayMs(uint32 d);


#endif