#include "SoilMoisture.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <raylib.h>

using namespace std;
#define SIMULATION_FILE "moistureData.txt"
#define SLEEPTIME 5

SoilMoisture::SoilMoisture()
{
	this->threshold = 30;
	this->soilMoistureLevel = 0;
	this->soilMoistureData = SIMULATION_FILE;
	this->irrigation = true;
	this->fp.open(soilMoistureData);
}

SoilMoisture::~SoilMoisture()
{
}

void SoilMoisture::readData()
{
	if (!fp.is_open()) {
		cerr << "ERROR: Can not ope file" << endl;
		return;
	}
	string line;
	if (getline(fp, line)) {
		this->soilMoistureLevel = stod(line);
	}
	return;
}

void SoilMoisture::control()
{
	if (soilMoistureLevel < 30) {
		this->irrigation = true;
	}
}

double SoilMoisture::GetThreshold()
{
	return threshold;
}

void SoilMoisture::SetThreshold(int value)
{
	this->threshold = value;
}

double SoilMoisture::GetData()
{
	return soilMoistureLevel;
}

void SoilMoisture::SetIrrigationStatus()
{
	if (irrigation == true) {
		this->irrigation = false;
	}
	else {
		this->irrigation = true;
	}
}

bool SoilMoisture::GetIrrigation()
{
	return irrigation;
}