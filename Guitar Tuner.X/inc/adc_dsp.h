#ifndef ADC_DSP_H
#define ADC_DSP_H


static void ADC_init();
static uint16_t ADC_read();
static uint16_t* ADC_Sample();
static void DigitalToVoltage(uint16_t adcSampleSet[], uint8_t size);



#endif