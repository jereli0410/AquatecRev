#include "Water.h"

Water::Water(){
    _temperature = 0;
    _pHLevel = 0;
    _totaldissolvedsolids = 0;
    _temperatureThreshold = 0;
    _pHThreshold = 0;
    _totaldissolvedsolidsThreshold = 0;
}

Water::Water(int pHThreshold, int totaldissolvedsolidsThreshold){
    _temperature = 0;
    _pHLevel = 0;
    _totaldissolvedsolids = 0;
    _temperatureThreshold = 0;
    _pHThreshold = pHThreshold;
    _totaldissolvedsolidsThreshold = totaldissolvedsolidsThreshold;
}

Water::~Water(){}

bool Water::isPotable(){
    bool ispHLevelOK = _pHLevel > _pHThreshold-1.5&&_pHLevel < _pHThreshold+1.5;
    bool isTotalDissolvedSolidsOK = _totaldissolvedsolids > _totaldissolvedsolidsThreshold-175&&_totaldissolvedsolids < _totaldissolvedsolidsThreshold+175;

    return ispHLevelOK && isTotalDissolvedSolidsOK;
}

//Setters and Getters
int Water::getTemperature(){
    return _temperature;
}

void Water::setTemperature(int temperature){
    _temperature = temperature;
}

float Water::getpHLevel(){
    return _pHLevel;
}

void Water::setpHLevel(float pHLevel){
    _pHLevel = pHLevel;
}

int Water::gettotaldissolvedsolids(){
    return _totaldissolvedsolids;
}

void Water::settotaldissolvedsolids(int totaldissolvedsolids){
    _totaldissolvedsolids = totaldissolvedsolids;
}

int Water::gettemperatureThreshold(){
    return _temperatureThreshold;
}

void Water::settemperatureThreshold(int temperatureThreshold){
    _temperatureThreshold = temperatureThreshold;
}

int Water::getpHThreshold(){
    return _pHThreshold;
}

void Water::setpHThreshold(int pHThreshold){
    _pHThreshold = pHThreshold;
}

int Water::gettotaldissolvedsolidsThreshold(){
    return _totaldissolvedsolidsThreshold;
}

void Water::settotaldissolvedsolidsThreshold(int totaldissolvedsolidsThreshold){
    _totaldissolvedsolidsThreshold = totaldissolvedsolidsThreshold;
}

