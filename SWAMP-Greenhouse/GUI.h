#pragma once
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
};

