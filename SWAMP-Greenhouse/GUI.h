#pragma once
#include "Device.h"
#include "raylib.h"

class GUI
{
private:
	int id;
	int userId;
	void DrawCameraControls();
	void DrawPanels();
public:
	GUI();
	bool Login();
	void Panel(Device& device);
	void DisplayAlert(Device& device);
	void Init();
	void UpdateDrawing();
	~GUI();
};