#ifndef TDSSensor_h
#define TDSSensor_h

#include <Arduino.h>
#include "GravityTDS.h"

class TDSSensor{
    public:
        TDSSensor();
        TDSSensor(int pin);
        ~TDSSensor();
        void begin();

        float readVoltage();
        float readTDS();

    private:
        GravityTDS _gravityTDS;
        int _inputPin;
        float _currentTemperature;
        int _voltage;
        float _tdsValue;
};
#endif //TDSSensor_h  