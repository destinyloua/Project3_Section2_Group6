#pragma once
// Camera header file
#include "raylib.h"
#include <string>
#include <list>

class CameraView {
private:

public:
	CameraView();
	void DrawCameraPanel();
	//void DrawCameraControls();
	void DrawCameraControlUp();
	void DrawCameraControlDown();
	void DrawCameraControlLeft();
	void DrawCameraControlRight();
	void DrawCameraControlZoomIn();
	void DrawCameraControlZoomOut();
	void DrawCameraRecording();
	void DrawFullScreen();
	//void UpdateCameraDrawing();
	//void SaveRecording();
	~CameraView();
};

