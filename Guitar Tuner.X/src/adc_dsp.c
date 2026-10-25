/*
 * File:   adc_dsp.c
 * Author: Matthew Lopez Tarsky
 *
 * Created on October 13, 2026, 3:23 PM
 */

#include "adc_dsp.h"
#include <stdio.h>
#include <stdint.h>

static void DigitalToVoltage(uint16_t adcSampleSet[], uint8_t size){
    for (int i = 0; i < size; i++){
        adcSampleSet[i] = (uint16_t)(((float)adcSampleSet[i] /  ADC_MAX) * VREF);
    }
}