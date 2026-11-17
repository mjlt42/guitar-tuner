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

#define _XTAL_FREQ 16000000 

void String_init(void){
    
<<<<<<< HEAD
    ANSELB = 0x00;              // PORTD digital
    TRISB = 0x03;               // RB0 and RB1 inputs;
    LATB  = 0x03;               // Clear latches
}

typedef enum {
    ELow,
    A,
    D,
    G,
    B,
    EHigh
} TrafficState;

typedef enum {
    NEXT,
    PREV
} Direction;

#define NUM_STATES 6

static TrafficState change_state(TrafficState current, Direction direction){
    if (direction == NEXT){
        return (TrafficState)((current + 1) % NUM_STATES);
=======
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
>>>>>>> e3a8aeed8f13adcdf6d1ed9c6f15b801858c5b7a
    }
    else if (direction == PREV)
    {
        if (current == ELow)
<<<<<<< HEAD
            return EHigh;
        else
            return (TrafficState)(current - 1);
=======
            current = EHigh;
        else
            current = (String)(current - 1);
>>>>>>> e3a8aeed8f13adcdf6d1ed9c6f15b801858c5b7a
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
