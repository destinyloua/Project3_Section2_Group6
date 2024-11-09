#pragma once
#include "Device.h"
#include "System.h"
class GUI
{
public:
	GUI();
	bool Login(System& system);
	void Panel(Device& device);
	void DisplayAlert(Device& device);
};

