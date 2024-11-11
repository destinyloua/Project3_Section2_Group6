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
	void readData();
	void control();
	void SetAlert(string message);
	void SetThreshold(int value);
	int GetThreshold();
	bool GetIrrigationStatus();
	void SetIrrigationStatus(bool status);
};