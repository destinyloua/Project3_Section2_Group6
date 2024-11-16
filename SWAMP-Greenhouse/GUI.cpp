//#include "GUI.h"
//#include "raylib.h"
//
//GUI::GUI() {}
//
//void GUI::Init() {
//	// initialize screen size
//	const int screenWidth = 1500;
//	const int screenHeight = 1000;
//	InitWindow(screenWidth, screenHeight, "SWAMP - Sustainable Water Application for Managing Plants");
//	SetTargetFPS(60);
//}
//
//void GUI::DrawPanels() {
//	// Camera view
//	DrawRectangle(10, 90, 800, 500, DARKGRAY); // x, y, length, height, colour
//	DrawText("Camera View", 20, 100, 40, WHITE); // x, y, size, colour
//	
//	// Lights
//	DrawRectangle(850, 90, 600, 100, YELLOW); // x, y, length, height, colour
//	DrawText("Lights", 860, 100, 40, BLACK); // x, y, size, colour
//
//	// Temp
//	DrawRectangle(850, 210, 600, 100, BLUE); // x, y, length, height, colour
//	DrawText("Temperature", 860, 220, 40, BLACK); // x, y, size, colour
//
//	// CO2
//	DrawRectangle(850, 330, 600, 100, PINK); // x, y, length, height, colour
//	DrawText("CO2", 860, 340, 40, BLACK); // x, y, size, colour
//
//	// Humidity
//	DrawRectangle(850, 450, 600, 100, ORANGE); // x, y, length, height, colour
//	DrawText("Humidity", 860, 460, 40, BLACK); // x, y, size, colour
//
//	// Soil Moisture
//	DrawRectangle(850, 570, 600, 100, GREEN); // x, y, length, height, colour
//	DrawText("Soil Moisture", 860, 580, 40, BLACK); // x, y, size, colour
//
//	// Energy
//	DrawRectangle(850, 690, 600, 100, PURPLE); // x, y, length, height, colour
//	DrawText("Energy Management", 860, 700, 40, BLACK); // x, y, size, colour
//
//	// Notification Panel
//	DrawRectangle(10, 750, 800, 200, WHITE); // x, y, length, height, colour
//	DrawText("Notifications", 15, 760, 20, BLACK); // x, y, size, colour
//}
//
//void GUI::DrawCameraControls() {
//	// Camera Controls
//	// UP
//	DrawRectangle(10, 600, 100, 100, GRAY); // x, y, length, height, colour
//	DrawText("Up", 15, 620, 20, BLACK); // x, y, size, colour
//	// DOWN
//	DrawRectangle(120, 600, 100, 100, GRAY); // x, y, length, height, colour
//	DrawText("Down", 125, 620, 20, BLACK); // x, y, size, colour
//	// LEFT
//	DrawRectangle(230, 600, 100, 100, GRAY); // x, y, length, height, colour
//	DrawText("Left", 235, 620, 20, BLACK); // x, y, size, colour
//	// RIGHT
//	DrawRectangle(340, 600, 100, 100, GRAY); // x, y, length, height, colour
//	DrawText("Right", 345, 620, 20, BLACK); // x, y, size, colour
//	// ZOOM IN
//	DrawRectangle(450, 600, 150, 100, GRAY); // x, y, length, height, colour
//	DrawText("Zoom In", 455, 620, 20, BLACK); // x, y, size, colour
//	// ZOOM OUT
//	DrawRectangle(620, 600, 150, 100, GRAY); // x, y, length, height, colour
//	DrawText("Zoom Out", 625, 620, 20, BLACK); // x, y, size, colour
//}
//
//void GUI::UpdateDrawing() {
//	BeginDrawing();
//	// Background
//	Color customBackground = { 204, 204, 204, 255 }; // red, green, blue, opacity
//	ClearBackground(customBackground);
//	// SWAMP
//	DrawText("Sustainable Water Application for Monitoring Plants", 10, 10, 56, DARKGREEN); // x, y, size, colour
//	// Panels and camera controls
//	DrawPanels();
//	DrawCameraControls();
//
//	EndDrawing();
//}
//
//GUI::~GUI() {}