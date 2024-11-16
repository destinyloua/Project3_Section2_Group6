//#include "Energy.h"
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream> // used for parsing string data from file 
//#include <Windows.h> // used for Sleep()
//
//using namespace std;
//
//Energy::Energy()
//{ 
//	deviceName = "Energy Manager";
//	isActive = true;
//	lowPower = false;
//	watts = 0.0;
//	fileName = "EnergyData.txt"; 
//    index = 0;
//}
//
//void Energy::readData()
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
//        if (ss.fail()) {
//            cerr << "Error reading value from line: " << line << endl;
//            return;
//        }
//
//        watts = value;
//        energyHistory.push_back(watts);
//
//    }
//
//    // verify data reading successful 
//    cout << "All Energy data read successfully" << endl;
//}
//
//void Energy::enableLowPower()
//{
//    watts = 250;
//    lowPower = true; 
//    cout << "Low Power Mode: ON -- System will maintain " << watts << " watts" << endl;
//}
//
//void Energy::disableLowPower()
//{
//    lowPower = false; 
//    cout << "Low Power Mode: OFF -- Resuming normal power usage" << endl; 
//}
//
//void Energy::showPowerOptions()
//{
//    bool validInput = false;
//    cout << "Enter 'y' to enable Low Power Mode or 'n' to ignore warning" << endl;
//    char choice; 
//    cin >> choice; 
//    
//    while (!validInput) {
//        switch (choice) {
//        case 'y': case 'Y':
//            enableLowPower(); 
//            showPowerStatus();
//            validInput = true;
//            break;
//        case 'n': case 'N':
//            cout << "Low Power Mode was not enabled" << endl;
//            showPowerStatus();
//            validInput = true;
//            break; 
//        default:
//            cout << "Invalid input" << endl; 
//        }
//    }
//}
//
//void Energy::showPowerStatus()
//{
//    if (lowPower) {
//        cout << "Low Power Mode: ON" << endl; 
//    }
//    cout << "Low Power Mode: OFF" << endl;
//}
//
//void Energy::control()
//{
//    for (index = 0; index < energyHistory.size(); ++index) {
//        if (lowPower) {
//            watts = 250;
//        }
//        else {
//            watts = energyHistory[index];
//        }
//        cout << "Current Energy Usage: " << watts << " watts" << endl; 
//
//        if (watts > 300) {
//            showPowerOptions(); 
//        }
//
//        Sleep(5000);
//    }
//}
//
//Energy::~Energy()
//{
//	if (dataFile.is_open()) {
//		dataFile.close();
//	}
//
//	cout << "EnergyData.txt closed successfully" << endl;
//
//}



