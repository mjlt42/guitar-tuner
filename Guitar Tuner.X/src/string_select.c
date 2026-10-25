/*
 * File:   string_select.c
 * Author: Justin Andreotti
 *
 * Created on October 13, 2026, 3:22 PM
 */

//check
#include <xc.h>
#include <stdint.h>

static void init(void){
    // 16 MHz HFINTOSC with 4x PLL
    OSCCON |= (0x7 << 4); //sets IRCF<2:0> to HFINTOSC (16 MHz)
    OSCCON |= (0x1 << 1); //selects internal oscillator block
    
    ANSELD = 0x00;              // PORTD digital
    TRISD = 0xC0;               // RD7 and RD6 inputs; RD0-RD5 outputs
    LATD  = 0x00;               // Clear output latches
}

typedef enum {
    ELow,
    A,
    D,
    G,
    B,
    EHigh
} String;

typedef enum {
    NEXT,
    PREV
} Direction;

#define NUM_STATES 6

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
}
