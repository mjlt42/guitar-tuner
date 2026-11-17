
#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

// Update the LCD with selected string
// and tuning status.
//
// String: 0-5 (Low E through High E)
// Status: 0=Flat, 1=In Tune,
//         2=Sharp, 3=No Signal

void Display_Update(uint8_t string, uint8_t status);

#endif
