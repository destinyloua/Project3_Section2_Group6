#pragma once

#include "Device.h"
#include "raylib.h"
#include <string>
#include <iostream>

#define UNSAFE_BUFFER_TEMP 5

class Temperature : public Device
{
    int minTemp;
    int maxTemp;
    int actualTemp;
    string units;
    bool isTempOn;
    int index;
    double lastUpdateTime;

public:
    Temperature();
    void setMinThreshold(int minTemp);
    void setMaxThreshold(int maxTemp);
    void setUnits(string units);
    void setActualTemperature(int actualTemp);
    void setTempSwitch(bool status);
    int getMinThreshold();
    int getMaxThreshold();
    string getUnit();
    int getActualTemperature();
    void displayTempStatus();
    void readData() override;
    void control() override;
    void convertToFahrenheit();
    void convertToCelsius();
    ~Temperature();

    friend class GUI;
};