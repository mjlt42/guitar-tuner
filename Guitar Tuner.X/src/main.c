
/*
 * ECE 3301 Guitar Tuner
 * Display Firmware Test
 */
#pragma warning disable 520
#include <xc.h>
#include "adc_dsp.h"
#include "Configuration.h"
#include "display.h"
#include "LCD.h"
#include "string_select.h"
#include "tuner_control.h"
#define _XTAL_FREQ 16000000 

#define CALIB 1.1f

#define PREV_PORT PORTBbits.RB1 
#define NEXT_PORT PORTBbits.RB0 
//TODO: 

static void init(void) {
    // 16 MHz HFINTOSC
    OSCCON &= ~(0x7 << 4);
    OSCCON |= (0x7 << 4);

    OSCCON &= ~(0x1 << 1);
    OSCCON |= (0x1 << 1);
}

void main(void) {
    //Initialization functions
    init();
    String_init();
    ADC_init();
    LCD_init();
    LCD_clear();
    String state = EHigh;
    while (1) {

        volatile static uint32_t freq;
        volatile static uint16_t peak_bin;
        volatile static ComplexNumber *samples;
        
        samples = ADC_Sample();

        FFT(samples);

        peak_bin = FindPeakBin(samples);

        freq = ((uint32_t) peak_bin * SAMPLE_RATE) / (SAMPLE_SIZE*CALIB);
        //freq = 5;
        switch (state) {
            case ELow:
                LCD_clear();
                LCD_cursor_set(1, 1);
                LCD_write_string("ELow");
                if ((65 < (int32_t) freq) && ((int32_t) freq < 104)) {
                    LCD_cursor_set(2, 1);
                    LCD_write_string("Frequency: ");
                    LCD_write_variable((int32_t) freq, 0);
                    LCD_write_string(" Hz");
                    if ((int32_t) freq < 80) {
                        Display_Update(1, 0);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 84) {
                        Display_Update(2, 2);

                        __delay_ms(1000);
                    } else {
                        Display_Update(0, 1);

                        __delay_ms(1000);
                    }
                } else if ((int32_t) freq > 104) {
                    freq = freq / 2;
                } else {
                    LCD_cursor_set(2, 1);
                    //LCD_write_string("NA");
                    LCD_write_variable((int32_t) freq, 0);
                }
                break;

            case A:
                LCD_clear();
                LCD_cursor_set(1, 1);
                LCD_write_string("A");
                if ((87 < (int32_t) freq) && ((int32_t) freq < 139)) {
                    LCD_cursor_set(2, 1);
                    LCD_write_string("Frequency: ");
                    LCD_write_variable((int32_t) freq, 0);
                    LCD_write_string(" Hz");
                    if ((int32_t) freq < 108) {
                        Display_Update(1, 0);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 112) {
                        Display_Update(2, 2);

                        __delay_ms(1000);
                    } else {
                        Display_Update(0, 1);

                        __delay_ms(1000);
                    }
                } else if ((int32_t) freq > 139) {
                    freq = freq / 2;
                } else {
                    LCD_cursor_set(2, 1);
                    //LCD_write_string("NA");
                    LCD_write_variable((int32_t) freq, 0);
                }
                break;

            case D:
                LCD_clear();
                LCD_cursor_set(1, 1);
                LCD_write_string("D");
                if ((116 < (int32_t) freq) && ((int32_t) freq < 185)) {
                    LCD_cursor_set(2, 1);
                    LCD_write_string("Frequency: ");
                    LCD_write_variable((int32_t) freq, 0);
                    LCD_write_string(" Hz");
                    if ((int32_t) freq < 144) {
                        Display_Update(1, 0);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 148) {
                        Display_Update(2, 2);

                        __delay_ms(1000);
                    } else {
                        Display_Update(0, 1);

                        __delay_ms(1000);
                    }
                } else if ((int32_t) freq > 185) {
                    freq = freq / 2;
                } else {
                    LCD_cursor_set(2, 1);
                    //LCD_write_string("NA");
                    LCD_write_variable((int32_t) freq, 0);
                }
                break;
            case G:
                LCD_clear();
                LCD_cursor_set(1, 1);
                LCD_write_string("G");
                if ((156 < (int32_t) freq) && ((int32_t) freq < 247)) {
                    LCD_cursor_set(2, 1);
                    LCD_write_string("Frequency: ");
                    LCD_write_variable((int32_t) freq, 0);
                    LCD_write_string(" Hz");
                    if ((int32_t) freq < 194) {
                        Display_Update(1, 0);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 198) {
                        Display_Update(2, 2);

                        __delay_ms(1000);
                    } else {
                        Display_Update(0, 1);

                        __delay_ms(1000);
                    }
                } else if ((int32_t) freq > 247) {
                    freq = freq / 2;
                } else {
                    LCD_cursor_set(2, 1);
                    //LCD_write_string("NA");
                    LCD_write_variable((int32_t) freq, 0);
                }
                break;
            case B:
                LCD_clear();
                LCD_cursor_set(1, 1);
                LCD_write_string("B");
                if ((196 < (int32_t) freq) && ((int32_t) freq < 311)) {
                    LCD_cursor_set(2, 1);
                    LCD_write_string("Frequency: ");
                    LCD_write_variable((int32_t) freq, 0);
                    LCD_write_string(" Hz");
                    if ((int32_t) freq < 245) {
                        Display_Update(1, 0);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 249) {
                        Display_Update(2, 2);

                        __delay_ms(1000);
                    } else {
                        Display_Update(0, 1);

                        __delay_ms(1000);
                    }
                } else if ((int32_t) freq > 311) {
                    freq = freq / 2;
                } else {
                    LCD_cursor_set(2, 1);
                    //LCD_write_string("NA");
                    LCD_write_variable((int32_t) freq, 0);
                }
                break;
            case EHigh:
                LCD_clear();
                LCD_cursor_set(1, 1);
                LCD_write_string("EHigh");
                if ((262 < (int32_t) freq) && ((int32_t) freq < 415)) {
                    LCD_cursor_set(2, 1);
                    LCD_write_string("Frequency: ");
                    LCD_write_variable((int32_t) freq, 0);
                    LCD_write_string(" Hz");}
                    /*if ((int32_t) freq < 328) {
                        Display_Update(1, 0);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 332) {
                        Display_Update(2, 2);

                        __delay_ms(1000);
                    } else {
                        Display_Update(0, 1);

                        __delay_ms(1000);
                    }
                } else if ((int32_t) freq > 415) {
                    freq = freq / 2;
                }*/ else {
                    LCD_cursor_set(2, 1);
                    //LCD_write_string("NA");
                    LCD_write_variable((int32_t) freq, 0);
                }
                break;
        }

        if (NEXT_PORT == 0) {
            state = change_state(state, NEXT);
            __delay_ms(200);
        } else if (PREV_PORT == 0) {
            state = change_state(state, PREV);
            __delay_ms(200);
        }
        __delay_ms(100);
    }
}
/*
 // Low E string, correctly tuned
    Display_Update(0, 1);

    __delay_ms(1000);

    // A string, too low
    Display_Update(1, 0);

    __delay_ms(1000);

    // D string, too high
    Display_Update(2, 2);

    __delay_ms(1000);
     
 */