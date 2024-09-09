#include "TDSSensor.h"

#define VREF 5.0  // analog reference voltage(Volt) of the ADC
#define SCOUNT 30 // sum of sample point

TDSSensor::TDSSensor()
{
}

TDSSensor::TDSSensor(int pin)
{
  _inputPin = pin;
  _gravityTDS = GravityTDS();
}

TDSSensor::~TDSSensor()
{
}

void TDSSensor::begin()
{
  pinMode(_inputPin, INPUT);

  _gravityTDS.setPin(_inputPin);
  _gravityTDS.setAref(VREF);
  _gravityTDS.setAdcRange(1024);
  _gravityTDS.begin();

  _temperature = 25; // TODO change to actual temperature reading when temperature sensor is available
}

float TDSSensor::readVoltage(){
  _voltage = analogRead(_inputPin) * VREF / 1023.0;
  return _voltage;
}

float TDSSensor::readTDS()
{
  _gravityTDS.setTemperature(_temperature);
  _gravityTDS.update();
  _tdsValue = _gravityTDS.getTdsValue();
  return _tdsValue;
}

int TDSSensor::getTemperature()
{
  return _temperature;
}

void TDSSensor::setTemperature(int temperature)
{
  _temperature = temperature;
}
