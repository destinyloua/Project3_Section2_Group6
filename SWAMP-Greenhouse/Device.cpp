#define _CRT_SECURE_NO_WARNINGS
#include "Device.h"
#include <iostream>

//Device.h Implementation

Device::Device()
{
	deviceName = " ";
	isActive = true; 
}

string Device::getDeviceName()
{
	return deviceName;
}
