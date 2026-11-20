
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
    String state = D;
    while (1) {

        volatile static uint32_t freq;
        volatile static uint16_t peak_bin;
        volatile static ComplexNumber *samples;
        
        samples = ADC_Sample();

        FFT(samples);

        peak_bin = FindPeakBin(samples);

        freq = ((uint32_t) peak_bin * SAMPLE_RATE) / (SAMPLE_SIZE*CALIB);
        
        switch (state) {
            case ELow:
                LCD_clear();
                LCD_cursor_set(1, 1);
                if ((65 < (int32_t) freq) && ((int32_t) freq < 104)) {
                    if ((int32_t) freq < 78) {
                        Display_Update(0, 0, freq);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 86) {
                        Display_Update(0, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(0, 1, freq);

                        __delay_ms(1000);
                    }
                } else if ((int32_t) freq > 104) {
                    freq = freq / 2;
                    if ((int32_t) freq < 78) {
                        Display_Update(0, 0, freq);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 86) {
                        Display_Update(0, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(0, 1, freq);

                        __delay_ms(1000);
                    }
                } else {
                    Display_Update(0, 4, freq);
                    
                }
                break;

            case A:
                LCD_clear();
                LCD_cursor_set(1, 1);
                if ((87 < (int32_t) freq) && ((int32_t) freq < 139)) {
                    if ((int32_t) freq < 104) {
                        Display_Update(1, 0, freq);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 116) {
                        Display_Update(1, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(1, 1, freq);

                        __delay_ms(1000);
                    }
                } else if ((int32_t) freq > 139) {
                    freq = freq / 2;
                    if ((int32_t) freq < 104) {
                        Display_Update(1, 0, freq);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 116) {
                        Display_Update(1, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(1, 1, freq);

                        __delay_ms(1000);
                    }if ((int32_t) freq < 104) {
                        Display_Update(1, 0, freq);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 116) {
                        Display_Update(1, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(1, 1, freq);

                        __delay_ms(1000);
                    }
                } else {
                    Display_Update(1, 4, freq);
                }
                break;

            case D:
                LCD_clear();
                LCD_cursor_set(1, 1);
                if ((116 < (int32_t) freq) && ((int32_t) freq < 185)) {
                    if ((int32_t) freq < 140) {
                        Display_Update(2, 0, freq);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 152) {
                        Display_Update(2, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(2, 1, freq);

                        __delay_ms(1000);
                    }
                } else if ((int32_t) freq > 185) {
                    freq = freq / 2;
                    if ((int32_t) freq < 140) {
                        Display_Update(2, 0, freq);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 152) {
                        Display_Update(2, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(2, 1, freq);

                        __delay_ms(1000);
                    }
                } else {
                    Display_Update(2, 4, freq);
                }
                break;
            case G:
                LCD_clear();
                LCD_cursor_set(1, 1);
                if ((156 < (int32_t) freq) && ((int32_t) freq < 247)) {
                    if ((int32_t) freq < 190) {
                        Display_Update(3, 0, freq);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 202) {
                        Display_Update(3, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(3, 1, freq);

                        __delay_ms(1000);
                    }
                } else if ((int32_t) freq > 247) {
                    freq = freq / 2;
                    if ((156 < (int32_t) freq) && ((int32_t) freq < 247)) {
                    if ((int32_t) freq < 190) {
                        Display_Update(3, 0, freq);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 202) {
                        Display_Update(3, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(3, 1, freq);

                        __delay_ms(1000);
                    }
                } else {
                    Display_Update(3, 4, freq);
                }
                break;
            case B:
                LCD_clear();
                LCD_cursor_set(1, 1);
                if ((196 < (int32_t) freq) && ((int32_t) freq < 311)) {
                    if ((int32_t) freq < 241) {
                        Display_Update(4, 0, freq);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 253) {
                        Display_Update(4, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(4, 1, freq);

                        __delay_ms(1000);
                    }
                } else if ((int32_t) freq > 311) {
                    freq = freq / 2;
                    if ((int32_t) freq < 241) {
                        Display_Update(4, 0, freq);

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 253) {
                        Display_Update(4, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(4, 1, freq);

                        __delay_ms(1000);
                    }
                } else {
                    Display_Update(4, 4, freq);
                }
                break;
            case EHigh:
                LCD_clear();
                LCD_cursor_set(1, 1);
                if ((262 < (int32_t) freq) && ((int32_t) freq < 415)) {
                    if ((int32_t) freq < 324) {
                        Display_Update(5, 0, freq );

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 336) {
                        Display_Update(5, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(5, 1, freq);

                        __delay_ms(1000);
                    }
                } else if ((int32_t) freq > 415) {
                    freq = freq / 2;
                    if ((int32_t) freq < 324) {
                        Display_Update(5, 0, freq );

                        __delay_ms(1000);
                    } else if ((int32_t) freq > 336) {
                        Display_Update(5, 2, freq);

                        __delay_ms(1000);
                    } else {
                        Display_Update(5, 1, freq);

                        __delay_ms(1000);
                    }
                } else {
                    Display_Update(5, 4, freq);
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
}