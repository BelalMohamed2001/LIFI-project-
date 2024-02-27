#ifndef UART_H
#define UART_H

#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "types.h"

#define UART0 0
#define UART1 1
#define UART2 2
#define UART3 3
#define UART4 4
#define UART5 5
#define UART6 6
#define UART7 7

#define SYSCLK 16000000

#define SYSCLKMODE 0
#define PIOSCMODE 5

#define TXEPIN  8
#define RXEPIN  9

#define TRANSMITFLAG 1
#define RECEIVEFLAG 1

#define WLEN5  0
#define WLEN6  1
#define WLEN7  2
#define WLEN8  3

#define RXFEPIN 4
#define TXFFPIN 5


void Uart_Init(uint8 uart, uint32 baudRate, uint8 mode);
void Uart_Control(uint8 uart, uint8 transmitFlag, uint8 recieveFlag, uint8 wlen);
uint8 Uart_RX(uint8 uart);
void Uart_TX(uint8 uart, uint8 c);

#endif