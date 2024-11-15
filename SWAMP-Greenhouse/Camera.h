#pragma once
// Camera header file
#include <string>
#include <list>

class Camera {
protected:
	void DrawCameraPanel();
	void DrawCameraControls();
	void DrawCameraRecording();
	void DrawFullScreen();

public:
	Camera();
	void UpdateCameraDrawing();
	~Camera();
};
