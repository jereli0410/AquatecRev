#include "pHLevelSensor.h"

#define VREF 5.0 // analog reference voltage(Volt) of the ADC
#define CALIBRATION_CONSTANT -2.5

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

// Examples Calculation
float pHLevelSensor::readpHLevel()
{
    float calibration_value = CALIBRATION_CONSTANT;
    unsigned long int avgval;
    int buffer_arr[10], temp;

    for (int i = 0; i < 10; i++)
    {
        buffer_arr[i] = analogRead(A0);
        delay(30);
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (buffer_arr[i] > buffer_arr[j])
            {
                temp = buffer_arr[i];
                buffer_arr[i] = buffer_arr[j];
                buffer_arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        Serial.print("Unsorted:  ");
        Serial.println(buffer_arr[i]);
    }

    avgval = 0;
    for (int i = 2; i < 8; i++)
    {
        avgval += buffer_arr[i];
        Serial.print("Sorted:  ");
        Serial.println(+buffer_arr[i]);
    }
    Serial.print("Avgval:  ");
    Serial.println(avgval);
    float volt = (float)avgval * 5.0 / 1024 / 6;
    Serial.print("VoltStep: ");
    Serial.println(volt);
    float ph_act = -5.70 * volt + calibration_value;
    Serial.print("pH before return: ");
    Serial.println(ph_act);

    return ph_act;
}

/* My Calculation
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
*/