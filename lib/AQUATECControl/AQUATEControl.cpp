#include "AQUATECControl.h"

AquatecControl::AquatecControl(){
}

AquatecControl::~AquatecControl(){}

void AquatecControl::begin(){
    water = Water();
}

void AquatecControl::begin(int pHThreshold, int totaldissolvedsolidsThreshold){
    water = Water(pHThreshold, totaldissolvedsolidsThreshold);
}
