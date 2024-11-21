#pragma once
// Camera header file
// Liam
#include "raylib.h"

class CameraView {
private:
    Texture2D currentTexture;
    Texture2D upTexture, downTexture, leftTexture, rightTexture, zoomInTexture, zoomOutTexture;
    Rectangle upButton, downButton, leftButton, rightButton, zoomInButton, zoomOutButton, recordButton, fullscreenButton, exitFullscreenButton;
    bool isRecording; // Flag to indicate recording state
    bool isFullscreen; // Flag to indicate full screen state
    Color GetButtonColor(Rectangle button);
    void DrawControls();
    void DrawCameraPanel();
    void ResizeToPanel();
    void RestoreOriginalSize();
public:
    CameraView();
    void HandleInput();
    void CameraUpdate();
    void CameraDraw();
    void LoadTextureFromPath(const char* imagePath);
    ~CameraView();
};
