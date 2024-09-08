#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(){
    // nothing
}

TemperatureSensor::TemperatureSensor(int pin){
    _inputPin = pin;
}

TemperatureSensor::~TemperatureSensor(){
    // nothing to destruct
}

void TemperatureSensor::begin(){
    pinMode(_inputPin, INPUT);
}

float TemperatureSensor::readTemperature(){
    
    //_temperature = analogRead(_inputPin);
    //return _temperature;
}

