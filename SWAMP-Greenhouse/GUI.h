#pragma once
#include "Device.h"
#include "System.h"
#include "raylib.h"

class GUI
{
private:
	//int id;
	//int userId;
	void DrawCameraControls();
	void DrawPanels();
public:
	GUI();
	~GUI();
	//bool Display();
	void Init();
	void UpdateDrawing();
	//bool Login(System& system);
	//void Panel(Device& device);
	//void DisplayAlert(Device& device);
};