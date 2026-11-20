
/*
 * File: display.c
 * Project: ECE 3301 Guitar Tuner
 * Description: Guitar tuner LCD display firmware
 */

#include <xc.h>
#include <stdint.h>
#include "LCD.h"

#define _XTAL_FREQ 16000000 

// Tuning status:
// 0 = Flat
// 1 = In Tune
// 2 = Sharp
// 3 = No Signal

void Display_Update(uint8_t string, uint8_t status, uint32_t frequency_hz)
{
    (void)string;

    // Row 1: tuning status
    LCD_cursor_set(1, 1);

    switch (status)
    {
        case 0:
            LCD_write_string("STATUS: FLAT    ");
            break;

        case 1:
            LCD_write_string("STATUS: IN TUNE ");
            break;

        case 2:
            LCD_write_string("STATUS: SHARP   ");
            break;

        default:
            LCD_write_string("STATUS: NO SIG  ");
            break;
    }

    // Row 2: measured frequency
    LCD_cursor_set(2, 1);
    LCD_write_string("FREQ:           ");
    LCD_cursor_set(2, 7);

    if (status <= 2)
    {
        LCD_write_variable((int32_t)frequency_hz, 0);
        LCD_write_string(" Hz");
    }
    else
    {
        LCD_write_string("-- Hz");
    }
}