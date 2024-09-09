#include <Arduino.h>
#include "AQUATECControl.h"

// Test Functions Declarations:
void testWithBlink();

void testWaterData(AquatecControl aquatec); // requires Serial.begin(9600)

void testRelay(Relay relay);

void testDigitalIRSensor(DigitalIRSensor IRSensor);

void testTDSSensor(TDSSensor tdsSensor);

void testPHSensor(pHLevelSensor phSensor);

void testDisplayLCD(DisplayLCD displayLCD);

void testpHSensorVoltage(pHLevelSensor phSensor);

void testTDSSensorVoltage(TDSSensor tdsSensor);

// Sensor Pins:
#define PROXIMITY_SENSOR_PIN 7
#define TDS_SENSOR_PIN 15
#define PH_SENSOR_PIN 14
#define TEMPERATURE_SENSOR_PIN 99 // for temperature sensor futre implementation

#define LCD_COLUMNS 16
#define LCD_ROWS 2
#define DISPLAY_LCD_I2C_ADDRESS 0x27

// Actuator Pins:
#define SOURCE_VALVE_PIN 4
#define DRAIN_VALVE_PIN 5
#define DISPENSER_VALVE_PIN 6

// Initialize Components:
// Intialize Aquatec
AquatecControl aquateccontrol;

// Initialize Sensors //intialization happens at setup()

// Initialize Actuators //intialization happens at setup()

void setup()
{
  // put your setup code here, to run once:
  // setup Aquatec
  aquateccontrol.begin(7, 250); // pHThreshold, totaldissolvedsolidsThreshold
  // setup Sensors
  aquateccontrol.proximitySensor = DigitalIRSensor(PROXIMITY_SENSOR_PIN);
  aquateccontrol.proximitySensor.begin();
  aquateccontrol.tdsSensor = TDSSensor(TDS_SENSOR_PIN);
  aquateccontrol.tdsSensor.begin();
  aquateccontrol.pHSensor = pHLevelSensor(PH_SENSOR_PIN);
  aquateccontrol.pHSensor.begin();
  aquateccontrol.displayLCD = DisplayLCD(DISPLAY_LCD_I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS);
  aquateccontrol.displayLCD.begin();

  // setup Actuators
  aquateccontrol.sourceValve = Relay(LED_BUILTIN, false);
  aquateccontrol.sourceValve.begin();
  aquateccontrol.drainValve = Relay(DRAIN_VALVE_PIN, false);
  aquateccontrol.drainValve.begin();
  aquateccontrol.dispenserValve = Relay(DISPENSER_VALVE_PIN, false);
  aquateccontrol.dispenserValve.begin();

  // initialize AQUATEC
  aquateccontrol.init();

  Serial.begin(9600);

  aquateccontrol.displayLCD.printAQUATEC();
  aquateccontrol.update();
  delay(3000);
  aquateccontrol.displayLCD.clear();
}

void loop()
{
  // put your main code here, to run repeatedly:
  // Run Aquatec
  aquateccontrol.update();
  aquateccontrol.operate();
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
  Serial.print("TDS: ");
  Serial.println(tdsSensor.readTDS());
  delay(1000);
}

void testPHSensor(pHLevelSensor phSensor)
{
  Serial.print("pH: ");
  Serial.println(phSensor.readpHLevel());
  delay(1000);
}

void testDisplayLCD(DisplayLCD displayLCD)
{
  Serial.println("Printing AQUATEC");
  displayLCD.printAQUATEC();
  delay(1000);
  Serial.println("Printing pH");
  displayLCD.printpH(7.5, 0);
  delay(1000);
  Serial.println("Printing TDS");
  displayLCD.printTDS(1000, 1);
  delay(1000);
  Serial.println("Printing Temperature");
  displayLCD.printTemperature(25, 1);
  delay(1000);
  Serial.println("Printing Warning Not Potable");
  displayLCD.printWarningNotPotable();
  delay(1000);
  Serial.println("Printing Resetting");
  displayLCD.printResetting();
  delay(1000);
  Serial.println("Clearing");
  displayLCD.clear();
  delay(1000);
}

void testpHSensorVoltage(pHLevelSensor pHsensor){
  Serial.print("pH sensor voltage: ");
  Serial.println(pHsensor.readVoltage());
  delay(1000);
}

void testTDSSensorVoltage(TDSSensor TDSsensor){
  Serial.print("TDS sensor voltage: ");
  Serial.println(TDSsensor.readVoltage());
  delay(1000);
}