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
#include "Camera.h"
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

	// Humidity
	//HumiditySensor hs;
	//hs.generateRandomHumidity();

    const int screenWidth = 1500;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "SWAMP - Sustainable Water Application for Managing Plants");
    SetTargetFPS(60);

    GUI gui;  // Create an instance of GUI
    CameraView camera;  // Create an instance of CameraView
    InputField inputField;

    while (!WindowShouldClose()) {
        switch (gui.page) {
        case LoginPage: {
            gui.Login();
            break;
        }
        case MainPage: {
            camera.CameraUpdate();  // Update camera

            BeginDrawing();

            gui.UpdateDrawing();  // Draw GUI elements
            camera.CameraDraw();  // Draw camera view

            EndDrawing();
            break;
        }
        default:
            break;
        }
    }

    CloseWindow();
    return 0;

}