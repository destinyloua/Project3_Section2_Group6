#pragma once
#include "Device.h"
#include <vector>
class SoilMoisture : public Device {
	int soilMoistureLevel;
	int threshold;
	vector<int> soilMoistureLog;
	string soilMoistureData;
	string alert;
public:
	SoilMoisture();
	~SoilMoisture();
	void readData() override;
	void control() override;
	void SetAlert(string message);
	void SetThreshold(int value);
	int GetThreshold();
	bool GetIrrigationStatus();
	void SetIrrigationStatus(bool status);
};