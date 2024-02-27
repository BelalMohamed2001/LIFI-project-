#include "DIO.h"

void DIO_InitClock(int port){
  Set_Bit(SYSCTL_RCGCGPIO_R,port);               // Provide Clock to Port
  while(Get_Bit(SYSCTL_PRGPIO_R,port)==0);       // Busy loop till peripheral is ready 
}

void DIO_LockAndCommit(int port){
  
  switch (port) {
    
    //----- PORT A -----//
  case 0: 
    GPIO_PORTA_LOCK_R = 0X4C4F434B;             // Unlock using the magic number
    GPIO_PORTA_CR_R = 0x1F;                     // Commit all pins of port
    break;
    
    //----- PORT B -----//
  case 1: 
    GPIO_PORTB_LOCK_R = 0X4C4F434B;
    GPIO_PORTB_CR_R = 0x1F;                    
    break;
    
    //----- PORT C -----//
  case 2: 
    GPIO_PORTC_LOCK_R = 0X4C4F434B;
    GPIO_PORTC_CR_R = 0x1F;                    
    break;
    
    //----- PORT D -----//
  case 3: 
    GPIO_PORTD_LOCK_R = 0X4C4F434B;
    GPIO_PORTD_CR_R = 0x1F;                    
    break;
    
    //----- PORT E -----//
  case 4: 
    GPIO_PORTE_LOCK_R = 0X4C4F434B;
    GPIO_PORTE_CR_R = 0x1F;                    
    break;
    
    //----- PORT F -----//
  case 5: 
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R = 0x1F;                    
    
    //----- Default  -----//
  default:
    break; 
  }
}

void DIO_SetInputPin(int port, int pin){
  switch (port) {
    
    //----- PORT A -----//
  case 0: 
    Clear_Bit(GPIO_PORTA_DIR_R,pin);          // I/P -> Clear Direction Bit  
    Set_Bit(GPIO_PORTA_PUR_R,pin);            // I/P -> Enable Pullup Resistance    
    break;
    
    //----- PORT B -----//
  case 1: 
    Clear_Bit(GPIO_PORTB_DIR_R,pin);          // I/P -> Clear Direction Bit  
    Set_Bit(GPIO_PORTB_PUR_R,pin);            // I/P -> Enable Pullup Resistance    break;                    
    break;
    
    //----- PORT C -----//
  case 2: 
    Clear_Bit(GPIO_PORTC_DIR_R,pin);          // I/P -> Clear Direction Bit  
    Set_Bit(GPIO_PORTC_PUR_R,pin);            // I/P -> Enable Pullup Resistance    break;                    
    break;
    
    //----- PORT D -----//
  case 3: 
    Clear_Bit(GPIO_PORTD_DIR_R,pin);          // I/P -> Clear Direction Bit  
    Set_Bit(GPIO_PORTD_PUR_R,pin);            // I/P -> Enable Pullup Resistance    break;                    
    break;
    
    //----- PORT E -----//
  case 4: 
    Clear_Bit(GPIO_PORTE_DIR_R,pin);          // I/P -> Clear Direction Bit  
    Set_Bit(GPIO_PORTE_PUR_R,pin);            // I/P -> Enable Pullup Resistance    break;                    
    break;
    
    //----- PORT F -----//
  case 5: 
    Clear_Bit(GPIO_PORTF_DIR_R,pin);          // I/P -> Clear Direction Bit  
    Set_Bit(GPIO_PORTF_PUR_R,pin);            // I/P -> Enable Pullup Resistance    break;                    
    break;                   
    
    //----- Default  -----//
  default:
    break; 
  }
}

void DIO_SetOutputPin(int port, int pin){
  switch (port) {
    
    //----- PORT A -----//
  case 0: 
    Set_Bit(GPIO_PORTA_DIR_R,pin);            // O/P -> Set Direction Bit to 1
    break;
    
    //----- PORT B -----//
  case 1: 
    Set_Bit(GPIO_PORTB_DIR_R,pin);            
    break;
    
    //----- PORT C -----//
  case 2: 
    Set_Bit(GPIO_PORTC_DIR_R,pin);            
    break;
    
    //----- PORT D -----//
  case 3: 
    Set_Bit(GPIO_PORTD_DIR_R,pin);            
    break;
    
    //----- PORT E -----//
  case 4: 
    Set_Bit(GPIO_PORTE_DIR_R,pin);            
    break;
    
    //----- PORT F -----//
  case 5: 
    Set_Bit(GPIO_PORTF_DIR_R,pin);            
    
    //----- Default  -----//
  default:
    break; 
  }
}

void DIO_DigitalEnable(int port){
  
  switch (port) {
    
    //----- PORT A -----//
  case 0: 
    GPIO_PORTA_DEN_R = 0xFF;                     // Digital Enable to all pins of port
    break;
    
    //----- PORT B -----//
  case 1: 
    GPIO_PORTB_DEN_R = 0xFF;                    
    break;
    
    //----- PORT C -----//
  case 2: 
    GPIO_PORTC_DEN_R = 0xFF;                    
    break;
    
    //----- PORT D -----//
  case 3: 
    GPIO_PORTD_DEN_R = 0xFF;                    
    break;
    
    //----- PORT E -----//
  case 4: 
    GPIO_PORTE_DEN_R = 0xFF;                    
    break;
    
    //----- PORT F -----//
  case 5: 
    GPIO_PORTF_DEN_R = 0xFF;                    
    
    //----- Default  -----//
  default:
    break; 
  }
}

void DIO_Init(int port, int pin, int direction){
  
  Set_Bit(SYSCTL_RCGCGPIO_R,port);               // Provide Clock to Port
  while(Get_Bit(SYSCTL_PRGPIO_R,port)==0);       // Busy loop till peripheral is ready 
  
  switch (port) {
    
    //----- PORT A -----//
  case 0: 
    GPIO_PORTA_LOCK_R = 0X4C4F434B;             // Unlock
    Set_Bit(GPIO_PORTA_CR_R,pin);               // Commit 
    Set_Bit(GPIO_PORTA_DEN_R,pin);              // Digital Enable to Pin
    if(direction){
      Set_Bit(GPIO_PORTB_DIR_R,pin);            // O/P -> Set Direction Bit to 1
    }
    else{
      Clear_Bit(GPIO_PORTB_DIR_R,pin);          // I/P -> Clear Direction Bit  
      Set_Bit(GPIO_PORTB_PUR_R,pin);            // I/P -> Enable Pullup Resistance
    }
    break;
    
    //----- PORT B -----//
  case 1: 
    GPIO_PORTB_LOCK_R = 0X4C4F434B;
    Set_Bit(GPIO_PORTB_CR_R,pin); 
    Set_Bit(GPIO_PORTB_DEN_R,pin); 
    if(direction){
      Set_Bit(GPIO_PORTB_DIR_R,pin); 
    }
    else{
      Clear_Bit(GPIO_PORTB_DIR_R,pin); 
      Set_Bit(GPIO_PORTB_PUR_R,pin); 
    }
    break;
    
    //----- PORT C -----//
  case 2: 
    GPIO_PORTC_LOCK_R = 0X4C4F434B;
    Set_Bit(GPIO_PORTC_CR_R,pin); 
    Set_Bit(GPIO_PORTC_DEN_R,pin); 
    if(direction){
      Set_Bit(GPIO_PORTC_DIR_R,pin); 
    }
    else{
      Clear_Bit(GPIO_PORTC_DIR_R,pin); 
      Set_Bit(GPIO_PORTC_PUR_R,pin); 
    }
    break;
    
    //----- PORT D -----//
  case 3: 
    GPIO_PORTD_LOCK_R = 0X4C4F434B;
    Set_Bit(GPIO_PORTD_CR_R,pin); 
    Set_Bit(GPIO_PORTD_DEN_R,pin); 
    if(direction){
      Set_Bit(GPIO_PORTD_DIR_R,pin); 
    }
    else{
      Clear_Bit(GPIO_PORTD_DIR_R,pin); 
      Set_Bit(GPIO_PORTD_PUR_R,pin); 
    }
    break;
    
    //----- PORT E -----//
  case 4: 
    GPIO_PORTE_LOCK_R = 0X4C4F434B;
    Set_Bit(GPIO_PORTE_CR_R,pin); 
    Set_Bit(GPIO_PORTE_DEN_R,pin); 
    if(direction){
      Set_Bit(GPIO_PORTE_DIR_R,pin); 
    }
    else{
      Clear_Bit(GPIO_PORTE_DIR_R,pin); 
      Set_Bit(GPIO_PORTE_PUR_R,pin); 
    }
    break;
    
    //----- PORT F -----//
  case 5: 
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    Set_Bit(GPIO_PORTF_CR_R,pin); 
    Set_Bit(GPIO_PORTF_DEN_R,pin); 
    if(direction){
      Set_Bit(GPIO_PORTF_DIR_R,pin); 
    }
    else{
      Clear_Bit(GPIO_PORTF_DIR_R,pin); 
      Set_Bit(GPIO_PORTF_PUR_R,pin); 
    }
    break;
    
    //----- Default  -----//
  default:
    break; 
  }
}

void DIO_Toggle(int port,int pin){
  
  switch (port) {
    
    //----- PORT A -----//
  case 0: 
      Toggle_Bit(GPIO_PORTA_DATA_R,pin); 
      break;// Data=1 =>Set
    
    //----- PORT B -----//
  case 1: 
      Toggle_Bit(GPIO_PORTB_DATA_R,pin); 
    break;
    
    //----- PORT C -----//
  case 2: 
 
      Toggle_Bit(GPIO_PORTC_DATA_R,pin); 

    break;
    
    //----- PORT D -----//
  case 3: 

      Toggle_Bit(GPIO_PORTD_DATA_R,pin); 
    break;
    
    //----- PORT E -----//
  case 4: 
   
      Toggle_Bit(GPIO_PORTE_DATA_R,pin); 
    break;
    
    //----- PORT F -----//
  case 5: 
   
      Toggle_Bit(GPIO_PORTF_DATA_R,pin);  
    break;
  }
}

void DIO_WritePin(int port,int pin, int data){
  
  switch (port) {
    
    //----- PORT A -----//
  case 0: 
    if(data)
      Set_Bit(GPIO_PORTA_DATA_R,pin);        // Data=1 =>Set
    else
      Clear_Bit(GPIO_PORTA_DATA_R,pin);      // Data=0 =>Clear
    break;
    
    //----- PORT B -----//
  case 1: 
    if(data)
      Set_Bit(GPIO_PORTB_DATA_R,pin); 
    else
      Clear_Bit(GPIO_PORTB_DATA_R,pin); 
    break;
    
    //----- PORT C -----//
  case 2: 
    if(data)
      Set_Bit(GPIO_PORTC_DATA_R,pin); 
    else
      Clear_Bit(GPIO_PORTC_DATA_R,pin); 
    break;
    
    //----- PORT D -----//
  case 3: 
    if(data)
      Set_Bit(GPIO_PORTD_DATA_R,pin); 
    else
      Clear_Bit(GPIO_PORTD_DATA_R,pin); 
    break;
    
    //----- PORT E -----//
  case 4: 
    if(data)
      Set_Bit(GPIO_PORTE_DATA_R,pin); 
    else
      Clear_Bit(GPIO_PORTE_DATA_R,pin); 
    break;
    
    //----- PORT F -----//
  case 5: 
    if(data)
      Set_Bit(GPIO_PORTF_DATA_R,pin); 
    else
      Clear_Bit(GPIO_PORTF_DATA_R,pin); 
    break;
  }
}

void DIO_WritePort(int port, int data){
  
  switch (port) {
    
    //----- PORT A -----//
  case 0: 
    GPIO_PORTA_DATA_R = data;break;    
    
    //----- PORT B -----//
  case 1: 
    GPIO_PORTB_DATA_R = data;break;
    
    //----- PORT C -----//
  case 2: 
    GPIO_PORTC_DATA_R = data;break;
    
    //----- PORT D -----//
  case 3: 
    GPIO_PORTD_DATA_R = data;break;
    
    //----- PORT E -----//
  case 4: 
    GPIO_PORTE_DATA_R = data;break;
    
    //----- PORT F -----//
  case 5: 
    GPIO_PORTF_DATA_R = data;break;
  }
}

int DIO_ReadPin(int port,int pin){
  
  switch (port) {
    
    //----- PORT A -----//
  case 0: 
    return Get_Bit(GPIO_PORTA_DATA_R,pin);break;        
    
    //----- PORT B -----//
  case 1: 
    return Get_Bit(GPIO_PORTB_DATA_R,pin);break;
    
    //----- PORT C -----//
  case 2: 
    return Get_Bit(GPIO_PORTC_DATA_R,pin);break;
    
    //----- PORT D -----//
  case 3: 
    return Get_Bit(GPIO_PORTD_DATA_R,pin);break;
    
    //----- PORT E -----//
  case 4: 
    return Get_Bit(GPIO_PORTE_DATA_R,pin);break;
    
    //----- PORT F -----//
  case 5: 
    return Get_Bit(GPIO_PORTF_DATA_R,pin);break;
    
    //----- Default -----//
  default:    
    return -1;
  }
}

int DIO_ReadPort(int port){
  
  switch (port) {
    
    //----- PORT A -----//
  case 0: 
    return GPIO_PORTA_DATA_R;break;
    
    //----- PORT B -----//
  case 1: 
    return GPIO_PORTB_DATA_R;break;
    
    //----- PORT C -----//
  case 2: 
    return GPIO_PORTC_DATA_R;break;
    
    //----- PORT D -----//
  case 3: 
    return GPIO_PORTD_DATA_R;break;
    
    //----- PORT E -----//
  case 4: 
    return GPIO_PORTE_DATA_R;break;
    
    //----- PORT F -----//
  case 5: 
    return GPIO_PORTF_DATA_R;break;
    
    //----- Default -----//
  default:    
    return -1;
  }
}

void GPIO_AlternateFunc(uint8 port, uint8 pin, uint8 func){
  
  switch (port) {
    
    //----- PORT A -----//
  case 0: 
    Set_Bit(GPIO_PORTA_AFSEL_R, pin); 
    GPIO_PORTA_PCTL_R |= (func << pin);
    break;
    
    //----- PORT B -----//
  case 1: 
    Set_Bit(GPIO_PORTB_AFSEL_R, pin); 
    GPIO_PORTB_PCTL_R |= (func << pin);
    break;
    
    //----- PORT C -----//
  case 2: 
    Set_Bit(GPIO_PORTC_AFSEL_R, pin); 
    GPIO_PORTC_PCTL_R |= (func << pin);
    break;
    
    //----- PORT D -----//
  case 3: 
    Set_Bit(GPIO_PORTD_AFSEL_R, pin); 
    GPIO_PORTD_PCTL_R |= (func << pin);
    break;
    
    //----- PORT E -----//
  case 4: 
    Set_Bit(GPIO_PORTE_AFSEL_R, pin); 
    GPIO_PORTE_PCTL_R |= (func << pin);
    break;
    
    //----- PORT F -----//
  case 5: 
    Set_Bit(GPIO_PORTF_AFSEL_R, pin); 
    GPIO_PORTF_PCTL_R |= (func << pin);
    break;
  }
}


void delayUs(uint32 d){
  for(int i=0; i<d;i++){
    for(int j=0; j<3;j++){// delay 1 us
    }
  }
}

void delayMs(uint32 d){
  for(int i=0; i<d;i++){
    for(int j=0; j<3180;j++){// delay 1 ms
    }
  }
}

