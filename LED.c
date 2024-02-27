#include "LED.h"
void LED_Init(){
  DIO_InitClock(PORTC);
   DIO_LockAndCommit(PORTC);
   DIO_DigitalEnable(PORTC);
   DIO_SetOutputPin(PORTC, PIN7);
//   DIO_WritePin(PORTC,PIN7,1);
}
