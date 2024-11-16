#pragma once

#include "Device.h"
#include <string>
#include <iostream>

class Temperature : public Device
{
    int minTemp;
    int maxTemp;
    int actualTemp;
    string units;

public:
    Temperature(int minTemp, int maxTemp, int actualTemp, std::string units);
    void setMinThreshold(int minTemp);
    void setMaxThreshold(int maxTemp);
    void setUnits(string units);
    int getMinThreshold();
    int getMaxThreshold();
    string getUnit();
    ~Temperature();
};