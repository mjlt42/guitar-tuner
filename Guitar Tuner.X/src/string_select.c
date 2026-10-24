/*
 * File:   string_select.c
 * Author: Justin Andreotti
 *
 * Created on October 13, 2026, 3:22 PM
 */

//check
#include <xc.h>

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
    PREVIOUS
} Direction;

#define NUM_STATES 6

static void change_state(TrafficState *current, Direction direction)
{
    if (direction == NEXT)
    {
        *current = (TrafficState)((*current + 1) % NUM_STATES);
    }
    else if (direction == PREVIOUS)
    {
        if (*current == ELow)
            *current = EHigh;
        else
            *current = (TrafficState)(*current - 1);
    }
}


void main(void)
{
    init();

    TrafficState state = ELow;

    while (1)
    {
        if (PORTDbits.RD6 == 0)
        {
            change_state(&state, NEXT);
        }
        else if (PORTDbits.RD7 == 0)
        {
            change_state(&state, PREVIOUS);
        }
    }
}
