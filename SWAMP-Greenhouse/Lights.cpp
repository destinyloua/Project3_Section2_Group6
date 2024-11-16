#include "Lights.h"

Lights::Lights(string lightType, double minLightLevel, double maxLightLevel) : lightType(lightType), minLightLevel(minLightLevel), maxLightLevel(maxLightLevel) {}

string Lights::getLightType() {
	return lightType;
}

double Lights::getminLightLevel() {
	return minLightLevel;
}
double Lights::getmaxLightLevel() {
	return maxLightLevel;
}
string Lights::setLightType(string lightType) {
	this->lightType = lightType;
}
double Lights::getminLightLevel(double minLightLevel) {
	this->minLightLevel = minLightLevel;
}
double Lights::getmaxLightLevel(double maxLightLevel) {
	this->maxLightLevel = maxLightLevel;
}
void Lights::setScheduel(int StartTime, int StopTime) {
	// still have to make this
}
Lights::~Lights() {
	// do nothing 
}