#pragma once
#include "Device.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class CO2: public Device
{
	double CO2Value; 
	bool isDanger; 
	string fileName; 
	vector<double> co2History; 
	int index; 

public:
	CO2();
	void displayWarning(); 
	void readData() override; 
	void simulateCO2Reading(); 
	void control() override; 
	void getTrendGraph(); 
	~CO2();
};

