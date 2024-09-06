#ifndef TDSSensor_h
#define TDSSensor_h


#include <Arduino.h>

class TDSSensor{
    public:
        TDSSensor();
        TDSSensor(int pin);
        ~TDSSensor();
        void begin();
        float readTDS();
        int getMedianNum(int bArray[], int iFilterLen);
;
        int getTemperature();
        void setTemperature(int temperature);

    private:
        int _inputPin;
        int _currentTemperature;
        int _temperature;
};
#endif //TDSSensor_h  