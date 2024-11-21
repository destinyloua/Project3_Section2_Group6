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

public:
	CO2();
	void displayWarning(); 
	void readData() override; 
	void simulateCO2Reading(); 
	void control() override; 
	void setLastUpdateTime(double newTime);
	void setDanger(); 

	Texture2D trendGraph;
	bool showTrendGraph = false;
	bool isClicked(Rectangle r, int mouseButton);
	void drawCO2Button(Rectangle btn);
	void displayTrendGraph();
	Texture2D getTrendGraph(const char* graphPath); 
	void hideTrendGraph(); 
	~CO2();

	friend class GUI;
};

