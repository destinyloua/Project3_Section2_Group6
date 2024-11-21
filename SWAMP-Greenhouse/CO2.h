#pragma once
#include "Device.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <raylib.h>

using namespace std;

class CO2: public Device
{
	double CO2Value; 
	bool isDanger; 
	string fileName; 
	vector<double> co2History; 
	int index; 
	double lastUpdateTime; 
	Texture2D trendGraph; 
	bool showTrendGraph; 

public:
	CO2();
	void displayWarning(); 
	void readData() override; 
	void simulateCO2Reading(); 
	void control() override; 
	void setLastUpdateTime(double newTime);

	bool isClicked(Rectangle r, int mouseButton);
	void drawCO2Button(Rectangle btn);
	void getTrendGraph(); 
	~CO2();

	friend class GUI;
};

