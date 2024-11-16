#pragma once
#include <string>
#include <vector>
using namespace std;
// outline for the greenhouse system - may need to be adjusted during the design phase
// this will be deleted after we take what we need 

// commented out because it was interfering with testing 

// Aiden: temperature + light
// Destiny: CO2 + energy
// Liam: humidity + camera
// Tyler: soil moisture + system

// devices: temperature, humidity, CO2, soil moisture, light, energy manager
//class Device {
//	string deviceName;
//	double data;
//	double threshhold;
//	bool isActive;
//
//public:
//	Device();
//	virtual void readData(string fileName);
//	virtual double getData();
//	virtual void control();
//	~Device();
//};

// Camera will be a separate class
//class Camera {
//	bool isRecording;
//	bool motionDetected;
//	int zoomLevel;
//	string cloudStoragePath;
//	int positionX;
//	int positionY;
//
//public:
//	Camera();
//	void viewLiveFeed();
//	void recordAndSaveToCloud();
//	void detectMotion();
//	void alertUser();
//	void zoomIn();
//	void zoomOut();
//	void moveLeft();
//	void moveRight();
//	void moveUp();
//	void moveDown();
//};

// The greenhouse has a collection of devices + a camera 
//class System {
//	vector <Device> devices;
//	Camera c;
//
//public:
//	System();
//	void addDevice(Device d);
//	void addCamera(Camera c);
//	~System();
//};


// Device instances 
//class Temperature : public Device {
//	double mintemp;
//	double maxtemp;
//	string unit; // Celsius, Fahrenheit
//
//public:
//	Temperature();
//	double getMinThreshold();
//	double getMaxThreshold();
//	string getUnit();
//	bool goodTemp();
//};
//
//class Light : public Device {
//	string lightType; // LED
//	double safeLightLevel;
//
//public:
//	Light();
//	string getLightType();
//	double getSafeLightLevel();
//	void setScheduel(int StartTime, int StopTime);
//};

// monitor only
//class CO2 : public Device {
//	double dangerLevel;
//
//public:
//	CO2();
//	string getDangerLevel();
//	void createGraph();
//	bool danger();
//};

//class Energy : public Device {
//	double usage;
//
//public:
//	Energy();
//	double calculateUsage();
//	string generateReport();
//};
//
//// monitor only 
//class Humidity : public Device {
//	double currentHumidity;
//	double minHumidity;
//	double maxHumidity;
//public:
//	Humidity();
//	void logData();
//	bool alert();
//};
//
//class SoilMoisture : public Device {
//	double minMoisture;
//public:
//	SoilMoisture();
//	void setSchedule(string start, string end);
//	bool lowMoisture();
//	void setWaterSchedule(int start, int end);
//};
//
//// for login
//class User {
//	string userName;
//	string password;
//	bool login;
//public:
//	bool loginStatus;
//};
//
//class Interface {
//	// pending GUI library selection
//public:
//	bool display();
//};