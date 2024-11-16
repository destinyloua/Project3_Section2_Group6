//#include "SoilMoisture.h"
//#include <fstream>
//#include <sstream>
//#include <string>
//#include <iostream>
//#include <raylib.h>
//#include <Windows.h>
//
//using namespace std;
//#define SIMULATION_FILE "moistureData.txt"
//SoilMoisture::SoilMoisture()
//{
//	this->threshold = 30;
//	this->soilMoistureLevel = 0;
//	this->soilMoistureData = SIMULATION_FILE;
//	this->alert = "";
//}
//
//SoilMoisture::~SoilMoisture()
//{
//}
//
//void SoilMoisture::readData()
//{
//	ifstream fp;
//	fp.open(soilMoistureData);
//	if (!fp.is_open()) {
//		cerr << "ERROR: Can not ope file" << endl;
//	}
//	string line;
//	while (getline(fp, line)) {
//		this->soilMoistureLevel = stoi(line);
//		Sleep(30000);
//	}
//}
//
//void SoilMoisture::SetAlert(string message)
//{
//	this->alert = message;
//}
