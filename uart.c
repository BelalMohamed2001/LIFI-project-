#include "uart.h"

void Uart_Init(uint8 uart, uint32 baudRate, uint8 mode){
  Set_Bit(SYSCTL_RCGCUART_R,uart);
  uint32 clkDiv = SYSCLK / (16 * baudRate);
  uint32 intBRD = (uint32)clkDiv;
  switch (uart) {
    case 0: 
    UART0_IBRD_R = intBRD;
    UART0_FBRD_R = (clkDiv - intBRD) * 64 + 0.5;
    UART0_CC_R |= mode;
    break;
    
    case 1: 
    UART1_IBRD_R = intBRD;
    UART1_FBRD_R = (clkDiv - intBRD) * 64 + 0.5;
    UART1_CC_R |= mode;
    break;
    
    case 2: 
    UART2_IBRD_R = intBRD;
    UART2_FBRD_R = (clkDiv - intBRD) * 64 + 0.5;
    UART2_CC_R |= mode;
    break;
    
    case 3: 
    UART3_IBRD_R = intBRD;
    UART3_FBRD_R = (clkDiv - intBRD) * 64 + 0.5;    
    UART3_CC_R |= mode;
    break;
    
    case 4: 
    UART4_IBRD_R = intBRD;
    UART4_FBRD_R = (clkDiv - intBRD) * 64 + 0.5;
    UART4_CC_R |= mode;
    break;
    
    case 5: 
    UART5_IBRD_R = intBRD;
    UART5_FBRD_R = (clkDiv - intBRD) * 64 + 0.5;    
    UART5_CC_R |= mode;
    break;
    
    case 6: 
    UART6_IBRD_R = intBRD;
    UART6_FBRD_R = (clkDiv - intBRD) * 64 + 0.5;
    UART6_CC_R |= mode;
    break;
    
    case 7: 
    UART7_IBRD_R = intBRD;
    UART7_FBRD_R = (clkDiv - intBRD) * 64 + 0.5;
    UART7_CC_R |= mode;
    break;
  }
}
void Uart_Control(uint8 uart, uint8 transmitFlag, uint8 recieveFlag, uint8 wlen){
  
  switch (uart) {
    case 0: 
      Set_Bit(UART0_CTL_R,0);
      if(transmitFlag)  Set_Bit(UART0_CTL_R,TXEPIN);
      if(recieveFlag)  Set_Bit(UART0_CTL_R,RXEPIN);
      UART0_LCRH_R |= (wlen << 5);
    break;
    
    case 1: 
      Set_Bit(UART1_CTL_R,0);
      if(transmitFlag)  Set_Bit(UART1_CTL_R,TXEPIN);
      if(recieveFlag)  Set_Bit(UART1_CTL_R,RXEPIN);
      UART1_LCRH_R |= (wlen << 5);
    break;
    
    case 2: 
      Set_Bit(UART2_CTL_R,0);
      if(transmitFlag)  Set_Bit(UART2_CTL_R,TXEPIN);
      if(recieveFlag)  Set_Bit(UART2_CTL_R,RXEPIN);
      UART2_LCRH_R |= (wlen << 5);
    break;
    
    case 3: 
      Set_Bit(UART3_CTL_R,0);
      if(transmitFlag)  Set_Bit(UART3_CTL_R,TXEPIN);
      if(recieveFlag)  Set_Bit(UART3_CTL_R,RXEPIN);
      UART3_LCRH_R |= (wlen << 5);
    break;
    
    case 4: 
      Set_Bit(UART4_CTL_R,0);
      if(transmitFlag)  Set_Bit(UART4_CTL_R,TXEPIN);
      if(recieveFlag)  Set_Bit(UART4_CTL_R,RXEPIN);
      UART4_LCRH_R |= (wlen << 5);
      break;
    
    case 5: 
      Set_Bit(UART5_CTL_R,0);
      if(transmitFlag)  Set_Bit(UART5_CTL_R,TXEPIN);
      if(recieveFlag)  Set_Bit(UART5_CTL_R,RXEPIN);
      UART5_LCRH_R |= (wlen << 5);
      break;
    
    case 6: 
      Set_Bit(UART6_CTL_R,0);
      if(transmitFlag)  Set_Bit(UART6_CTL_R,TXEPIN);
      if(recieveFlag)  Set_Bit(UART6_CTL_R,RXEPIN);
      UART6_LCRH_R |= (wlen << 5);
    break;
    
    case 7: 
      Set_Bit(UART0_CTL_R,7);
      if(transmitFlag)  Set_Bit(UART7_CTL_R,TXEPIN);
      if(recieveFlag)  Set_Bit(UART7_CTL_R,RXEPIN);
      UART7_LCRH_R |= (wlen << 5);
    break;
  }
  
}
uint8 Uart_RX(uint8 uart){
  uint8 c;
  switch (uart) {
    case 0: 
    while(Get_Bit(UART0_FR_R,RXFEPIN) != 0);
    c = UART0_DR_R;
    break;
    
    case 1: 
    while(Get_Bit(UART1_FR_R,RXFEPIN) != 0);
    c = UART1_DR_R;
    break;
    
    case 2: 
    while(Get_Bit(UART2_FR_R,RXFEPIN) != 0);
    c = UART2_DR_R;
    break;
    
    case 3: 
    while(Get_Bit(UART3_FR_R,RXFEPIN) != 0);
    c = UART3_DR_R;
    break;
    
    case 4: 
    while(Get_Bit(UART4_FR_R,RXFEPIN) != 0);
    c = UART4_DR_R;
    break;
    
    case 5: 
    while(Get_Bit(UART5_FR_R,RXFEPIN) != 0);
    c = UART5_DR_R;
    break;
    
    case 6: 
    while(Get_Bit(UART6_FR_R,RXFEPIN) != 0);
    c = UART6_DR_R;
    break;
    
    case 7: 
    while(Get_Bit(UART7_FR_R,RXFEPIN) != 0);
    c = UART7_DR_R;
    break;
  }
  return c;

}

void Uart_TX(uint8 uart, uint8 c){
 switch (uart) {
    case 0: 
    while(Get_Bit(UART0_FR_R,TXFFPIN) != 0);
    UART0_DR_R = c;
    break;
    
    case 1: 
    while(Get_Bit(UART1_FR_R,TXFFPIN) != 0);
    UART1_DR_R = c;
    break;
    
    case 2: 
    while(Get_Bit(UART2_FR_R,TXFFPIN) != 0);
    UART2_DR_R = c;
    break;
    
    case 3: 
    while(Get_Bit(UART3_FR_R,TXFFPIN) != 0);
    UART3_DR_R = c;
    break;
    
    case 4: 
    while(Get_Bit(UART4_FR_R,TXFFPIN) != 0);
    UART4_DR_R = c;
    break;
    
    case 5: 
    while(Get_Bit(UART5_FR_R,TXFFPIN) != 0);
    UART5_DR_R = c;
    break;
    
    case 6: 
    while(Get_Bit(UART6_FR_R,TXFFPIN) != 0);
    UART6_DR_R = c;
    break;
    
    case 7: 
    while(Get_Bit(UART7_FR_R,TXFFPIN) != 0);
    UART7_DR_R = c;
    break;
 }
}
