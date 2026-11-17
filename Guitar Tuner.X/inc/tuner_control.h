#ifndef TUNER_CONTROL_H
#define TUNER_CONTROL_H

#include <stdint.h>
#define ADC_MAX 1023.0f
#define SAMPLE_SIZE 256
#define _XTAL_FREQ 16000000 

typedef struct _complexNumber{
    int16_t real;
    int16_t imag;
} ComplexNumber;

static ComplexNumber multiplyComplex(ComplexNumber num1, ComplexNumber num2);
inline uint8_t reverseBits(uint8_t number);
static ComplexNumber* reorderSample(ComplexNumber sampleSet[]);
void FFT(ComplexNumber* data);
#endif