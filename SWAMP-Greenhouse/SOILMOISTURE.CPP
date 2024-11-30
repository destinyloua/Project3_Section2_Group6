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
	this->irrigation = false;
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
		cout << soilMoistureLevel << endl;
	}
	return;
}

void SoilMoisture::control()
{
	if (soilMoistureLevel < threshold) {
		this->irrigation = true;
	}
}

double SoilMoisture::GetThreshold()
{
	return threshold;
}

void SoilMoisture::IncreaseThreshold()
{
	this->threshold++;
}
void SoilMoisture::DecreaseThreshold()
{
	this->threshold--;
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