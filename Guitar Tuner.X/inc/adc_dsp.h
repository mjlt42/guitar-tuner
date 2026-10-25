#ifndef ADC_DSP_H
#define ADC_DSP_H

#define VREF 5.0f
#define ADC_MAX 1023.0f

static void DigitalToVoltage(uint16_t adcSampleSet[], uint8_t size);

#endif