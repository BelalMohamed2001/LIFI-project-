#include "Interupt.h"

void Interupt_Enable(uint8 IRQ){
  if(IRQ>=0 && IRQ <=31)
    Set_Bit(NVIC_EN0_R, IRQ);
  
  else if(IRQ>=32 && IRQ<=63)
    Set_Bit(NVIC_EN1_R, IRQ);
  
  else if(IRQ>=64 && IRQ<=95)
    Set_Bit(NVIC_EN2_R, IRQ);
  
  else if(IRQ>=96 && IRQ<=127)
    Set_Bit(NVIC_EN3_R, IRQ);
  
  else if(IRQ>128 && IRQ<=138)
    Set_Bit(NVIC_EN4_R, IRQ);
}

void Interupt_Disable(uint8 IRQ){
  if(IRQ>=0 && IRQ <=31)
    Set_Bit(NVIC_DIS0_R, IRQ);
  
  else if(IRQ>=32 && IRQ<=63)
    Set_Bit(NVIC_DIS1_R, IRQ);
  
  else if(IRQ>=64 && IRQ<=95)
    Set_Bit(NVIC_DIS2_R, IRQ);
  
  else if(IRQ>=96 && IRQ<=127)
    Set_Bit(NVIC_DIS3_R, IRQ);
  
  else if(IRQ>128 && IRQ<=138)
    Set_Bit(NVIC_DIS4_R, IRQ);
}

void Interupt_GPIO_Config(uint8 lvlFlag, uint8 risingOrHighFlag, uint8 bothEdgesFlag, uint8 maskFlag, uint8 port, uint8 pin){
  switch (port){
    // PORTA
    case PORTA:
      // Level or Edge
      if(lvlFlag == LEVEL)
        Set_Bit(GPIO_PORTA_IS_R,pin);
      else if(lvlFlag == EDGE)
        Clear_Bit(GPIO_PORTA_IS_R,pin);
      // (High or Low Level) or (Rising or Falling Edge)
      if(risingOrHighFlag == RISING_OR_HIGH)
        Set_Bit(GPIO_PORTA_IEV_R,pin);
      else if(risingOrHighFlag == FALLING_OR_LOW)
        Clear_Bit(GPIO_PORTA_IEV_R,pin);
      // Enable or Disbale both Edges
      if(bothEdgesFlag == BOTH_EDGES)
        Set_Bit(GPIO_PORTA_IBE_R,pin);
      else if(bothEdgesFlag == !BOTH_EDGES)
        Clear_Bit(GPIO_PORTA_IBE_R,pin);
      // Clear any prior interrupts
        Set_Bit(GPIO_PORTA_ICR_R,pin);
      // Unmasking or Masking Pin 
      if(maskFlag == UNMASK)
        Set_Bit(GPIO_PORTA_IM_R,pin);
      else if(maskFlag == MASK)
        Clear_Bit(GPIO_PORTA_IM_R,pin);
      break;
      
      // PORTB
    case PORTB:
      // Level or Edge
      if(lvlFlag == LEVEL)
        Set_Bit(GPIO_PORTB_IS_R,pin);
      else if(lvlFlag == EDGE)
        Clear_Bit(GPIO_PORTB_IS_R,pin);
      // (High or Low Level) or (Rising or Falling Edge)
      if(risingOrHighFlag == RISING_OR_HIGH)
        Set_Bit(GPIO_PORTB_IEV_R,pin);
      else if(risingOrHighFlag == FALLING_OR_LOW)
        Clear_Bit(GPIO_PORTB_IEV_R,pin);
      // Enable or Disbale both Edges
      if(bothEdgesFlag == BOTH_EDGES)
        Set_Bit(GPIO_PORTB_IBE_R,pin);
      else if(bothEdgesFlag == !BOTH_EDGES)
        Clear_Bit(GPIO_PORTB_IBE_R,pin);
      // Clear any prior interrupts
        Set_Bit(GPIO_PORTB_ICR_R,pin);
      // Unmasking or Masking Pin 
      if(maskFlag == UNMASK)
        Set_Bit(GPIO_PORTB_IM_R,pin);
      else if(maskFlag == MASK)
        Clear_Bit(GPIO_PORTB_IM_R,pin);
      break;
      
      // PORTC
    case PORTC:
      // Level or Edge
      if(lvlFlag == LEVEL)
        Set_Bit(GPIO_PORTC_IS_R,pin);
      else if(lvlFlag == EDGE)
        Clear_Bit(GPIO_PORTC_IS_R,pin);
      // (High or Low Level) or (Rising or Falling Edge)
      if(risingOrHighFlag == RISING_OR_HIGH)
        Set_Bit(GPIO_PORTC_IEV_R,pin);
      else if(risingOrHighFlag == FALLING_OR_LOW)
        Clear_Bit(GPIO_PORTC_IEV_R,pin);
      // Enable or Disbale both Edges
      if(bothEdgesFlag == BOTH_EDGES)
        Set_Bit(GPIO_PORTC_IBE_R,pin);
      else if(bothEdgesFlag == !BOTH_EDGES)
        Clear_Bit(GPIO_PORTC_IBE_R,pin);
      // Clear any prior interrupts
        Set_Bit(GPIO_PORTC_ICR_R,pin);
      // Unmasking or Masking Pin 
      if(maskFlag == UNMASK)
        Set_Bit(GPIO_PORTC_IM_R,pin);
      else if(maskFlag == MASK)
        Clear_Bit(GPIO_PORTC_IM_R,pin);
      break;
      
       // PORTD
    case PORTD:
      // Level or Edge
      if(lvlFlag == LEVEL)
        Set_Bit(GPIO_PORTD_IS_R,pin);
      else if(lvlFlag == EDGE)
        Clear_Bit(GPIO_PORTD_IS_R,pin);
      // (High or Low Level) or (Rising or Falling Edge)
      if(risingOrHighFlag == RISING_OR_HIGH)
        Set_Bit(GPIO_PORTD_IEV_R,pin);
      else if(risingOrHighFlag == FALLING_OR_LOW)
        Clear_Bit(GPIO_PORTD_IEV_R,pin);
      // Enable or Disbale both Edges
      if(bothEdgesFlag == BOTH_EDGES)
        Set_Bit(GPIO_PORTD_IBE_R,pin);
      else if(bothEdgesFlag == !BOTH_EDGES)
        Clear_Bit(GPIO_PORTD_IBE_R,pin);
      // Clear any prior interrupts
        Set_Bit(GPIO_PORTD_ICR_R,pin);
      // Unmasking or Masking Pin 
      if(maskFlag == UNMASK)
        Set_Bit(GPIO_PORTD_IM_R,pin);
      else if(maskFlag == MASK)
        Clear_Bit(GPIO_PORTD_IM_R,pin);
      break;
      
       // PORTE
    case PORTE:
      // Level or Edge
      if(lvlFlag == LEVEL)
        Set_Bit(GPIO_PORTE_IS_R,pin);
      else if(lvlFlag == EDGE)
        Clear_Bit(GPIO_PORTE_IS_R,pin);
      // (High or Low Level) or (Rising or Falling Edge)
      if(risingOrHighFlag == RISING_OR_HIGH)
        Set_Bit(GPIO_PORTE_IEV_R,pin);
      else if(risingOrHighFlag == FALLING_OR_LOW)
        Clear_Bit(GPIO_PORTE_IEV_R,pin);
      // Enable or Disbale both Edges
      if(bothEdgesFlag == BOTH_EDGES)
        Set_Bit(GPIO_PORTE_IBE_R,pin);
      else if(bothEdgesFlag == !BOTH_EDGES)
        Clear_Bit(GPIO_PORTE_IBE_R,pin);
      // Clear any prior interrupts
        Set_Bit(GPIO_PORTE_ICR_R,pin);
      // Unmasking or Masking Pin 
      if(maskFlag == UNMASK)
        Set_Bit(GPIO_PORTE_IM_R,pin);
      else if(maskFlag == MASK)
        Clear_Bit(GPIO_PORTE_IM_R,pin);
      break;
      
      case PORTF:
      // Level or Edge
      if(lvlFlag == LEVEL)
        Set_Bit(GPIO_PORTF_IS_R,pin);
      else if(lvlFlag == EDGE)
        Clear_Bit(GPIO_PORTF_IS_R,pin);
      // (High or Low Level) or (Rising or Falling Edge)
      if(risingOrHighFlag == RISING_OR_HIGH)
        Set_Bit(GPIO_PORTF_IEV_R,pin);
      else if(risingOrHighFlag == FALLING_OR_LOW)
        Clear_Bit(GPIO_PORTF_IEV_R,pin);
      // Enable or Disbale both Edges
      if(bothEdgesFlag == BOTH_EDGES)
        Set_Bit(GPIO_PORTF_IBE_R,pin);
      else if(bothEdgesFlag == !BOTH_EDGES)
        Clear_Bit(GPIO_PORTF_IBE_R,pin);
      // Clear any prior interrupts
        Set_Bit(GPIO_PORTF_ICR_R,pin);
      // Unmasking or Masking Pin 
      if(maskFlag == UNMASK)
        Set_Bit(GPIO_PORTF_IM_R,pin);
      else if(maskFlag == MASK)
        Clear_Bit(GPIO_PORTF_IM_R,pin);
      break;
  }
}

void Interrupt_SetPriority(uint8 IRQ, uint8 priority){
  uint8 shift;
  switch (IRQ % 4){
    case 0: shift = 5; break;
    case 1: shift = 13; break;
    case 2: shift = 21; break;
    case 3: shift = 29; break;
  }
   if(IRQ>=0 && IRQ<=3)         NVIC_PRI0_R |= priority << shift;
   else if(IRQ>=4 && IRQ<=7)    NVIC_PRI1_R |= priority << shift;
   else if(IRQ>=8 && IRQ<=11)   NVIC_PRI2_R |= priority << shift;
   else if(IRQ>=12 && IRQ<=15)  NVIC_PRI3_R |= priority << shift;
   else if(IRQ>=16 && IRQ<=19)  NVIC_PRI4_R |= priority << shift;
   else if(IRQ>=20 && IRQ<=23)  NVIC_PRI5_R |= priority << shift;
   else if(IRQ>=24 && IRQ<=27)  NVIC_PRI6_R |= priority << shift;
   else if(IRQ>=28 && IRQ<=31)  NVIC_PRI7_R |= priority << shift;
   else if(IRQ>=32 && IRQ<=35)  NVIC_PRI8_R |= priority << shift;
   else if(IRQ>=36 && IRQ<=39)  NVIC_PRI9_R |= priority << shift;
   else if(IRQ>=40 && IRQ<=43)  NVIC_PRI10_R |= priority << shift;
   else if(IRQ>=44 && IRQ<=47)  NVIC_PRI11_R |= priority << shift;
   else if(IRQ>=48 && IRQ<=51)  NVIC_PRI12_R |= priority << shift;
   else if(IRQ>=52 && IRQ<=55)  NVIC_PRI13_R |= priority << shift;
   else if(IRQ>=56 && IRQ<=59)  NVIC_PRI14_R |= priority << shift;
   else if(IRQ>=60 && IRQ<=63)  NVIC_PRI15_R |= priority << shift;
   else if(IRQ>=64 && IRQ<=67)  NVIC_PRI16_R |= priority << shift;
   else if(IRQ>=68 && IRQ<=71)  NVIC_PRI17_R |= priority << shift;
   else if(IRQ>=72 && IRQ<=75)  NVIC_PRI18_R |= priority << shift;
   else if(IRQ>=76 && IRQ<=79)  NVIC_PRI19_R |= priority << shift;
   else if(IRQ>=80 && IRQ<=83)  NVIC_PRI20_R |= priority << shift;
   else if(IRQ>=84 && IRQ<=87)  NVIC_PRI21_R |= priority << shift;
   else if(IRQ>=88 && IRQ<=91)  NVIC_PRI22_R |= priority << shift;
   else if(IRQ>=92 && IRQ<=95)  NVIC_PRI23_R |= priority << shift;
   else if(IRQ>=96 && IRQ<=99)  NVIC_PRI24_R |= priority << shift;
   else if(IRQ>=100 && IRQ<=103)  NVIC_PRI25_R |= priority << shift;
   else if(IRQ>=104 && IRQ<=107)  NVIC_PRI26_R |= priority << shift;
   else if(IRQ>=108 && IRQ<=111)  NVIC_PRI27_R |= priority << shift;
   else if(IRQ>=112 && IRQ<=115)  NVIC_PRI28_R |= priority << shift;
   else if(IRQ>=116 && IRQ<=119)  NVIC_PRI29_R |= priority << shift;
   else if(IRQ>=120 && IRQ<=123)  NVIC_PRI30_R |= priority << shift;
   else if(IRQ>=124 && IRQ<=127)  NVIC_PRI31_R |= priority << shift;
   else if(IRQ>=128 && IRQ<=131)  NVIC_PRI32_R |= priority << shift;
   else if(IRQ>=132 && IRQ<=135)  NVIC_PRI33_R |= priority << shift;
   else if(IRQ>=136 && IRQ<=138)  NVIC_PRI34_R |= priority << shift;
}

/*void Interupt_Init(uint8 pin){
  
    Clear_Bit(GPIO_PORTF_IS_R,pin);
    Clear_Bit(GPIO_PORTF_IBE_R, pin);
    Clear_Bit(GPIO_PORTF_IEV_R, pin);
    Set_Bit(GPIO_PORTF_ICR_R, pin);
    Set_Bit(GPIO_PORTF_IM_R, pin);
      
}*/
