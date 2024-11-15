#define _CRT_SECURE_NO_WARNINGS
// Camera.h implementation
#include "Camera.h"
#include "raylib.h"
#include <fstream>
#include <iostream>

Camera::Camera() {} 

// Camera view on the screen
void Camera::DrawCameraPanel() {
	DrawRectangle(10, 90, 800, 500, DARKGRAY); // x, y, length, height, colour
	DrawText("Camera View", 20, 100, 40, WHITE); // x, y, size, colour
}

// Camera Controls
void Camera::DrawCameraControls() {
	// UP
	DrawRectangle(120, 600, 100, 100, GRAY); // x, y, length, height, colour
	DrawText("UP", 125, 610, 20, BLACK); // x, y, size, colour
	// DOWN
	DrawRectangle(120, 710, 100, 100, GRAY); // x, y, length, height, colour
	DrawText("DOWN", 125, 720, 20, BLACK); // x, y, size, colour
	// LEFT
	DrawRectangle(10, 710, 100, 100, GRAY); // x, y, length, height, colour
	DrawText("LEFT", 15, 720, 20, BLACK); // x, y, size, colour
	// RIGHT
	DrawRectangle(230, 710, 100, 100, GRAY); // x, y, length, height, colour
	DrawText("RIGHT", 235, 720, 20, BLACK); // x, y, size, colour
	// ZOOM IN
	DrawRectangle(10, 600, 100, 100, GRAY); // x, y, length, height, colour
	DrawText("ZOOM IN", 15, 610, 20, BLACK); // x, y, size, colour
	// ZOOM OUT
	DrawRectangle(230, 600, 100, 100, GRAY); // x, y, length, height, colour
	DrawText("ZOOM OUT", 231, 610, 20, BLACK); // x, y, size, colour
}

void Camera::DrawCameraRecording() {
	//// RECORD
	DrawRectangle(10, 820, 150, 100, GRAY); // x, y, length, height, colour
	DrawText("RECORD", 15, 830, 20, BLACK); // x, y, size, colour
	// code to record
}

void Camera::DrawFullScreen() {
	// FULL SCREEN
	DrawRectangle(175, 820, 150, 100, GRAY); // x, y, length, height, colour
	DrawText("FULL SCREEN", 180, 830, 20, BLACK); // x, y, size, colour
	// code to full screen
}

void Camera::SaveRecording() {
	// code for saving
}
Camera::~Camera() {}
