#include "application.h"

void Application_Init(){
   Switches_Init();
   LED_Init();
   Timer0ACapture_init();  
   HC05_init(); // call HC05_init() to initialze UART5 of TM4C123GH6PM
    Fume_Init();
   Magnetic_Init();
}
