// CSCN72030 - Project III
// Aiden, Destiny, Liam, Tyler
// The SWAMP 

#include <iostream>
#include "raylib.h"
#include "Camera.h"

using namespace std;

int main() {
	// these are just ways for me to test that it works since i don't have the GUI
	const int screenWidth = 1500;
	const int screenHeight = 1000;
	InitWindow(screenWidth, screenHeight, "SWAMP -Camera View");

	CameraView cv;

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		cv.DrawCameraPanel();
		cv.DrawCameraControlUp();
		cv.DrawCameraControlDown();
		cv.DrawCameraControlLeft();
		cv.DrawCameraControlRight();
		cv.DrawCameraControlZoomIn();
		cv.DrawCameraControlZoomOut();
		cv.DrawCameraRecording();
		cv.DrawFullScreen();

		EndDrawing();

	}
	return 0; 
}
