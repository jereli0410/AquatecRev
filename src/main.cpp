#include <Arduino.h>
#include "AQUATECControl.h"
#include <Relay.h>

// Test Functions Declarations:
void testWithBlink();

void testWaterData(AquatecControl aquatec); // requires Serial.begin(9600)

void testRelay(Relay relay);

void testDigitalIRSensor(DigitalIRSensor IRSensor);

void testTDSSensor(TDSSensor tdsSensor);

// Sensor Pins:
#define PROXIMITY_SENSOR_PIN 14
#define TDS_SENSOR_PIN 15

// Actuator Pins:
#define SOURCE_VALVE_PIN 4
#define DRAIN_VALVE_PIN 5
#define DISPENSER_VALVE_PIN 6

// Initialize Components:
// Intialize Aquatec
AquatecControl aquateccontrol;

// Initialize Sensors

// Initialize Actuators

void setup()
{
  // put your setup code here, to run once:
  // setup Aquatec
  aquateccontrol.begin(7, 175); // pHThreshold, totaldissolvedsolidsThreshold
  // setup Sensors
  aquateccontrol.proximitySensor = DigitalIRSensor(PROXIMITY_SENSOR_PIN);
  aquateccontrol.proximitySensor.begin();
  aquateccontrol.tdsSensor = TDSSensor(TDS_SENSOR_PIN);
  aquateccontrol.tdsSensor.begin();

  // setup Actuators
  aquateccontrol.sourceValve = Relay(LED_BUILTIN, false);
  aquateccontrol.sourceValve.begin();
  aquateccontrol.drainValve = Relay(DRAIN_VALVE_PIN, false);
  aquateccontrol.drainValve.begin();
  aquateccontrol.dispenserValve = Relay(DISPENSER_VALVE_PIN, false);
  aquateccontrol.dispenserValve.begin();

  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // Run Aquatec
  // Serial.println("Hello World");
  testTDSSensor(aquateccontrol.tdsSensor);
}

// Test Functions Definitions:
void testWithBlink()
{
  pinMode(LED_BUILTIN, OUTPUT);
  while (1)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}

void testWaterData(AquatecControl aquatec)
{
  Serial.print("pH Level: ");
  Serial.println(aquatec.water.getpHLevel());
  Serial.print("Total Dissolved Solids: ");
  Serial.println(aquatec.water.gettotaldissolvedsolids());
  Serial.print("Temperature: ");
  Serial.println(aquatec.water.getTemperature());
  Serial.print("pH Threshold: ");
  Serial.println(aquatec.water.getpHThreshold());
  Serial.print("Total Dissolved Solids Threshold: ");
  Serial.println(aquatec.water.gettotaldissolvedsolidsThreshold());
  Serial.print("Temperature Threshold: ");
  Serial.println(aquatec.water.gettemperatureThreshold());
  delay(10000); // TODO: Replace with interupt later
}

void testRelay(Relay relay)
{
  relay.turnOn();
  Serial.println(relay.getState());
  delay(1000);
  relay.turnOff();
  Serial.println(relay.getState());
  delay(1000);
}

void testDigitalIRSensor(DigitalIRSensor IRSensor)
{
  Serial.println(IRSensor.readProximity());
  delay(1000);
}

void testTDSSensor(TDSSensor tdsSensor)
{
  Serial.println(tdsSensor.readTDS());
  delay(1000);
}