#define _CRT_SECURE_NO_WARNINGS
#include "Device.h"
#include <iostream>

//Device.h Implementation

Device::Device(string deviceName)
{
	this->deviceName = deviceName; 
}

string Device::getDeviceName()
{
	return deviceName;
}
