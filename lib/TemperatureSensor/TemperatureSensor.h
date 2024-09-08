#ifndef TemperatureSensor_h
#define TemperatureSensor_h

#include <Arduino.h>

class TemperatureSensor
{
    public:
        TemperatureSensor();
        TemperatureSensor(int pin);
        ~TemperatureSensor();

        void begin();
        float readTemperature();

        int getTemperature();
        void setTemperature(int temperature);
    private:
        int _inputPin;
        int _temperature;
};

#endif //TemperatureSensor_h