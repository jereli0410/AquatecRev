#ifndef DisplayLCD_h
#define DisplayLCD_h

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class DisplayLCD
{
public:
    DisplayLCD() : _lcd(0x27, 16, 2) {}; // initialized to 0x27.
    DisplayLCD(uint8_t lcdAddress, uint8_t lcdColumns, uint8_t lcdRows) : _lcd(lcdAddress, lcdColumns, lcdRows)
    {
        _lcd = LiquidCrystal_I2C(lcdAddress, lcdColumns, lcdRows);
    };
    ~DisplayLCD();

    void begin();

    void printAQUATEC();
    void printTDS(float tdsValue, int row);
    void printpH(float pHValue, int row);
    void printTemperature(float temperature, int row);
    void printWarningNotPotable();
    void printWaitingForWater();
    void printDispensingWater();
    void printResetting();

    void clear();

private:
    LiquidCrystal_I2C _lcd;
};

#endif // DisplayLCD_h