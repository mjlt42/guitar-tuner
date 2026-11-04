/*
 * File:   string_select.c
 * Author: Justin Andreotti
 *
 * Created on October 13, 2026, 3:22 PM
 */

//check
#include <xc.h>
#include <stdint.h>
#include "string_select.h"

static void String_init(){
    
    //Button initialization 
    TRISBbits.TRISB0 = 0x01;
    ANSELBbits.ANSB0 = 0x00;
    
    TRISBbits.TRISB1 = 0x01;
    ANSELBbits.ANSB1 = 0x00;
}

static String change_state(Direction direction){
    static String current = ELow;
    if (direction == NEXT){
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
        if (PORTDbits.RD6 == 0){
            change_state(&state, NEXT);
        }
        else if (PORTDbits.RD7 == 0){
            change_state(&state, PREV);
        }
    }
}*/
