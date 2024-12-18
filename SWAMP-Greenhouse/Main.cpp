#define _CRT_SECURE_NO_WARNINGS

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
    // create devices
    CO2 c;
    c.readData(); 
    Energy e;
    e.readData(); 
    SoilMoisture s;
    Humidity h;
    Lights l;
    Temperature t;

    const int screenWidth = 1500;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "SWAMP - Sustainable Water Application for Managing Plants");
    SetTargetFPS(60);

    GUI gui;  // Create an instance of GUI
    CameraView camera;  // Create an instance of CameraView
    InputField inputField;
    InputField thresholdInput;

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

            gui.UpdateDrawing(c,e,s,h);  // Draw GUI elements
            camera.CameraDraw();  // Draw camera view
            if (c.showTrendGraph) {
                DrawTexture(c.trendGraph, 100, 100, WHITE);
            }
            if (e.showEnergyControls) {
                e.showPowerOptions(); 
            }
            if (h.showTable) {
                h.drawHumidityLogTable();
            }
            EndDrawing();
            break;
        }
        case LightsPage: {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            gui.DrawLightsScreen(l);
            EndDrawing();
            break;
        }
        case TemperaturePage: {
            BeginDrawing(); 
            ClearBackground(RAYWHITE); 
            gui.DrawTemperatureScreen(t);
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