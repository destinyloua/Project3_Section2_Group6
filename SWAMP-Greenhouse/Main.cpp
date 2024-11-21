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

	// Testing CO2 
	CO2 c; 
	c.readData();

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


	switch (gui.page)
	{
	case LoginPage: {
		gui.Login();
	}
	case MainPage: {
		gui.UpdateDrawing(c);
		break;
	}
	default:
		break;
	}
	


	
	CloseWindow();
	return 0; 
}