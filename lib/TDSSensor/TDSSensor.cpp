#include "TDSSensor.h"

TDSSensor::TDSSensor()
{
}

TDSSensor::TDSSensor(int pin)
{
    _inputPin = pin;
}

TDSSensor::~TDSSensor()
{
}

void TDSSensor::begin()
{
    _gravityTDS = GravityTDS();
    pinMode(_inputPin, INPUT);
    _gravityTDS.setPin(_inputPin);
    _gravityTDS.setAref(5.0);
    _gravityTDS.setAdcRange(1024);
    _gravityTDS.begin();
    _currentTemperature = 25.0;
    _tdsValue = 0.0;
}

float TDSSensor::readVoltage()
{
    _voltage = analogRead(_inputPin);
    _voltage = _voltage * (5.0 / 1023.0);
    return _voltage;
}


float TDSSensor::readTDS()
{
    _gravityTDS.setTemperature(25);
    _gravityTDS.update();
    return _gravityTDS.getTdsValue();
}
