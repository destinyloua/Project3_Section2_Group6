#pragma once
#include <vector>
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
	void control() override;
	~Energy(); 

};

