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
    // create CO2 device
    CO2 c;
    c.readData(); 
    Energy e;
    e.readData(); 
    SoilMoisture s;

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

    double lastUpdateTime = GetTime();

    while (!WindowShouldClose() && gui.page!=Quit) {
        if (GetTime() - lastUpdateTime >= 1) {
            s.readData();
            s.control();
            lastUpdateTime = GetTime();
        }
        switch (gui.page) {
        case LoginPage: {
            gui.Login();
            break;
        }
        case MainPage: {
            camera.CameraUpdate();  // Update camera

            BeginDrawing();

            gui.UpdateDrawing(c,e,s);  // Draw GUI elements
            camera.CameraDraw();  // Draw camera view
            if (c.showTrendGraph) {
                DrawTexture(c.trendGraph, 100, 100, WHITE);
            }
            if (e.showEnergyControls) {
                e.showPowerOptions(); 
            }
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