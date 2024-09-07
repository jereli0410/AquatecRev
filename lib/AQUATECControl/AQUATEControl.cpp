#include "AQUATECControl.h"

AquatecControl::AquatecControl()
{
}

AquatecControl::~AquatecControl() {}

void AquatecControl::begin()
{
    water = Water();
}

void AquatecControl::begin(int pHThreshold, int totaldissolvedsolidsThreshold)
{
    water = Water(pHThreshold, totaldissolvedsolidsThreshold);
}

void AquatecControl::init()
{
    displayLCD.printAQUATEC();
    sourceValve.turnOn();
    drainValve.turnOff();
    dispenserValve.turnOff();
    delay(3000);
    displayLCD.clear();
}

void AquatecControl::update()
{
    water.setpHLevel(pHSensor.readpHLevel());
    water.settotaldissolvedsolids(tdsSensor.readTDS());
    // water.setTemperature(temperatureSensor.readTemperature()); // To be implemented in the future
    displayLCD.printTDS(water.gettotaldissolvedsolids(), 0);
    displayLCD.printpH(water.getpHLevel(), 1);
    Serial.println("pH: " + String(water.getpHLevel()) + " " + "TDS: " + String(water.gettotaldissolvedsolids()) + " " + "Temperature: " + String(water.getTemperature()));
}

void AquatecControl::operate()
{
    if (water.isPotable())
    {
        Serial.println("Water OK!");
        if (proximitySensor.readProximity()) // Allow dispenser to operate if water is potable
        {
            Serial.println("Dispensing water...");
            dispenserValve.turnOn();
        }
        else
        {
            dispenserValve.turnOff();
        }
    }
    else
    {
        Serial.println("Water not potable!");
        displayLCD.printWarningNotPotable(); // Water not potable drain the water
        dispenserValve.turnOff();
        sourceValve.turnOff();
        drainValve.turnOn();
        Serial.println("Resetting reservoir...");
        delay(10000);
        // TODO: How to detect if reservoir is full then reset.
    }
}
