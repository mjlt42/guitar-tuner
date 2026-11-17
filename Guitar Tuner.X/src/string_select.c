/*
 * File:   string_select.c
 * Author: Justin Andreotti
 *
 * Created on October 13, 2026, 3:22 PM
 */

//check
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "string_select.h"

#define _XTAL_FREQ 16000000UL

void String_init(void)
{
    ANSELBbits.ANSB0 = 0;
    ANSELBbits.ANSB1 = 0;

    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
}

String change_state(Direction direction)
{
    static String current = ELow;

    if (direction == NEXT)
    {
        current = (String)((current + 1) % NUM_STATES);
    }
    else if (direction == PREV)
    {
        if (current == ELow)
            current = EHigh;
        else
            current = (String)(current - 1);
    }

    return current;
}

/*
void main(void){
    init();

    String state = ELow;

    while (1)
    {
        if (PORTBbits.RB0 == 0){
            state = change_state(state, NEXT);
        }
        else if (PORTBbits.RB1 == 0){
            state = change_state(state, PREV);
        }
    }
}*/
