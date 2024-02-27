#include "magnetic.h"

void Magnetic_Init(){
   DIO_InitClock(PORTD);
  DIO_LockAndCommit(PORTD);
  DIO_DigitalEnable(PORTD);
  //// INTIALIZE BUTTON 
    DIO_SetInputPin(PORTD,PIN1);
   Interupt_Enable(PORTD_IRQ);
  Interupt_GPIO_Config(EDGE,RISING_OR_HIGH,!BOTH_EDGES,UNMASK,PORTD,1);
  
  

    
  
}

