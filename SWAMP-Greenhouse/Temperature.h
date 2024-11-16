#pragma once

#include "Device.h"
#include "string"
#include <iostream>

class Temperature : public Device
{
	int minTemp;
	int maxTemp;
	int actualTemp;
	string units;

public:
	Temperature(int minTemp, int maxTemp, int actualTemp, std::string units);
	double setMinThreshold(double minTemp);
	double setMaxThreshold(double maxTemp);
	string setUnits(string units);
	double getMinThreshold();
	double getMaxThreshold();
	string getUnit();
	~Temperature();
};

