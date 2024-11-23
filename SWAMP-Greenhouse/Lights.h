#pragma once

#include "Device.h"
#include "raylib.h"
#include <string>
#include <iostream>

#define UNSAFE_BUFFER_LIGHTS 5

class Lights : public Device
{
    string lightType; // LED
    int minLightLevel;
    int maxLightLevel;
    int actualLightLevel;
    bool isLightOn;
    int startTime;
    int stopTime;

public:
    Lights();
    string getLightType();
    int getminLightLevel();
    int getmaxLightLevel();
    int getActualLightLevel();
    void setActualLightLevel(int actualLightLevel);
    void setLightType(string lightType);
    void setminLightLevel(int minLightLevel);
    void setmaxLightLevel(int maxLightLevel);
    void setScheduel(int StartTime, int StopTime);
    void setLightSwitch(bool status);
    void displayLightStatus();
    void readData() override;
    void control() override;
    ~Lights();

    friend class GUI;
};

