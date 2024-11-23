#include "Temperature.h"

Temperature::Temperature()
{
    minTemp = 10;
    maxTemp = 30;
    actualTemp = 20;
    units = "C";
    isTempOn = false;
}
void Temperature::readData() {


}

void Temperature::control() {


}

void Temperature::setMinThreshold(int minTemp) {
    this->minTemp = minTemp;
}
void Temperature::setMaxThreshold(int maxTemp) {
    this->maxTemp = maxTemp;
}
void Temperature::setUnits(string units) {
    this->units = units;
}
void Temperature::setActualTemperature(int actualTemp) {
    this->actualTemp = actualTemp;
}
void Temperature::setTempSwitch(bool status) {
    isTempOn = status;
}

int Temperature::getMinThreshold() {
    return minTemp;
}
int Temperature::getMaxThreshold() {
    return maxTemp;
}
string Temperature::getUnit() {
    return units;
}
int Temperature::getActualTemperature() {
    return actualTemp;
}

void Temperature::displayTempStatus() {
    // Colorcoding status of temperature
    Color tempColor;
    Color tempColorSwitch;
    string tempText;

    if (actualTemp < minTemp) {
        tempColor = RED; // below safe threshold
    }
    else if (actualTemp >= minTemp + UNSAFE_BUFFER_TEMP && actualTemp <= maxTemp - UNSAFE_BUFFER_TEMP) {
        tempColor = GREEN; // safe level met
    }
    else {
        tempColor = YELLOW; // near unsafe threshold
    }


    // Draw temperature status on screen (GUI part using raylib)
    DrawText(("Current Temperature: " + to_string(actualTemp) + " " + units).c_str(), 10, 10, 20, BLACK);
    DrawText(("Min Temp: " + to_string(minTemp) + " " + units).c_str(), 10, 40, 20, BLACK);
    DrawText(("Max Temp: " + to_string(maxTemp) + " " + units).c_str(), 10, 70, 20, BLACK);
    if (isTempOn) {
        DrawText("Temp is ON", 10, 130, 20, GREEN);
    }
    else {
        DrawText("Temp is OFF", 10, 130, 20, RED);
    }

    // Display the temperature status with color
    DrawText(("Temperature Status: "), 10, 100, 20, tempColor);
}

void Temperature::convertToFahrenheit() {
    // Convert thresholds and actual temperature to Fahrenheit
    minTemp = minTemp * 1.8 + 32;
    maxTemp = maxTemp * 1.8 + 32;
    actualTemp = actualTemp * 1.8 + 32;
    units = "F";
}

void Temperature::convertToCelsius() {
    // Convert thresholds and actual temperature to Celsius
    minTemp = (minTemp - 32) / 1.8;
    maxTemp = (maxTemp - 32) / 1.8;
    actualTemp = (actualTemp - 32) / 1.8;
    units = "C";
}

Temperature::~Temperature() {
    //do nothing for now
}