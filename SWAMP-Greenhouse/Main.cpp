// CSCN72030 - Project III
// Aiden, Destiny, Liam, Tyler
// The SWAMP 

//#include "raylib.h" // make sure you have raylib installed 
#include <iostream>
#include <vector>
#include "Device.h"
#include "CO2.h"
#include "Energy.h"
#include "GUI.h"

using namespace std;

int main() {

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

	// Liam: I commented it out for now so things can still run without the raylib stuff
	// GUI things
	GUI gui;
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
		gui.UpdateDrawing();
	}
	default:
		break;
	}

	return 0; 
}