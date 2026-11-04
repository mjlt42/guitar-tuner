#ifndef STRING_SELECT_H
#define STRING_SELECT_H

#include <stdint.h>

#define NUM_STATES 6

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

static void String_init(void);
static String change_state(Direction direction);

#endif
