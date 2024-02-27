#include "switch.h"

void Switches_Init() {
  DIO_InitClock(PORTF);
  DIO_LockAndCommit(PORTF);
  DIO_DigitalEnable(PORTF);
  DIO_SetInputPin(PORTF, 0);
  DIO_SetInputPin(PORTF, 4);
  //// INTIALIZE BUTTON 
  Interupt_Enable(PORTF_IRQ);       
  Interupt_GPIO_Config(EDGE,FALLING_OR_LOW,!BOTH_EDGES,UNMASK,PORTF,PIN0);
  Interupt_GPIO_Config(EDGE,FALLING_OR_LOW,!BOTH_EDGES,UNMASK,PORTF,PIN4);
  Interrupt_SetPriority(PORTF_IRQ,1);
  
  DIO_InitClock(PORTE);
  DIO_LockAndCommit(PORTE);
  DIO_DigitalEnable(PORTE);
  DIO_SetInputPin(PORTE, PIN1);
  Interupt_Enable(PORTE_IRQ);        
  Interupt_GPIO_Config(EDGE,!FALLING_OR_LOW,!BOTH_EDGES,UNMASK,PORTE,PIN1);
  Interrupt_SetPriority(PORTE,1);
  
}