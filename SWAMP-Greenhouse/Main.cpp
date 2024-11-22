// CSCN72030 - Project III
// Aiden, Destiny, Liam, Tyler
// The SWAMP 

#include "raylib.h" // make sure you have raylib installed 
#include <iostream>
#include <vector>
#include "Device.h"
#include "CO2.h"
#include "Energy.h"
#include "Humidity.h"
#include "GUI.h"
#include "SoilMoisture.h"

using namespace std;

int test(SoilMoisture soil) {
	return soil.getData();
}

int main() {

	// 
	//// create the collection of devices -- need to update with System class  
	//vector<Device*> devices;
	//
	//// adding devices to the system 
	//devices.push_back(new Energy());
	//devices.push_back(new CO2());
	//
	//
	//// testing devices 
	//for (Device* device: devices) {
	//	cout << "Testing " << device->getDeviceName() << endl; 
	//	device->readData();
	//	device->control();
	//}

	//// clean up devices 
	//for (Device* device : devices) {
	//	delete device; 
	//}

	// Humidity
	//HumiditySensor hs;
	//hs.generateRandomHumidity();

	// GUI
	GUI gui;
	SoilMoisture soil;
	vector<Device*> devices;
	Device* soilSTuff = &soil;
	devices.push_back(soilSTuff);

	// initialize gui
	// 
	// while the window is open, draw
	const int screenWidth = 1500;
	const int screenHeight = 1000;
	InitWindow(screenWidth, screenHeight, "SWAMP - Sustainable Water Application for Managing Plants");
	SetTargetFPS(60);
	InputField inputField;


	switch (gui.page)
	{
	case LoginPage: {
		gui.Login();
	}
	case MainPage: {
		gui.UpdateDrawing(devices);
		break;
	}
	default:
		break;
	}
	CloseWindow();
	return 0; 
}