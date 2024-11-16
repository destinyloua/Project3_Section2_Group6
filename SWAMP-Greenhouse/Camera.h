#pragma once
// Camera header file
#pragma once
#include "raylib.h"

class CameraView {
private:
    Texture2D currentTexture; // Current texture to be displayed
    Texture2D upTexture, downTexture, leftTexture, rightTexture, zoomInTexture, zoomOutTexture; // Textures for directional buttons
    Rectangle upButton, downButton, leftButton, rightButton, zoomInButton, zoomOutButton;
    Color GetButtonColor(Rectangle button);
    void DrawControls();
    void DrawCameraPanel();

public:
    CameraView();
    void HandleInput();
    void CameraUpdate();
    void CameraDraw();
    void LoadTextureFromPath(const char* imagePath);
    ~CameraView();
};


