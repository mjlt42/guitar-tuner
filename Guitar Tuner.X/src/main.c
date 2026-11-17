
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
#define _XTAL_FREQ 16000000 


#define PREV_PORT PORTBbits.RB1 
#define NEXT_PORT PORTBbits.RB0 
//TODO: 
static void init(void){
    // 16 MHz HFINTOSC
    OSCCON &= ~(0x7 << 4);
    OSCCON |= (0x7 << 4);
    
    OSCCON &= ~(0x1 << 1);
    OSCCON |= (0x1 << 1);
}

void main(void)
{
    //Initialization functions
    init();
    String_init();
    ADC_init();
    LCD_init();
    
    /*
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
     * 
     if (PORTBbits.RB0 == 0){
            state = change_state(state, NEXT);
        }
        else if (PORTBbits.RB1 == 0){
            state = change_state(state, PREV);
        }
    }*/
     
}
