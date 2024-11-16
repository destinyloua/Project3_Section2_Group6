#define _CRT_SECURE_NO_WARNINGS
// Camera.h implementation
#include "Camera.h"
#include "raylib.h"
#include <iostream>

CameraView::CameraView() {} 

// still need code for inserting image somehow with raylib

// Camera view on the screen
void CameraView::DrawCameraPanel() {
	DrawRectangle(10, 90, 800, 500, DARKGRAY); // x, y, length, height, colour
	DrawText("Camera View", 20, 100, 40, WHITE); // x, y, size, colour
}

// Camera Controls
void CameraView::DrawCameraControlUp() {
	// UP
	DrawRectangle(120, 600, 100, 100, GRAY); // x, y, length, height, colour
	DrawText("UP", 125, 610, 20, BLACK); // x, y, size, colour
	// code for making the image go up
}

void CameraView::DrawCameraControlDown() {
	// DOWN
	DrawRectangle(120, 710, 100, 100, GRAY); // x, y, length, height, colour
	DrawText("DOWN", 125, 720, 20, BLACK); // x, y, size, colour
	// code for making the image go down
}

void CameraView::DrawCameraControlLeft() {
	// LEFT
	DrawRectangle(10, 710, 100, 100, GRAY); // x, y, length, height, colour
	DrawText("LEFT", 15, 720, 20, BLACK); // x, y, size, colour
	// code for making the image go left

}

void CameraView::DrawCameraControlRight() {
	// RIGHT
	DrawRectangle(230, 710, 100, 100, GRAY); // x, y, length, height, colour
	DrawText("RIGHT", 235, 720, 20, BLACK); // x, y, size, colour
	// code for making the image go right

}

void CameraView::DrawCameraControlZoomIn() {
	// ZOOM IN
	DrawRectangle(10, 600, 100, 100, GRAY); // x, y, length, height, colour
	DrawText("ZOOM IN", 15, 610, 20, BLACK); // x, y, size, colour
	// code for zooming in
}

void CameraView::DrawCameraControlZoomOut() {
	// ZOOM OUT
	DrawRectangle(230, 600, 100, 100, GRAY); // x, y, length, height, colour
	DrawText("ZOOM OUT", 231, 610, 20, BLACK); // x, y, size, colour
	// code for zooming out
}


void CameraView::DrawCameraRecording() {
	//// RECORD
	DrawRectangle(10, 820, 150, 100, GRAY); // x, y, length, height, colour
	DrawText("RECORD", 15, 830, 20, BLACK); // x, y, size, colour
	// code to record
}

void CameraView::DrawFullScreen() {
	// FULL SCREEN
	DrawRectangle(175, 820, 150, 100, GRAY); // x, y, length, height, colour
	DrawText("FULL SCREEN", 180, 830, 20, BLACK); // x, y, size, colour
	// code to full screen
}

//void CameraView::SaveRecording() {
//	// code for saving
//}

CameraView::~CameraView() {}
