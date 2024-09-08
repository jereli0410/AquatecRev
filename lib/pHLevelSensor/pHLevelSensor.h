#ifndef pHLevelSensor_h
#define pHLevelSensor_h

#include <Arduino.h>

class pHLevelSensor
{
    public:
        pHLevelSensor();
        pHLevelSensor(int pin);
        ~pHLevelSensor();

        void begin();
        float readVoltage();
        float readpHLevel();

    private:
        int _inputPin;
        int _pHLevel;
        int _voltage;
}; 

#endif //pHLevelSensor_h