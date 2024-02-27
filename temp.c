#include "temp.h"

/*void wTimer0_init(int timerNumber){
//  initalize timmer to trigger ADC at sampler/sec
  SYSCTL_RCGCWTIMER_R |= 1;             // enable clock to WTimer Block 0
  uint32 delay = SYSCTL_RCGCWTIMER_R;
  WTIMER0_CTL_R = 0;                    // disable timer before initialization
  WTIMER0_CFG_R = 0x04;                 // 32-bit option
  WTIMER0_TAMR_R = 0x2;                 // periodic mode and down counter
  WTIMER0_TAILR_R = timerNumber;        // WTimer A interval load value red (we want 1 s so timerNumber=80,000,000)
  WTIMER0_CTL_R |= 0x20;                // timer trigger ADC
  WTIMER0_CTL_R |= 0x1;                 // enable WTimer A after initialization
}*/

void adc_init(){
  //initalize ADC0
  SYSCTL_RCGCADC_R |= 0x1;      //enable clock to ADC
  uint32 delay;
  delay = SYSCTL_RCGCADC_R;
  delay = SYSCTL_RCGCADC_R;
  delay = SYSCTL_RCGCADC_R;     // could also use polling to ask when clock is stable
  ADC0_ACTSS_R &= ~0x8;         // disable SS3 during configuration
  ADC0_EMUX_R &= ~0xF000;
  ADC0_EMUX_R |= 0x5000;        // timer trigger conversion seq 0
  //ADC0_SSMUX3_R = 0;            // take input from channel 0 (I think we don't need this line)
  ADC0_SSCTL3_R |= 0x0E;        // take chip tempreture, set flag at first sample (sample interrupt enable & end of squence)
  ADC0_IM_R |= (1 << 3);        // unmask allowing intrrupt to be send to interrupt controller
  NVIC_EN0_R |= (1 << 17);
  ADC0_ACTSS_R |= 0x8;          // enable ADC 0 sequencer 3 
}
