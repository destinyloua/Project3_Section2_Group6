#define _CRT_SECURE_NO_WARNINGS
// Camera.h implementation
// Liam
#include "Camera.h"
#include "raylib.h"
#include <iostream>

// Constructor for CameraView class
CameraView::CameraView() : currentTexture{} {
    // Initialize button rectangles with positions and sizes
    upButton = { 95, 600, 75, 75 };
    downButton = { 95, 685, 75, 75 }; // x, y, width, height
    leftButton = { 10, 685, 75, 75 };
    rightButton = { 180, 685, 75, 75 };
    zoomInButton = { 10, 600, 75, 75 };
    zoomOutButton = { 180, 600, 75, 75 };


    // Load textures for directional buttons (icons)
    upTexture = LoadTexture("Up.png");
    downTexture = LoadTexture("Down.png");
    leftTexture = LoadTexture("Left.png");
    rightTexture = LoadTexture("Right.png");
    zoomInTexture = LoadTexture("ZoomIn.png");
    zoomOutTexture = LoadTexture("ZoomOut.png");
}

// Get the color of the button based on its state
Color CameraView::GetButtonColor(Rectangle button) {
    return (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), button)) ? LIGHTGRAY : BLACK;
}

// Handle input for buttons and load corresponding textures
void CameraView::HandleInput() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, upButton)) {
            LoadTextureFromPath("Greenhouse.png"); // Load image for UP button
        }
        if (CheckCollisionPointRec(mousePoint, downButton)) {
            LoadTextureFromPath("GreenDown.png"); // Load image for DOWN button
        }
        if (CheckCollisionPointRec(mousePoint, leftButton)) {
            LoadTextureFromPath("GreenLeft.png"); // Load image for LEFT button
        }
        if (CheckCollisionPointRec(mousePoint, rightButton)) {
            LoadTextureFromPath("Greenright.png"); // Load image for RIGHT button
        }
        if (CheckCollisionPointRec(mousePoint, zoomInButton)) {
            LoadTextureFromPath("GreenZoomIn.png"); // Load image for ZOOM IN button
        }
        if (CheckCollisionPointRec(mousePoint, zoomOutButton)) {
            LoadTextureFromPath("GreenZoomOut.png"); // Load image for ZOOM OUT button
        }
    }
}

// Update the state of the camera view
void CameraView::CameraUpdate() {
    HandleInput();
}

// Load a texture from a file path and resize it to fit the camera panel
void CameraView::LoadTextureFromPath(const char* imagePath) {
    if (currentTexture.id != 0) {
        UnloadTexture(currentTexture); // Unload previous texture if any
    }
    Image img = LoadImage(imagePath);
    if (img.data == nullptr) {
        std::cerr << "Failed to load image: " << imagePath << std::endl;
        return;
    }

    // Resize the image to fit the camera panel size (800x500)
    ImageResize(&img, 800, 500);

    currentTexture = LoadTextureFromImage(img);
    UnloadImage(img);
}

// Draw the camera view and controls
void CameraView::CameraDraw() {
    // Draw the camera panel
    DrawCameraPanel();

    // Draw the current image within the camera panel area
    if (currentTexture.id != 0) {
        DrawTexture(currentTexture, 10, 90, WHITE); // Position image at the top-left corner of the panel
    }
                                                    // texture, x, y, tint
    // Draw buttons with their images
    DrawControls();
}

// Draw the camera panel rectangle and label
void CameraView::DrawCameraPanel() {
    DrawRectangle(10, 90, 800, 500, DARKGRAY);
    DrawText("Camera View", 20, 100, 40, WHITE);
}

// Draw the controls with button images
void CameraView::DrawControls() {
    // Calculate the scale factor to fit the icons within the buttons
    float scale = 0.15f; 

    // Draw the up button icon scaled
    Vector2 upButtonPosition = { upButton.x, upButton.y };
    DrawTextureEx(upTexture, upButtonPosition, 0.0f, scale, WHITE); // Draw textures with extended parameters

    // Draw the down button icon scaled
    Vector2 downButtonPosition = { downButton.x, downButton.y };
    DrawTextureEx(downTexture, downButtonPosition, 0.0f, scale, WHITE); // texture, position (x, y), rotation, scale, tint

    // Draw the left button icon scaled
    Vector2 leftButtonPosition = { leftButton.x, leftButton.y };
    DrawTextureEx(leftTexture, leftButtonPosition, 0.0f, scale, WHITE);

    // Draw the right button icon scaled
    Vector2 rightButtonPosition = { rightButton.x, rightButton.y };
    DrawTextureEx(rightTexture, rightButtonPosition, 0.0f, scale, WHITE);

    // Draw the zoom in button icon scaled
    Vector2 zoomInButtonPosition = { zoomInButton.x, zoomInButton.y };
    DrawTextureEx(zoomInTexture, zoomInButtonPosition, 0.0f, scale, WHITE);

    // Draw the zoom out button icon scaled
    Vector2 zoomOutButtonPosition = { zoomOutButton.x, zoomOutButton.y };
    DrawTextureEx(zoomOutTexture, zoomOutButtonPosition, 0.0f, scale, WHITE);

    // Draw the button outlines for visual feedback
    DrawRectangleLines(upButton.x, upButton.y, upButton.width, upButton.height, GetButtonColor(upButton));
    DrawRectangleLines(downButton.x, downButton.y, downButton.width, downButton.height, GetButtonColor(downButton));
    DrawRectangleLines(leftButton.x, leftButton.y, leftButton.width, leftButton.height, GetButtonColor(leftButton));
    DrawRectangleLines(rightButton.x, rightButton.y, rightButton.width, rightButton.height, GetButtonColor(rightButton));
    DrawRectangleLines(zoomInButton.x, zoomInButton.y, zoomInButton.width, zoomInButton.height, GetButtonColor(zoomInButton));
    DrawRectangleLines(zoomOutButton.x, zoomOutButton.y, zoomOutButton.width, zoomOutButton.height, GetButtonColor(zoomOutButton));
}

// Destructor for CameraView class
CameraView::~CameraView() {
    if (currentTexture.id != 0) {
        UnloadTexture(currentTexture); // Unload current texture to free memory
    }
    UnloadTexture(upTexture);
    UnloadTexture(downTexture);
    UnloadTexture(leftTexture);
    UnloadTexture(rightTexture);
    UnloadTexture(zoomInTexture);
    UnloadTexture(zoomOutTexture);
}
