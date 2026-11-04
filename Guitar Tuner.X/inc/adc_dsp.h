#ifndef ADC_DSP_H
#define ADC_DSP_H

#define _XTAL_FREQ 16000000  //Frequency of the system clock (16 MHz HFINTOSC)


void ADC_init(void);
static uint16_t ADC_read();
static uint16_t* ADC_Sample();
static void DigitalToVoltage(uint16_t adcSampleSet[], uint8_t size);



#endif