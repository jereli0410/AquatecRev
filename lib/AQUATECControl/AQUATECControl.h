#ifndef AquatecControl_h
#define AquatecControl_h

#include <Arduino.h>
#include "Water.h"
#include "Relay.h"
#include "DigitalIRSensor.h"
#include "TDSSensor.h"


class AquatecControl{

    public:
        Water water;

        DigitalIRSensor proximitySensor;
        TDSSensor tdsSensor;

        Relay dispenserValve;
        Relay drainValve;
        Relay sourceValve;

        AquatecControl();
        ~AquatecControl();

        void begin();
        void begin(int pHThreshold, int totaldissolvedsolidsThreshold);

    private:
        //Water _water; // Consider private later
};

#endif //AquatecControl_h