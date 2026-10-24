
/*
 * File: display.c
 * Project: ECE 3301 Guitar Tuner
 * Description: Guitar tuner LCD display firmware
 */

#include <xc.h>
#include <stdint.h>
#include "LCD.h"

// Tuning status:
// 0 = Flat
// 1 = In Tune
// 2 = Sharp
// 3 = No Signal

void Display_Update(uint8_t string, uint8_t status)
{
    LCD_clear();

    // First row: Selected guitar string
    LCD_cursor_set(1, 0);

    switch (string)
    {
        case 0:
            LCD_write_string("STRING: LOW E");
            break;

        case 1:
            LCD_write_string("STRING: A");
            break;

        case 2:
            LCD_write_string("STRING: D");
            break;

        case 3:
            LCD_write_string("STRING: G");
            break;

        case 4:
            LCD_write_string("STRING: B");
            break;

        case 5:
            LCD_write_string("STRING: HIGH E");
            break;

        default:
            LCD_write_string("STRING: UNKNOWN");
            break;
    }

    // Second row: Tuning status
    LCD_cursor_set(2, 0);

    switch (status)
    {
        case 0:
            LCD_write_string("STATUS: FLAT");
            break;

        case 1:
            LCD_write_string("STATUS: IN TUNE");
            break;

        case 2:
            LCD_write_string("STATUS: SHARP");
            break;

        default:
            LCD_write_string("STATUS: NO SIG");
            break;
    }
}
