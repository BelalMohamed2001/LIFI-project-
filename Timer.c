#include "Timer.h"
#include "Interupt.h"

/*
void TimerIntrp(uint8 Timer, uint8 timerAorBFlag){
  switch (Timer) {
      //----- TIMER 0 -----//
  case 0: 
       Set_Bit(TIMER0_ICR_R,0);
       Set_Bit(TIMER0_IMR_R,0);
       if(timerAorBFlag == AFLAG)       Interupt_Enable(TIMER0AIRQ);
       else if(timerAorBFlag == AFLAG)       Interupt_Enable(TIMER0BIRQ);
       break;
       
       //----- TIMER 1 -----//
  case 1: 
       Set_Bit(TIMER1_ICR_R,0);
       Set_Bit(TIMER1_IMR_R,0);
       if(timerAorBFlag == AFLAG)       Interupt_Enable(TIMER1AIRQ);
       else if(timerAorBFlag == AFLAG)       Interupt_Enable(TIMER1BIRQ);
       break;
       
       //----- TIMER 2 -----//
  case 2: 
       Set_Bit(TIMER2_ICR_R,0);
       Set_Bit(TIMER2_IMR_R,0);
       if(timerAorBFlag == AFLAG)       Interupt_Enable(TIMER2AIRQ);
       else if(timerAorBFlag == AFLAG)       Interupt_Enable(TIMER2BIRQ);
       break;
       
       //----- TIMER 3 -----//
  case 3: 
      Set_Bit(TIMER3_ICR_R,0);
      Set_Bit(TIMER3_IMR_R,0);
      if(timerAorBFlag == AFLAG)       Interupt_Enable(TIMER3AIRQ);
      else if(timerAorBFlag == AFLAG)       Interupt_Enable(TIMER3BIRQ);
      break;
       
       //----- TIMER 4 -----//
  case 4: 
      Set_Bit(TIMER4_ICR_R,0);
      Set_Bit(TIMER3_IMR_R,4);
      if(timerAorBFlag == AFLAG)       Interupt_Enable(TIMER4AIRQ);
      else if(timerAorBFlag == AFLAG)       Interupt_Enable(TIMER4BIRQ);
       break;
  //----- TIMER 5 -----//
  case 5: 
      Set_Bit(TIMER5_ICR_R,0);
      Set_Bit(TIMER5_IMR_R,0);
      if(timerAorBFlag == AFLAG)       Interupt_Enable(TIMER5AIRQ);
      else if(timerAorBFlag == AFLAG)       Interupt_Enable(TIMER5BIRQ);       
      break;
      
   default:
    break; 
}


}

void TimerEnable(uint8 Timer, uint8 ABFlag){
  switch (Timer) {
      //----- TIMER 0 -----//
  case 0: 
    if(ABFlag == AFLAG)         Set_Bit(TIMER0_CTL_R,0);
    else if(ABFlag == BFLAG)         Set_Bit(TIMER0_CTL_R,8);
    break;
       
       //----- TIMER 1 -----//
  case 1: 
    if(ABFlag == AFLAG)         Set_Bit(TIMER1_CTL_R,0);
    else if(ABFlag == BFLAG)         Set_Bit(TIMER1_CTL_R,8);
    break;
       
       //----- TIMER 2 -----//
  case 2: 
    if(ABFlag == AFLAG)         Set_Bit(TIMER2_CTL_R,0);
    else if(ABFlag == BFLAG)         Set_Bit(TIMER2_CTL_R,8);
    break;
       
       //----- TIMER 3 -----//
  case 3: 
    if(ABFlag == AFLAG)         Set_Bit(TIMER3_CTL_R,0);
    else if(ABFlag == BFLAG)         Set_Bit(TIMER3_CTL_R,8);
    break;
    
       //----- TIMER 4 -----//
  case 4: 
    if(ABFlag == AFLAG)         Set_Bit(TIMER4_CTL_R,0);
    else if(ABFlag == BFLAG)         Set_Bit(TIMER4_CTL_R,8);
    break;
    
  //----- TIMER 5 -----//
  case 5: 
    if(ABFlag == AFLAG)         Set_Bit(TIMER5_CTL_R,0);
    else if(ABFlag == BFLAG)         Set_Bit(TIMER5_CTL_R,8);
    break;
    
default:
    break; 
}

} 
 
void TimerDisbale(uint8 Timer, uint8 ABFlag){
  switch (Timer) {
      //----- TIMER 0 -----//
  case 0: 
    if(ABFlag == AFLAG)     {Clear_Bit(TIMER0_CTL_R,0); }
    else if(ABFlag == BFLAG)  {Clear_Bit(TIMER0_CTL_R,8);}
    break;
       
       //----- TIMER 1 -----//
  case 1: 
    if(ABFlag == AFLAG)     {Clear_Bit(TIMER1_CTL_R,0); }
    else if(ABFlag == BFLAG)  {Clear_Bit(TIMER1_CTL_R,8);}
    break;
       
       //----- TIMER 2 -----//
  case 2: 
    if(ABFlag == AFLAG)     {Clear_Bit(TIMER2_CTL_R,0); }
    else if(ABFlag == BFLAG)  {Clear_Bit(TIMER2_CTL_R,8);}
    break;
       
       //----- TIMER 3 -----//
  case 3: 
    if(ABFlag == AFLAG)     {Clear_Bit(TIMER3_CTL_R,0); }
    else if(ABFlag == BFLAG)  {Clear_Bit(TIMER3_CTL_R,8);}
    break;
    
       //----- TIMER 4 -----//
  case 4: 
     if(ABFlag == AFLAG)     {Clear_Bit(TIMER4_CTL_R,0); }
    else if(ABFlag == BFLAG)  {Clear_Bit(TIMER4_CTL_R,8);}
    
  //----- TIMER 5 -----//
  case 5: 
     if(ABFlag == AFLAG)     {Clear_Bit(TIMER5_CTL_R,0); }
    else if(ABFlag == BFLAG)  {Clear_Bit(TIMER5_CTL_R,8);}
    
default:
    break; 
}

}
      //----- TIMER 0 -----//
  case 0: 
     if(ABFlag == AFLAG)       Clear_Bit(TIMER0_CTL_R,0);
     else if(ABFlag == AFLAG)       Clear_Bit(TIMER0_CTL_R,8);   
   
    break;
       
       //----- TIMER 1 -----//
  case 1: 
      if(ABFlag == AFLAG)         Clear_Bit(TIMER1_CTL_R,0);
      else if(ABFlag == BFLAG)         Clear_Bit(TIMER1_CTL_R,8);
       break;
       
       //----- TIMER 2 -----//
  case 2: 
      if(ABFlag == AFLAG)         Clear_Bit(TIMER2_CTL_R,0);
      else if(ABFlag == BFLAG)         Clear_Bit(TIMER2_CTL_R,8);
      break;
       //----- TIMER 3 -----//
  case 3: 
      if(ABFlag == AFLAG)         Clear_Bit(TIMER3_CTL_R,0);
      else if(ABFlag == BFLAG)         Clear_Bit(TIMER3_CTL_R,8);
      break;
       
       //----- TIMER 4 -----//
  case 4: 
      if(ABFlag == AFLAG)         Clear_Bit(TIMER4_CTL_R,0);
      else if(ABFlag == BFLAG)         Clear_Bit(TIMER4_CTL_R,8);
      break;
  //----- TIMER 5 -----//
  case 5: 
      if(ABFlag == AFLAG)         Clear_Bit(TIMER0_CTL_R,0);
      else if(ABFlag == BFLAG)         Clear_Bit(TIMER0_CTL_R,8);
      break;
default:
    break; 
}}

void TimerClockConfig(uint8 Timer, uint8 Config ,uint8 ABFlag, uint8 Mode, uint8 UpDownFlag){

Set_Bit(SYSCTL_RCGCTIMER_R,Timer);
TimerDisbale(Timer, ABFlag);

switch (Timer) {
      //----- TIMER 0 -----//
  case 0: 
      TIMER0_CFG_R |= Config;
      if (ABFlag == AFLAG){
        Set_Bit(TIMER0_CTL_R,AFLAG);
        TIMER0_TAMR_R |= Mode;
        TIMER0_TAMR_R |= (UpDownFlag << 2);

      }
      else{
        Set_Bit(TIMER0_CTL_R,BFLAG);
        TIMER0_TBMR_R |= Mode;
        TIMER0_TBMR_R |= (UpDownFlag << 2);
      }
       break;
       
       //----- TIMER 1 -----//
  case 1: 
      TIMER1_CFG_R |= Config;
      if (ABFlag == AFLAG){
        Set_Bit(TIMER1_CTL_R,AFLAG);
        TIMER1_TAMR_R |= Mode;
        TIMER1_TAMR_R |= (UpDownFlag << 2);
      }
      else{
      Set_Bit(TIMER1_CTL_R,BFLAG);
      TIMER1_TBMR_R |= Mode;
      TIMER1_TBMR_R |= (UpDownFlag << 2);
      }
       break;
       
       //----- TIMER 2 -----//
  case 2: 
      TIMER2_CFG_R |= Config;
      TIMER2_TAMR_R |= Mode;
      if (AFLAG){
        Set_Bit(TIMER2_CTL_R,AFLAG);
        TIMER2_TAMR_R |= Mode;
        TIMER2_TAMR_R |= (UpDownFlag << 2);
      }
      else{
      Set_Bit(TIMER2_CTL_R,BFLAG);
      TIMER2_TBMR_R |= Mode;
      TIMER2_TBMR_R |= (UpDownFlag << 2);
      }
       break;
       
       //----- TIMER 3 -----//
  case 3: 
      TIMER3_CFG_R |= Config;
      if (AFLAG){
        Set_Bit(TIMER3_CTL_R,AFLAG);
        TIMER3_TAMR_R |= Mode;
        TIMER3_TAMR_R |= (UpDownFlag << 2);
      }
      else{
      Set_Bit(TIMER3_CTL_R,BFLAG);
      TIMER3_TBMR_R |= Mode;
      TIMER3_TBMR_R |= (UpDownFlag << 2);
      }
       break;
       
       //----- TIMER 4 -----//
  case 4: 
      TIMER4_CFG_R |= Config;
      if (AFLAG){
        Set_Bit(TIMER4_CTL_R,AFLAG);
        TIMER4_TAMR_R |= Mode;
        TIMER4_TAMR_R |= (UpDownFlag << 2);
      }
      else{
      Set_Bit(TIMER4_CTL_R,BFLAG);
      TIMER4_TBMR_R |= Mode;
      TIMER4_TBMR_R |= (UpDownFlag << 2);
      }
       break;
  //----- TIMER 5 -----//
  case 5: 
      TIMER5_CFG_R |= Config;
      if (AFLAG){
        Set_Bit(TIMER5_CTL_R,AFLAG);
        TIMER5_TAMR_R |= Mode;
        TIMER5_TAMR_R |= (UpDownFlag << 2);
      }
      else{
      Set_Bit(TIMER5_CTL_R,BFLAG);
      TIMER5_TBMR_R |= Mode;
      TIMER5_TBMR_R |= (UpDownFlag << 2);
      }
       break;
default:
    break; 
}

} 

void TimerLoad(uint8 Timer,uint32 value ,uint8 ABFlag){
  switch (Timer) {
    
    value = (value*FREQUENCY)-1; // from sec to ticks
      //----- TIMER 0 -----//
  case 0: 
      if (AFLAG){
        TIMER0_TAILR_R |= value;
      }
      else{
    TIMER0_TBILR_R |= value;
      }
       break;
       
       //----- TIMER 1 -----//
  case 1:  
      if (AFLAG){
        TIMER1_TAILR_R |= value;
      }
      else{
    TIMER1_TBILR_R |= value;
      }
       break;
       
       //----- TIMER 2 -----//
  case 2: 
      if (AFLAG){
        TIMER2_TAILR_R |= value;
      }
      else{
    TIMER2_TBILR_R |= value;
      }
       break;
       
       //----- TIMER 3 -----//
  case 3: 
      if (AFLAG){
        TIMER3_TAILR_R |= value;
      }
      else{
    TIMER3_TBILR_R |= value;
      }
       break;
       
       //----- TIMER 4 -----//
  case 4: 
      if (AFLAG){
        TIMER4_TAILR_R |= value;
      }
      else{
    TIMER4_TBILR_R |= value;
      }
       break;
  //----- TIMER 5 -----//
  case 5: 
      if (AFLAG){
        TIMER5_TAILR_R |= value;
      }
      else{
    TIMER5_TBILR_R |= value;
      }
       break;
default:
    break; 
}  
  }

void TimerPreScale(uint8 Timer,uint16 value ,uint8 ABFlag ){
 switch (Timer) {
      //----- TIMER 0 -----//
  case 0: 
      if (ABFlag == AFLAG){
        TIMER0_TAPR_R |= value;
      }
      else{
    TIMER0_TBPR_R |= value;
      }
       break;
       
       //----- TIMER 1 -----//
  case 1:  
      if (ABFlag == AFLAG){
        TIMER1_TAPR_R |= value;
      }
      else{
    TIMER1_TBPR_R |= value;
      }
       break;
       
       //----- TIMER 2 -----//
  case 2: 
      if (AFLAG){
        TIMER2_TAPR_R |= value;
      }
      else{
    TIMER2_TBPR_R |= value;
      }
       break;
       
       //----- TIMER 3 -----//
  case 3: 
      if (ABFlag == AFLAG){
        TIMER3_TAPR_R |= value;
      }
      else{
    TIMER3_TBPR_R |= value;
      }
       break;
       
       //----- TIMER 4 -----//
  case 4: 
      if (AFLAG){
        TIMER4_TAPR_R |= value;
      }
      else{
    TIMER4_TBPR_R |= value;
      }
       break;
  //----- TIMER 5 -----//
  case 5: 
      if (AFLAG){
        TIMER5_TAPR_R |= value;
      }
      else{
    TIMER5_TBPR_R |= value;
      }
       break;

}
}*/
