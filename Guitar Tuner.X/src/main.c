
/*
 * ECE 3301 Guitar Tuner
 * Display Firmware Test
 */

#include <xc.h>
#include "Configuration.h"
#include "LCD.h"
#include "display.h"

void main(void)
{
    // Set internal oscillator to 16 MHz
    OSCCONbits.IRCF = 0b111;
    OSCCONbits.SCS = 0b10;

    // Configure LCD data pins as digital
    ANSELA = 0x00;
    ANSELD = 0x00;

    // Initialize the LCD
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
