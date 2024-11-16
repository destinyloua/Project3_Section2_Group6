#include "Device.h"
#include "Camera.h"
#include "User.h"
#include "GUI.h"
#include <iostream>
#include <vector>

using namespace std;

class System {
	vector <Device*> devices;
	Camera* camera; 
	GUI* gui;
	User* user;

public:
	System();
	// device management 
	void addDevice(Device* d); 
	void removeDevice(Device* d);
	vector<Device> getDevices(); 


	bool Initialize();
	bool Mornitor();
	bool Control();
	bool IsCriticalCondition();
};