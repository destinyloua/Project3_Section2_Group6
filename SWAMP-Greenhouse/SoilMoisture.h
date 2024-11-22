#pragma once
#include "Device.h"
#include <vector>
class SoilMoisture : public Device {
	double soilMoistureLevel;
	double threshold;
	vector<int> soilMoistureLog;
	string soilMoistureData;
	bool irrigation;
	ifstream fp;
public:
	SoilMoisture();
	~SoilMoisture();
	void readData() override;
	void control() override;
	double getThreshold() override;
	bool getMarker() override;
	void SetThreshold(int value);
	double getData() override;
	void SetIrrigationStatus(bool status);
};