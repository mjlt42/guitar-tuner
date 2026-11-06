#ifndef TUNER_CONTROL_H
#define TUNER_CONTROL_H

#define ADC_MAX 1023.0f
#define SAMPLE_SIZE 256

uint8_t reverseBits(uint8_t number);
static uint16_t* reorderSample(uint16_t sampleSet[]);
static uint16_t* revaluateSample(uint16_t sampleSet[]);


#endif