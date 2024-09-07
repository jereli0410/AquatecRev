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
        float readpHLevel();
    private:
        int _inputPin;
        int _pHLevel;
}; 

#endif //pHLevelSensor_h