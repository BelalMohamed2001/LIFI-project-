#include "ultrasonic.h"
// timer 0A used
// timer 1
void Send_Trigger(void)
{
	
	  GPIO_PORTA_DATA_R &= ~(1<<4); /* make trigger  pin low */
	  Delay_MicroSecond(10); /*10 seconds delay */
	  GPIO_PORTA_DATA_R |= (1<<4); /* make trigger  pin high */
	  Delay_MicroSecond(10); /*10 seconds delay */
	  GPIO_PORTA_DATA_R &= ~(1<<4); /* make trigger  pin low */
}

/* Timer0A initialization function */
/* Initialize Timer0A in input-edge time mode with up-count mode */
void Timer0ACapture_init(void)
{
    SYSCTL_RCGCTIMER_R |= 1;     /* enable clock to Timer Block 0 */
    SYSCTL_RCGCGPIO_R |= 2;      /* enable clock to PORTB */
    
    GPIO_PORTB_DIR_R &= ~0x40;        /* make PB6 an input pin */
    GPIO_PORTB_DEN_R |= 0x40;         /* make PB6 as digital pin */
    GPIO_PORTB_AFSEL_R |= 0x40;       /* use PB6 alternate function */
    GPIO_PORTB_PCTL_R &= ~0x0F000000;  /* configure PB6 for T0CCP0 */
    GPIO_PORTB_PCTL_R |= 0x07000000;
    
	  /* PB2 as a digital output signal to provide trigger signal */
	  SYSCTL_RCGCGPIO_R |= 1;      /* enable clock to PORTA */
	  GPIO_PORTA_DIR_R |=(1<<4);         /* set PB2 as a digial output pin */
	  GPIO_PORTA_DEN_R |=(1<<4);         /* make PB2 as digital pin */

    TIMER0_CTL_R &= ~1;          /* disable timer0A during setup */
    TIMER0_CFG_R = 4;            /* 16-bit timer mode */
    TIMER0_TAMR_R = 0x17;        /* up-count, edge-time, capture mode */
    TIMER0_CTL_R |=0x0C;        /* capture the rising edge */
    TIMER0_ICR_R |= 0x01;
    TIMER0_IMR_R |= 0x04;
    NVIC_EN0_R = 1<<19;
    TIMER0_CTL_R |= (1<<0);           /* enable timer0A */
}


/* Create one microsecond second delay using Timer block 1 and sub timer A */

void Delay_MicroSecond(int time)
{
    int i;
    SYSCTL_RCGCTIMER_R |= 2;     /* enable clock to Timer Block 1 */
    TIMER1_CTL_R = 0;            /* disable Timer before initialization */
    TIMER1_CFG_R = 0x04;         /* 16-bit option */ 
    TIMER1_TAMR_R = 0x02;        /* periodic mode and down-counter */
    TIMER1_TAILR_R = 16 - 1;  /* TimerA interval load value reg */
    TIMER1_ICR_R = 0x1;          /* clear the TimerA timeout flag */
    TIMER1_CTL_R |= 0x01;        /* enable Timer A after initialization */

    for(i = 0; i < time; i++)
    {
        while ((TIMER1_RIS_R & 0x1) == 0) ;      /* wait for TimerA timeout flag */
        TIMER1_ICR_R = 0x1;      /* clear the TimerA timeout flag */
    }
}
