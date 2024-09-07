#ifndef AquatecControl_h
#define AquatecControl_h

#include <Arduino.h>
#include "Water.h"
#include <Relay.h>
#include "DigitalIRSensor.h"
#include "TDSSensor.h"
#include "pHLevelSensor.h"
#include "DisplayLCD.h"



class AquatecControl{

    public:
        Water water;

        DigitalIRSensor proximitySensor;
        TDSSensor tdsSensor;
        pHLevelSensor pHSensor;

        Relay dispenserValve;
        Relay drainValve;
        Relay sourceValve;
        DisplayLCD displayLCD;

        AquatecControl();
        ~AquatecControl();

        void begin();
        void begin(int pHThreshold, int totaldissolvedsolidsThreshold);

        void init();

        void update();
        void operate();

    private:
        //Water _water; // Consider private later
};

#endif //AquatecControl_h