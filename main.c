#include "tm4c123gh6pm.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "application.h"

//#include "fume.h"

uint32_t time; /*stores pulse on time */
uint32_t distance; /* stores measured distance value */
char mesg[40];
int32 temp = 0;
int32 fume=0;

uint32 lastEdge = 0;
uint32 thisEdge = -1;
uint32 dist = 0;

volatile int tempreture = 0;

void TIMER0A_Handler(){
  if (Get_Bit(TIMER0_RIS_R, 2)) {
    if (GPIO_PORTB_DATA_R & (1<<6) && lastEdge == 0){
      lastEdge = TIMER0_TAR_R; 
      thisEdge =0;
    }
    else if(thisEdge == 0){
      thisEdge = TIMER0_TAR_R;
      distance = ((thisEdge - lastEdge) * 10625)/10000000;
      lastEdge = 0;
      sprintf(mesg, "Ultrsonic Distance: = %d cm\n", distance); //convert float type distance data into string 
      Bluetooth_Write_String(mesg);
      if(distance >=2 && distance <=4 ){
        DIO_WritePin(PORTC, PIN7,1);
        delayMs(40);
        DIO_WritePin(PORTC, PIN7,0);
        delayMs(40);
        DIO_WritePin(PORTC, PIN7,1);
        delayMs(40);
        DIO_WritePin(PORTC, PIN7,0);
        delayMs(40);
        DIO_WritePin(PORTC, PIN7,1);
        delayMs(40);
        DIO_WritePin(PORTC, PIN7,0);
        
        printf("Near");
        
      }
      ADC0_PSSI_R |= (1<<3);        /* Enable SS3 conversion or start sampling data from AN0 */
      
    }
    TIMER0_ICR_R = 4; 
  }
}

void portD_handler(){
  if (Get_Bit(GPIO_PORTD_MIS_R, PIN1)) {
    // to handle magnetic sensor
    
    sprintf(mesg, "Magnetic Sensor: = %d Open door\n", 1); /*convert float type distance data into string */
    Bluetooth_Write_String(mesg);
    DIO_WritePin(PORTC, PIN7,1);
        delayMs(20);
        DIO_WritePin(PORTC, PIN7,0);
        delayMs(20);
        DIO_WritePin(PORTC, PIN7,1);
        delayMs(20);
        DIO_WritePin(PORTC, PIN7,0);
        delayMs(20);
        DIO_WritePin(PORTC, PIN7,1);
        delayMs(20);
        DIO_WritePin(PORTC, PIN7,0);
        delayMs(20);
        DIO_WritePin(PORTC, PIN7,1);
        delayMs(20);
        DIO_WritePin(PORTC, PIN7,0);
        delayMs(20);
        DIO_WritePin(PORTC, PIN7,1);
        delayMs(20);
        DIO_WritePin(PORTC, PIN7,0);
    GPIO_PORTD_ICR_R |= 0x2;
    
  }  
}

void GPIOE_Handler(void){
  if (Get_Bit(GPIO_PORTE_MIS_R, PIN1)) {
    printf("\nport e pin 2\n");
    //TIMER2_CTL_R |= (1<<0);
    GPIO_PORTE_ICR_R |= (1<<1);
  }
  
}

void ADC0SS3_Handler(){ 
  // Temp ISR
  fume =ADC0_SSFIFO3_R;
  if(fume>=1000) {
    DIO_WritePin(PORTC, PIN7,1);
        delayMs(60);
        DIO_WritePin(PORTC, PIN7,0);
        delayMs(60);
        DIO_WritePin(PORTC, PIN7,1);
        delayMs(60);
        DIO_WritePin(PORTC, PIN7,0);
        delayMs(60);
        DIO_WritePin(PORTC, PIN7,1);
        delayMs(60);
        DIO_WritePin(PORTC, PIN7,0);
  }
  sprintf(mesg, "Fume Sensor: = %d \n", fume); /*convert float type distance data into string */
  Bluetooth_Write_String(mesg);
  //printf("%d\n",temp);
  //delayMs(5000);
  ADC0_ISC_R = 8;                       // clear completion flaf
}

void GPIOF_Handler(void) {
  
  if (Get_Bit(GPIO_PORTF_MIS_R, PIN4)) {
    // Stop
    NVIC_DIS0_R |= 1<<19;       // diasable timer0   (ultrasonic)
    NVIC_DIS0_R |= (1 << 17);    // diasable adcseq  (temp)
    NVIC_DIS0_R |= (1<<3);      // diable portd intrp (magnetic) 
    NVIC_DIS0_R |= (1<<23);     // diable timer2 (mute btn)
    printf("\nstop\n"); 
    NVIC_EN0_R |=1<<30;         // keep portf enabled switches
    GPIO_PORTF_ICR_R |= 0x10;
  } 
  else if (Get_Bit(GPIO_PORTF_MIS_R, PIN0)) {
    //Start
    GPIO_PORTF_ICR_R |= 0x1; 
    NVIC_EN0_R |= 1<<19;       // enable timer0   (ultrasonic)
    NVIC_EN0_R |= (1 << 17);    // enable adcseq  (temp)
    NVIC_EN0_R |= (1<<2);      // enble portc intrp (mute btn)   
    NVIC_EN0_R |= (1<<3);      // enble portd intrp (magnetic)   
    NVIC_EN0_R |= (1<<23);     // enable timer2 (mute btn)
    //NVIC_EN0_R |=1<<30;         // keep portf enabled switches
    //printf("\nstart\n");
  } 
}

void TIMER2A_Handler(){
  if (Get_Bit(TIMER2_RIS_R, 0)) {
    printf("timeout after mute");
    TIMER2_ICR_R |= (1<<0);
  }
  
}

int main(void)
{
  
  
  Application_Init();
    
  while(1)
  {
     Send_Trigger(); 
    }
}


