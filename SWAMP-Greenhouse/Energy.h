#pragma once
#include <vector>
#include <fstream>
#include "Device.h"

class Energy: public Device
{
	double watts;
	bool lowPower;
	string fileName;
	vector<double> energyHistory;
	int index;

public:
	Energy();
	void readData() override;
	void enableLowPower(); 
	void disableLowPower(); 
	void showPowerOptions();
	void showPowerStatus(); 
	void control() override;
	~Energy(); 

};

