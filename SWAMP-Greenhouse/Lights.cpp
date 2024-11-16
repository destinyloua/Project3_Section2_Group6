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
void Lights::setLightType(string lightType) {
    this->lightType = lightType;
}
void Lights::setminLightLevel(double minLightLevel) {
    this->minLightLevel = minLightLevel;
}
void Lights::setmaxLightLevel(double maxLightLevel) {
    this->maxLightLevel = maxLightLevel;
}
void Lights::setScheduel(int StartTime, int StopTime) {
    // still have to make this
}
Lights::~Lights() {
    // do nothing 
}