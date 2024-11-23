#include "Lights.h"

using namespace std;

Lights::Lights()
{

    lightType = "LED";
    minLightLevel = 20;
    maxLightLevel = 80;
    actualLightLevel = 50;
    isLightOn = false;
    startTime = 0;
    stopTime = 0;
}

void Lights::readData() {


}
void Lights::control() {


}

string Lights::getLightType() {
    return lightType;
}
int Lights::getminLightLevel() {
    return minLightLevel;
}
int Lights::getmaxLightLevel() {
    return maxLightLevel;
}
int Lights::getActualLightLevel() {
    return actualLightLevel;
}

void Lights::setActualLightLevel(int actualLightLevel) {
    this->actualLightLevel = actualLightLevel;
}

void Lights::setLightType(string lightType) {
    this->lightType = lightType;
}
void Lights::setminLightLevel(int minLightLevel) {
    this->minLightLevel = minLightLevel;
}
void Lights::setmaxLightLevel(int maxLightLevel) {
    this->maxLightLevel = maxLightLevel;
}
void Lights::setScheduel(int StartTime, int StopTime) {
    this->startTime = StartTime;
    this->stopTime = StopTime;
}
void Lights::setLightSwitch(bool status) {
    this->isLightOn = status;
}

void Lights::displayLightStatus() {
    // coloring status of light level
    Color lightColor;
    if (actualLightLevel < minLightLevel || actualLightLevel > maxLightLevel) {
        lightColor = RED; // below safe threshold
    }
    else if (actualLightLevel >= minLightLevel + UNSAFE_BUFFER_LIGHTS && actualLightLevel <= maxLightLevel - UNSAFE_BUFFER_LIGHTS) {
        lightColor = GREEN; // safe level met
    }
    else {
        lightColor = YELLOW; // near unsafe threshold
    }

    // Draw light status on screen (GUI part using raylib)
    DrawText(("Light Type: " + lightType).c_str(), 10, 10, 20, BLACK);
    DrawText(("Light Level: " + to_string(actualLightLevel) + "%").c_str(), 10, 40, 20, lightColor);
    DrawText(("Schedule: " + to_string(startTime) + " - " + to_string(stopTime)).c_str(), 10, 70, 20, BLACK);

    // Display the light's on/off status with color
    if (isLightOn) {
        DrawText("Light is ON", 10, 100, 20, GREEN);
    }
    else {
        DrawText("Light is OFF", 10, 100, 20, RED);
    }
}


Lights::~Lights() {
    // do nothing 
}
