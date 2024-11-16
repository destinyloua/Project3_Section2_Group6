#pragma once

#include "Device.h"
#include <string>
#include <iostream>

class Lights : public Device
{
	string lightType; // LED
	double minLightLevel;
	double maxLightLevel;

public:
	Lights(string lightType, double minLightLevel, double maxLightLevel);
	string getLightType();
	double getminLightLevel();
	double getmaxLightLevel();
	string setLightType(string lightType);
	double getminLightLevel(double minLightLevel);
	double getmaxLightLevel(double maxLightLevel);
	void setScheduel(int StartTime, int StopTime);
	~Lights();
};

