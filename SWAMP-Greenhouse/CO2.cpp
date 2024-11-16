//// The CO2 monitoring system should get data from a .txt file to simulate the system reading CO2 data every 5 seconds. 
//// The values obtained from the .txt file will get stored in a vector. 
//// This module is monitor only - user will not be able to control. 
//// User will be able to view trend graph of all CO2 data (values stored in the vector) -- pending implementation with raylib 
//// Destiny 
//
//#include "CO2.h"
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream> // used for parsing string data from file 
//#include <Windows.h> // used for Sleep()
//
//using namespace std; 
//
//// initialize with default values
//CO2::CO2()
//{
//    deviceName = "CO2 Sensor";
//    isActive = true; 
//	CO2Value = 0.0;
//	isDanger = false; 
//	fileName = "CO2Data.txt"; // name of simulation data file 
//    index = 0; 
//}
//
//// display DANGER if value outside of threshold otherwise OK
//void CO2::displayWarning()
//{
//    if (CO2Value > 1500) {
//        isDanger = true;
//        cout << "CO2 Value: " << CO2Value << " ppm, DANGER! Too High! " << endl;
//    }
//    else if(CO2Value < 1000){
//        isDanger = true;
//        cout << "CO2 Value: " << CO2Value << " ppm, DANGER! Too Low! " << endl;
//    }
//    else {
//        cout << "CO2 Value: " << CO2Value << " ppm, OK!" << endl;
//    }
//}
//
//// open file to read simulation data - add each value to vector for trend graph later 
//void CO2::readData()
//{
//    // open file 
//    dataFile.open(fileName);
//    if (!dataFile) {
//        cerr << "Error opening file: " << fileName << endl;
//        return;
//    }
//
//    // get data from each line
//    string line;
//    while (getline(dataFile, line)) {
//        stringstream ss(line);
//        double value;
//        ss >> value; // turn string into double value 
//
//    if (ss.fail()) {
//        cerr << "Error reading value from line: " << line << endl;
//        return;
//        }
//
//    // update CO2Value from data file 
//    CO2Value = value;
//    co2History.push_back(CO2Value); // add value to co2History vector 
//    }
//
//    // verify data reading successful 
//    cout << "All CO2 data read successfully" << endl;
//}
//
//// CO2 is monitor only - simulate data updating every 5 seconds as stated in requirements 
//void CO2::simulateCO2Reading()
//{
//    while (index < co2History.size()) {
//        CO2Value = co2History[index];
//        displayWarning(); 
//        Sleep(5000); 
//        index++; 
//    }
//}
//
//// not actually controlling, but needed for testing 
//void CO2::control()
//{
//    cout << "CO2 is monitor only...Simulating CO2 instead...(Updates every 5 seconds)" << endl; 
//    simulateCO2Reading(); 
//}
//
//// to be implemented with raylib 
//void CO2::getTrendGraph()
//{
//    cout << "Displaying CO2 trends..." << endl; 
//}
//
//// to ensure proper cleanup 
//CO2::~CO2()
//{
//	if (dataFile.is_open()) {
//		dataFile.close(); 
//	}
//
//    cout << "CO2Data.txt closed successfully" << endl; 
//}
