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
        float readpH();
        int getMedianNum(int bArray[], int iFilterLen);
    private:
        int _inputPin;
}; 

#endif //pHLevelSensor_h