#include "CO2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // used for parsing string data from file 

using namespace std; 

// initialize with default values
CO2::CO2()
{
    deviceName = "CO2";
    isActive = true; 
	CO2Value = 0.0;
	isDanger = false; 
	fileName = "CO2Data.txt"; // name of simulation data file 
    index = 0; 
    lastUpdateTime = 0.0;
    trendGraph = LoadTexture("CO2TrendGraph.png");
    showTrendGraph = false; 
}

// display DANGER if value outside of threshold otherwise OK
void CO2::displayWarning()
{
    if (CO2Value > 1500) {
        isDanger = true;
        cout << "CO2 Value: " << CO2Value << " ppm, DANGER! Too High! " << endl;
    }
    else if(CO2Value < 1000){
        isDanger = true;
        cout << "CO2 Value: " << CO2Value << " ppm, DANGER! Too Low! " << endl;
    }
    else {
        cout << "CO2 Value: " << CO2Value << " ppm, OK!" << endl;
    }
}

// open file to read simulation data - add each value to vector for trend graph later 
void CO2::readData()
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

    // update CO2Value from data file 
    CO2Value = value;
    co2History.push_back(CO2Value); // add value to co2History vector 
    }

    // verify data reading successful 
    //cout << "All CO2 data read successfully" << endl;
}

// CO2 is monitor only - simulate data updating every 5 seconds as stated in requirements 
void CO2::simulateCO2Reading()
{
    while (index < co2History.size()) {
        CO2Value = co2History[index];
        displayWarning(); 
        //Sleep(5000); 
        index++; 
    }
}

// not actually controlling, but needed for testing 
void CO2::control()
{
    cout << "CO2 is monitor only...Simulating CO2 instead...(Updates every 5 seconds)" << endl; 
    simulateCO2Reading(); 
}

void CO2::setLastUpdateTime(double newTime)
{
    lastUpdateTime = newTime;
}

bool CO2::isClicked(Rectangle r, int mouseButton)
{
    Vector2 mousePosition = GetMousePosition();

    return CheckCollisionPointRec(mousePosition, r) && IsMouseButtonPressed(mouseButton);
}

void CO2::drawCO2Button(Rectangle btn)
{ 
    double currentTime = GetTime();
    //cout << "Current Time: " << currentTime << ", Last Update Time: " << lastUpdateTime << endl;
    if (index < co2History.size()) {
        // TESTING with 5 seconds -- change to 60 seconds later
        if (currentTime - lastUpdateTime >= 5.0) {
            CO2Value = co2History[index++];
            cout << "CO2 value updated" << endl;    
            setLastUpdateTime(currentTime);
        }   
    }
    else {
        // reset the data loop
        index = 0;
        if (!co2History.empty()) {
            CO2Value = co2History[index];
        }
        setLastUpdateTime(currentTime);
    }

    // for hover color
    Color btnColor = PINK;
    if (CheckCollisionPointRec(GetMousePosition(), btn)) {
        btnColor = MAGENTA;
    }

    // for danger color
    if (isDanger) {
        btnColor = RED;
    }

    // draw co2 button
    DrawRectangleRec(btn, btnColor);
    DrawText(deviceName.c_str(), btn.x + 10, btn.y + 10, 40, BLACK);

    // draw co2 value 
    ostringstream valueStream;
    valueStream.precision(2);
    valueStream << fixed << CO2Value << " ppm";
    string valueText = valueStream.str();
    DrawText(valueText.c_str(), btn.x + 10, btn.y + 60, 30, BLACK);

    // handle click 
    if (isClicked(btn, MOUSE_LEFT_BUTTON)) {
        getTrendGraph();
    }
  
}

// to be implemented with raylib 
void CO2::getTrendGraph()
{
    cout << "Displaying CO2 trends..." << endl; 
}

// to ensure proper cleanup 
CO2::~CO2()
{
    UnloadTexture(trendGraph);
	if (dataFile.is_open()) {
		dataFile.close(); 
	}

    //cout << "CO2Data.txt closed successfully" << endl; 
}
