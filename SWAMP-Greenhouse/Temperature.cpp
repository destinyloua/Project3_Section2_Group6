#include "Temperature.h"

Temperature::Temperature(int minTemp, int maxTemp, int actualTemp, std::string units) : minTemp(minTemp), maxTemp(maxTemp), actualTemp(actualTemp), units(units) {}

void Temperature::setMinThreshold(int minTemp) {
    this->minTemp = minTemp;
}

void Temperature::setMaxThreshold(int maxTemp) {
    this->maxTemp = maxTemp;
}

void Temperature::setUnits(string units) {
    this->units = units;
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

Temperature::~Temperature() {
    //do nothing for now
}