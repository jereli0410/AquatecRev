#include "DisplayLCD.h"

DisplayLCD::~DisplayLCD()
{
}

void DisplayLCD::begin()
{
    _lcd.init();
    _lcd.backlight();
}

void DisplayLCD::printAQUATEC()
{ 
    _lcd.setCursor(2, 0);
    _lcd.print("AQUATEC");
}

void DisplayLCD::printTDS(float tdsValue, int row)
{
    _lcd.setCursor(0, row);
    _lcd.print("TDS: ");
    _lcd.print(tdsValue);
}

void DisplayLCD::printpH(float pHValue, int row)
{
    _lcd.setCursor(0, row);
    _lcd.print("pH: ");
    _lcd.print(pHValue);
}

void DisplayLCD::printWarningNotPotable()
{
    _lcd.setCursor(1, 0);
    _lcd.print("!!!WARNING!!!");
    _lcd.setCursor(2, 1);
    _lcd.print("NOT POTABLE");
}

void DisplayLCD::printResetting()
{
    _lcd.setCursor(0,0);
    _lcd.print("RESETTING..");
}

void DisplayLCD::clear()
{
    _lcd.clear();
}


