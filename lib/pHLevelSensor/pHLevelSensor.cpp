#include "pHLevelSensor.h"

pHLevelSensor::pHLevelSensor()
{
}

pHLevelSensor::pHLevelSensor(int pin){
    _inputPin = pin;
}

pHLevelSensor::~pHLevelSensor()
{
}

void pHLevelSensor::begin()
{
    pinMode(_inputPin, INPUT);
}

float pHLevelSensor::readpHLevel()
{
    static unsigned long analogSampleTimepoint = millis();
    int pHBuffer[10];
    int pHBufferIndex = 0;
    float averagepH = 0.0;

    if (millis() - analogSampleTimepoint > 40U) // every 40 milliseconds,read 10 analog samples and calculate the average value
    {
        analogSampleTimepoint = millis();
        pHBuffer[pHBufferIndex] = analogRead(_inputPin);
        pHBufferIndex++;
        if (pHBufferIndex == 10)
            pHBufferIndex = 0;
    }
    for (int i = 0; i < 10; i++) // average the 10 readings from the buffer
        averagepH += pHBuffer[i];
    averagepH /= 10.0;
    return averagepH;
}

