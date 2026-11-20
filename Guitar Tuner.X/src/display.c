
/*
 * File: display.c
 * Project: ECE 3301 Guitar Tuner
 * Description: Guitar tuner LCD display firmware
 */

#include <stdint.h>
#include "display.h"
#include "LCD.h"

void Display_Update(uint8_t string, uint8_t status, uint32_t frequency_hz)
{
    LCD_clear();

    // Row 1: selected string and tuning status
    LCD_cursor_set(1, 1);

    switch (string)
    {
        case 0:
            LCD_write_string("LOW E");
            break;
        case 1:
            LCD_write_string("A");
            break;
        case 2:
            LCD_write_string("D");
            break;
        case 3:
            LCD_write_string("G");
            break;
        case 4:
            LCD_write_string("B");
            break;
        case 5:
            LCD_write_string("HIGH E");
            break;
        default:
            LCD_write_string("?");
            break;
    }

    LCD_write_string(" - ");

    switch (status)
    {
        case 0:
            LCD_write_string("FLAT");
            break;
        case 1:
            LCD_write_string("TUNED");
            break;
        case 2:
            LCD_write_string("SHARP");
            break;
        default:
            LCD_write_string("NO SIG");
            break;
    }

    // Row 2: measured frequency
    LCD_cursor_set(2, 1);
    LCD_write_string("FREQ: ");

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