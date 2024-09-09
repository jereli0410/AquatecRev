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
;
        int getTemperature();
        void setTemperature(int temperature);

    private:
        int _inputPin;
        int _temperature;
        int _voltage;
        int _tdsValue;
        GravityTDS _gravityTDS; 
};
#endif //TDSSensor_h  