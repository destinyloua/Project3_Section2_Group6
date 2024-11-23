#pragma once
#include "Device.h"
#include <vector>
class SoilMoisture : public Device {
	double soilMoistureLevel;
	double threshold;
	string soilMoistureData;
	bool irrigation;
	ifstream fp;
public:
	SoilMoisture();
	~SoilMoisture();
	void readData() override;
	void control() override;
	double GetThreshold();
	void IncreaseThreshold();
	void DecreaseThreshold();
	double GetData();
	void SetIrrigationStatus();
	bool GetIrrigation();
};