#ifndef DigitalIRSensor_h
#define DigitalIRSensor_h

#include <Arduino.h>


class DigitalIRSensor{
    public:
        DigitalIRSensor();
        DigitalIRSensor(int pin);
        ~DigitalIRSensor();
        void begin();
        byte readProximity();
    private:
        int _inputPin;
};
#endif //DigitalIRSensor_h