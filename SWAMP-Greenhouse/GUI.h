#pragma once

#include "Device.h"
#include "raylib.h"
#include "CO2.h"
#include "Energy.h"
#include "SoilMoisture.h"
#define MAX_CHARS 50

enum Page { LoginPage = 0, MainPage , Quit};

class InputField {
public:
	char inputText[MAX_CHARS + 1] = { 0 };
	int textLength = 0;
	bool isActive = false;
	bool hasDecimalPoint = false;

	InputField();
	void Clear();
};

class GUI {
private:
	int userId;

public:
	int page;
	GUI();
	void SetUser(int userId);
	void Login();
	void InputFieldDraw(Rectangle rec, InputField& inputField, Color bColor, Color lColor, Color tColor, int fontSize, int maxChars);
	void DrawPanels(CO2& c, Energy& e, SoilMoisture& s);
	void DrawCameraControls();
	void UpdateDrawing(CO2& c, Energy& e, SoilMoisture& s);
	~GUI();
};
