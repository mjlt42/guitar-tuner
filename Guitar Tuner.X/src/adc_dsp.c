/*
 * File:   adc_dsp.c
 * Author: Matthew Lopez Tarsky
 *
 * Created on October 13, 2026, 3:23 PM
 */

#include <xc.h>
#include "adc_dsp.h"
#include <stdio.h>
#include <stdint.h>
#include <pic18f46k22.h>

#define VREF 5.0f
#define ADC_MAX 1023.0f
#define SAMPLE_SIZE 256

static void ADC_init() {

    TRISAbits.TRISA0 = 1; // Set RA0 as input
    ANSELAbits.ANSA0 = 1; // Set RA0 to analog    

    ADCON0bits.CHS = 0b00000; // Channel AN0
    ADCON0bits.ADON = 1; // Enable ADC module

    ADCON1bits.PVCFG = 0b00; // VREF+ = VDD
    ADCON1bits.NVCFG = 0b00; // VREF- = VSS

    ADCON2bits.ADFM = 1; // Right-justified
    ADCON2bits.ACQT = 0b100; // 8 TAD acquisition time
    ADCON2bits.ADCS = 0b010; // FOSC/32 clock source

    ADCON0bits.ADON = 1; //Start ADC
}

static uint16_t ADC_read() {

    static uint16_t adcReading = 0;
    ADCON0bits.GO = 1; // Begin reading
    while (ADCON0bits.GO); // Wait till reading it done
    PIR1bits.ADIF = 0; // Clear interrupt flag;
    adcReading = (uint16_t) (((uint16_t) ADRESH << 8) | ADRESL); //Store upper and lower bytes

    return adcReading;
}

static uint16_t* ADC_Sample(){
    static uint16_t adcTempSet[SAMPLE_SIZE];
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        adcTempSet[i] = ADC_read();
        __delay_us(100);
    }
    return adcTempSet;
}
    

static void DigitalToVoltage(uint16_t adcSampleSet[], uint8_t size) {
    for (int i = 0; i < size; i++) {
        adcSampleSet[i] = (uint16_t) (((float) adcSampleSet[i] / ADC_MAX) * VREF);
    }
}