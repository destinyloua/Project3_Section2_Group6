#pragma once
#include <vector>
#include <fstream>
#include "Device.h"
#include <raylib.h>

class Energy: public Device
{
	double watts;
	bool lowPower;
	bool tooMuchPower; 
	string fileName;
	vector<double> energyHistory;
	int index;
	double lastUpdateTime;

public:
	Energy();
	void readData() override;
	void enableLowPower(); 
	void disableLowPower(); 
	void showPowerOptions();
	void showPowerStatus(); 
	void control() override;
	void setLastUpdateTime(double newTime);
	void setTooMuchPower();

	bool isClicked(Rectangle r, int mouseButton);
	bool showEnergyControls = false;
	void displayWarning();
	void drawEnergyButton(Rectangle btn); 
	void hideEnergyControls(); 
	
	~Energy(); 

	friend class GUI; 
};

