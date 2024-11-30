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
    warning = "";
	fileName = "CO2Data.txt"; // name of simulation data file 
    co2History = {};
    index = 0; 
    lastUpdateTime = 0.0; 
}

void CO2::setWarning(string warning)
{
    this->warning = warning;
}

string CO2::getWarning(double CO2Value)
{
    if (CO2Value > 1500) {
        setWarning("CO2 Value: " + to_string(CO2Value) + " ppm, DANGER! Too High! ");
    }
    
    else if (CO2Value < 1000) {
        setWarning("CO2 Value: " + to_string(CO2Value) + " ppm, DANGER! Too Low! ");
    }

    else {
        setWarning("CO2 Value: " + to_string(CO2Value) + " ppm, OK! ");
    }

    return warning;
}

int CO2::getIndex()
{
    return index;
}

// display DANGER if value outside of threshold otherwise OK
void CO2::displayWarning()
{
    if (CO2Value > 1500) {
        DrawText(TextFormat("DANGER: CO2 level TOO HIGH"), 310, 740, 20, RED);
        DrawText(TextFormat("HUMAN HEALTH HAZARD!"), 310, 760, 20, RED);
        //cout << getWarning(CO2Value) << endl;
    }
    else if(CO2Value < 1000){
        DrawText(TextFormat("DANGER: CO2 level TOO LOW"), 310, 740, 20, RED);
        DrawText(TextFormat("PLANT HEALTH HAZARD!"), 310, 760, 20, RED);
       //cout << getWarning(CO2Value) << endl;
    }
    else {
        //cout << getWarning(CO2Value) << endl;
    }
}

void CO2::addToCO2History(double value)
{
    co2History.push_back(value);
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
    addToCO2History(value);
    }

    // verify data reading successful 
    cout << "All CO2 data read successfully" << endl;
}

// CO2 is monitor only - simulate data updating every 60 seconds as stated in requirements 
void CO2::simulateCO2Reading()
{
    while (index < co2History.size()) {
        CO2Value = co2History[index];
        cout << getWarning(CO2Value) << endl;
        index++; 
    }
    cout << endl;
}

// not actually controlling, but needed for testing 
void CO2::control()
{
    cout << "CO2 is monitor only...Simulating CO2 instead..." << endl; 
    simulateCO2Reading(); 
}

void CO2::setLastUpdateTime(double newTime)
{
    lastUpdateTime = newTime;
}

void CO2::setDanger()
{
    if (CO2Value > 1500 || CO2Value < 1000) {
        isDanger = true; 
    }
    else {
        isDanger = false; 
    }
}

void CO2::updateCO2Value(double currentTime)
{
    if (currentTime - lastUpdateTime >= 50.0) {
        CO2Value = co2History[index++];
        setDanger();
        cout << "CO2 value updated" << endl;
        setLastUpdateTime(currentTime);
    }
}

vector<double>& CO2::getCO2History()
{
    return co2History;
}

double CO2::getCurrentCO2(int index)
{
    return co2History[index];
}

bool CO2::isClicked(Rectangle r, int mouseButton)
{
    Vector2 mousePosition = GetMousePosition();

    return CheckCollisionPointRec(mousePosition, r) && IsMouseButtonPressed(mouseButton);
}

void CO2::drawCO2Button(Rectangle btn)
{ 
    double currentTime = GetTime();
  
    if (index < co2History.size()) {
        updateCO2Value(currentTime);
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
        displayTrendGraph(); 
    }
    else {
        hideTrendGraph();
    }

}

void CO2::displayTrendGraph()
{
    trendGraph = getTrendGraph("CO2TrendGraph.png");
    showTrendGraph = true;
}

// to be implemented with raylib 
Texture2D CO2::getTrendGraph(const char* graphPath)
{
    cout << "Displaying CO2 trends..." << endl;
    Image graph = LoadImage(graphPath);
    Texture2D trendGraph = LoadTextureFromImage(graph);
    UnloadImage(graph);
   
    return trendGraph;
}

void CO2::hideTrendGraph()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        showTrendGraph = false; 
    }
}

// to ensure proper cleanup 
CO2::~CO2()
{
	if (dataFile.is_open()) {
		dataFile.close(); 
	}

    //cout << "CO2Data.txt closed successfully" << endl; 
}
