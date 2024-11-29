#pragma once
#include "Device.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "raylib.h""

using namespace std;

class CO2: public Device
{
	double CO2Value; 
	bool isDanger; 
	string warning;
	string fileName; 
	vector<double> co2History; 
	int index; 
	double lastUpdateTime; 

public:
	CO2();
	void setWarning(string warning);
	string getWarning(double CO2Value);
	int getIndex();
	void displayWarning(); 
	void addToCO2History(double value);
	void readData() override; 
	void simulateCO2Reading(); 
	void control() override; 
	void setLastUpdateTime(double newTime);
	void setDanger();
	void updateCO2Value(double currentTime);
	vector <double>& getCO2History();
	double getCurrentCO2(int index); 

	Texture2D trendGraph;
	bool showTrendGraph = false;
	bool isClicked(Rectangle r, int mouseButton);
	void drawCO2Button(Rectangle btn);
	void displayTrendGraph();
	Texture2D getTrendGraph(const char* graphPath); 
	void hideTrendGraph(); 
	~CO2();

	friend class GUI;
	friend class SWAMP_TESTS;
};

