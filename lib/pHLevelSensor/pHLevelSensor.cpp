#include "pHLevelSensor.h"

#define VREF 5.0 // analog reference voltage(Volt) of the ADC
#define CALIBRATION_CONSTANT 0.0

pHLevelSensor::pHLevelSensor()
{
}

pHLevelSensor::pHLevelSensor(int pin)
{
    _inputPin = pin;
}

pHLevelSensor::~pHLevelSensor()
{
}

void pHLevelSensor::begin()
{
    pinMode(_inputPin, INPUT);
}

float pHLevelSensor::readVoltage()
{
    _voltage = analogRead(_inputPin) * VREF / 1023;
    return _voltage;
}

float pHLevelSensor::readpHLevel()
{
    int samples = 10;
    int pHBuffer[samples];
    int pHBufferIndex;
    float averagepH = 0;

    for (pHBufferIndex = 0; pHBufferIndex < samples; pHBufferIndex++)
    {
        pHBuffer[pHBufferIndex] = analogRead(_inputPin);
        delay(30);
    }

    for (int i = 0; i < samples; i++)
    {
        averagepH += (float)pHBuffer[i];
    }
    // average the 10 readings from the buffer

    return averagepH = averagepH / samples * (14.0 / 1023.0); // convert the voltage to pH
}
