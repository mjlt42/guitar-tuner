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
    }
    else if (direction == PREV)
    {
        if (current == ELow)
            return EHigh;
        else
            return (TrafficState)(current - 1);
    }
}


void main(void){
    init();

    TrafficState state = ELow;

    while (1)
    {
        if (PORTBbits.RB0 == 0){
            state = change_state(state, NEXT);
        }
        else if (PORTBbits.RB1 == 0){
            state = change_state(state, PREV);
        }
    }
}
