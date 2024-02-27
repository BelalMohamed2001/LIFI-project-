#include "fume.h"

void Fume_Init(){
  SYSCTL_RCGCGPIO_R |= 0x10;            // enable clock to GPIOE (AIN0 ID PE3)
  SYSCTL_RCGCADC_R |= 0x1;              // enable clock to ADC0
  
  //initalize PE3 for AIN0 input
  GPIO_PORTE_AFSEL_R |= 0x8;            // enable alternate function
  GPIO_PORTE_DEN_R &= ~0x8;             // disable digital function
  GPIO_PORTE_AMSEL_R |= 0x8;            // enabke analogue function
  
  
  ADC0_ACTSS_R &= ~0x8;                 // disable SS3 during configurations
  
  ADC0_EMUX_R &= ~0xF000;               // software trigger conversion (Processor Trigger)
  
  ADC0_SSMUX3_R = 0x0;                // get input from channel 0 (skip if you are using internal tempreture sensor)
  
  ADC0_SSCTL3_R |= 0x6;                 // single ended, end of sequence, interrupt enable (flag on seqence finishes)
  ADC0_SSCTL0_R &= ~(1 << 3);         // read from channel (skip this if you are reading from internal sensor)
  
  // use ADC0_IM_R to mask interrupts  
  ADC0_IM_R |= (1 << 3);        // unmask allowing intrrupt to be send to interrupt controller
  NVIC_EN0_R |= (1 << 17);
  ADC0_ACTSS_R |= 0x8;                  // enable ADC0 sequencer 3
  ADC0_PSSI_R |= (1<<3);        /* Enable SS3 conversion or start sampling data from AN0 */
  
}
