#include "DigitalIRSensor.h"

DigitalIRSensor::DigitalIRSensor() {}
DigitalIRSensor::DigitalIRSensor(int inputPin)
{
    _inputPin = inputPin;
}

DigitalIRSensor::~DigitalIRSensor() {}

void DigitalIRSensor::begin()
{
    pinMode(_inputPin, INPUT);
}

byte DigitalIRSensor::readProximity()
{
    return !digitalRead(_inputPin); // actual sensor is inverted
}
