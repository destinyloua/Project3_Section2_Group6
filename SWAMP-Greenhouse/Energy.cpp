#include "Energy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // used for parsing string data from file 
//#include <Windows.h> // used for Sleep()

using namespace std;

Energy::Energy()
{ 
	deviceName = "Energy Manager";
	isActive = true;
	lowPower = false;
    tooMuchPower = false; 
	watts = 0.0;
	fileName = "EnergyData.txt"; 
    index = 0;
    lastUpdateTime = 0.0;
}

void Energy::readData()
{
    // open file 
    dataFile.open(fileName);
    if (!dataFile) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    // get data from each line
    string line;
    while (getline(dataFile, line)) {
        stringstream ss(line);
        double value;
        ss >> value; // turn string into double value 

        if (ss.fail()) {
            cerr << "Error reading value from line: " << line << endl;
            return;
        }

        watts = value;
        energyHistory.push_back(watts);

    }

    // verify data reading successful 
    cout << "All Energy data read successfully" << endl;
}

void Energy::enableLowPower()
{
    watts = 250;
    lowPower = true; 
    cout << "Enabling Low Power -- System will maintain " << watts << " watts" << endl;
}

void Energy::disableLowPower()
{
    lowPower = false; 
    cout << "Disabling Low Power -- Resuming normal power usage" << endl; 
}

void Energy::showPowerOptions()
{
    if (!showEnergyControls) {
        return;
    }

    Rectangle panel = { 450, 300, 550, 350 };
    DrawRectangleRec(panel, WHITE);
    DrawText("Energy Control Panel", panel.x + 20, panel.y + 20, 30, BLACK);
    DrawText("Low Power Mode:", panel.x + 20, panel.y + 100, 30, BLACK);
    
    // to enable low power
    Rectangle onButton = { panel.x + 20, panel.y + 150, 120, 50 };
    Color onButtonColor = lowPower ? GREEN : LIGHTGRAY;
    DrawRectangleRec(onButton, onButtonColor);
    DrawText("ON", onButton.x + 35, onButton.y + 10, 30, BLACK);

    if (CheckCollisionPointRec(GetMousePosition(), onButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        enableLowPower();
    }
    
    // to disable low power
    Rectangle offButton = { panel.x + 20, panel.y + 250, 120, 50 };
    Color offButtonColor = lowPower ? LIGHTGRAY : RED;
    DrawRectangleRec(offButton, offButtonColor);
    DrawText("OFF", offButton.x + 35, offButton.y + 10, 30, BLACK);

    if (CheckCollisionPointRec(GetMousePosition(), offButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        disableLowPower();
    }
 
    // to close controls 
    Rectangle closeButton = { panel.x + 400, panel.y + 280, 120, 50 };
    DrawRectangleRec(closeButton, LIGHTGRAY);
    DrawText("Close", closeButton.x + 20, closeButton.y + 10, 30, BLACK);

    if (CheckCollisionPointRec(GetMousePosition(), closeButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        showEnergyControls = false;
    }
}

void Energy::showPowerStatus()
{
    if (lowPower) {
        cout << "Low Power Mode: ON" << endl; 
    }
    else {
        cout << "Low Power Mode: OFF" << endl;
    }
}

void Energy::control()
{
    if (lowPower) {
        cout << "Low power is already ON" << endl;
    }

    enableLowPower();
}

void Energy::setLastUpdateTime(double newTime)
{
    lastUpdateTime = newTime;
}

void Energy::setTooMuchPower()
{
    if (watts > 300) {
        tooMuchPower = true;
    }
    else {
        tooMuchPower = false;
    }
}

bool Energy::isClicked(Rectangle r, int mouseButton)
{
    Vector2 mousePosition = GetMousePosition();

    return CheckCollisionPointRec(mousePosition, r) && IsMouseButtonPressed(mouseButton);
}

void Energy::displayWarning()
{
    if (watts > 300) {
        DrawText(TextFormat("WARNING: Power usage TOO HIGH"), 310, 790, 20, RED);
        DrawText(TextFormat("Reduce Power in Energy Manager"), 310, 810, 20, RED);
    }
}

void Energy::drawEnergyButton(Rectangle btn)
{
    double currentTime = GetTime();

    if (index < energyHistory.size()) {
        if (currentTime - lastUpdateTime >= 30.0) {
            watts = energyHistory[index++];
            if (lowPower) {
                watts = 250.00;
            }
            setTooMuchPower(); 
            cout << "Energy value updated" << endl;
            setLastUpdateTime(currentTime);
        }
    }
    else {
        // reset the data loop
        index = 0;
        if (!energyHistory.empty()) {
            watts = energyHistory[index];
        }
        setLastUpdateTime(currentTime);
    }

    // for hover color
    Color btnColor = PURPLE;
    if (CheckCollisionPointRec(GetMousePosition(), btn)) {
        btnColor = DARKPURPLE;
    }

    // for danger color
    if (tooMuchPower) {
        btnColor = RED;
    }

    // draw co2 button
    DrawRectangleRec(btn, btnColor);
    DrawText(deviceName.c_str(), btn.x + 10, btn.y + 10, 40, BLACK);

    // draw co2 value 
    ostringstream valueStream;
    valueStream.precision(2);
    valueStream << fixed << watts << " watts";
    string valueText = valueStream.str();
    DrawText(valueText.c_str(), btn.x + 10, btn.y + 60, 30, BLACK);

    // handle click 
    if (isClicked(btn, MOUSE_LEFT_BUTTON)) {
        cout << "Energy button clicked" << endl;
        showEnergyControls = true;
    }
    else {
        hideEnergyControls();
    }
 
}

void Energy::hideEnergyControls()
{
    if (IsKeyPressed(KEY_ESCAPE)) {
        showEnergyControls = false;
    }
}

Energy::~Energy()
{
	if (dataFile.is_open()) {
		dataFile.close();
	}

	cout << "EnergyData.txt closed successfully" << endl;

}



