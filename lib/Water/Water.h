#ifndef Water_h
#define Water_h

#include <Arduino.h>

class Water{

    public:
        Water();
        Water(int pHThreshold, int totaldissolvedsolidsThreshold);
        ~Water();

        bool isPotable();

//Getters and Setters
        int getTemperature();
        void setTemperature(int temperature);
        float getpHLevel();
        void setpHLevel(float pHLevel);
        int gettotaldissolvedsolids();
        void settotaldissolvedsolids(int totaldissolvedsolids);
        int gettemperatureThreshold();
        void settemperatureThreshold(int temperatureThreshold);
        int getpHThreshold();
        void setpHThreshold(int pHThreshold);
        int gettotaldissolvedsolidsThreshold();
        void settotaldissolvedsolidsThreshold(int totaldissolvedsolidsThreshold);
    
    private:
        int _temperature;
        float _pHLevel;
        int _totaldissolvedsolids;
        int _temperatureThreshold;
        int _pHThreshold;
        int _totaldissolvedsolidsThreshold;

};

#endif //Water_h