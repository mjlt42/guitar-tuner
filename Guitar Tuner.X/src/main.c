
/*
 * ECE 3301 Guitar Tuner
 * Display Firmware Test
 */

#include <xc.h>
#include "adc_dsp.h"
#include "Configuration.h"
#include "display.h"
#include "LCD.h"
#include "string_select.h"
#include "tuner_control.h"


#define PREV_PORT PORTBbits.RB1 
#define NEXT_PORT PORTBbits.RB0 
#define _XTAL_FREQ 64000000 
//TODO: 
static void init(void){
    // 16 MHz HFINTOSC with 4x PLL
    OSCCON &= ~(0x7 << 4);
    OSCCON |= (0x7 << 4);
    
    OSCCON &= ~(0x1 << 1);
    OSCCON |= (0x1 << 1);
}

void main(void)
{
   
    // Configure LCD data pins as digital
    ANSELA = 0x00;
    ANSELD = 0x00;

    // Initialize the LCD
    init();
    //String_init();
    ADC_init;
    LCD_init();

    while (1)
    {
        // Low E string, correctly tuned
        Display_Update(0, 1);

        __delay_ms(1000);

        // A string, too low
        Display_Update(1, 0);

        __delay_ms(1000);

        // D string, too high
        Display_Update(2, 2);

        __delay_ms(1000);
    }
}
