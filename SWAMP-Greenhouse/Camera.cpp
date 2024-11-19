#define _CRT_SECURE_NO_WARNINGS
// Camera.h implementation
// Liam
#include "Camera.h"
#include "raylib.h"
#include <iostream>

CameraView::CameraView() : currentTexture{}, isRecording(false), isFullscreen(false) {
    // Initialize button rectangles
    upButton = { 95, 600, 75, 75 };
    downButton = { 95, 685, 75, 75 }; // x, y, width, height
    leftButton = { 10, 685, 75, 75 };
    rightButton = { 180, 685, 75, 75 };
    zoomInButton = { 10, 600, 75, 75 };
    zoomOutButton = { 180, 600, 75, 75 };
    recordButton = { 10, 770, 115, 75 };
    fullscreenButton = { 140, 770, 115, 75 };
    exitFullscreenButton = { 1380, 950, 110, 40 };
    // Load textures for directional buttons
    upTexture = LoadTexture("Up.png");
    downTexture = LoadTexture("Down.png");
    leftTexture = LoadTexture("Left.png");
    rightTexture = LoadTexture("Right.png");
    zoomInTexture = LoadTexture("ZoomIn.png");
    zoomOutTexture = LoadTexture("ZoomOut.png");
}

Color CameraView::GetButtonColor(Rectangle button) {
    return (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), button)) ? LIGHTGRAY : GRAY;
}

void CameraView::HandleInput() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, upButton)) {
            LoadTextureFromPath("Greenhouse.png");
        }
        if (CheckCollisionPointRec(mousePoint, downButton)) {
            LoadTextureFromPath("GreenDown.png");
        }
        if (CheckCollisionPointRec(mousePoint, leftButton)) {
            LoadTextureFromPath("GreenLeft.png");
        }
        if (CheckCollisionPointRec(mousePoint, rightButton)) {
            LoadTextureFromPath("Greenright.png");
        }
        if (CheckCollisionPointRec(mousePoint, zoomInButton)) {
            LoadTextureFromPath("GreenZoomIn.png");
        }
        if (CheckCollisionPointRec(mousePoint, zoomOutButton)) {
            LoadTextureFromPath("GreenZoomOut.png");
        }
        if (CheckCollisionPointRec(mousePoint, recordButton)) {
            isRecording = !isRecording; // Toggle the recording state
        }
        if (CheckCollisionPointRec(mousePoint, fullscreenButton)) {
            isFullscreen = !isFullscreen; // Toggle the full screen state
            if (isFullscreen) {
                ResizeToPanel(); // Resize the current image to fit the control panel
            }
            else {
                RestoreOriginalSize(); // Resize the image back to its original size
            }
        }
        if (isFullscreen && CheckCollisionPointRec(mousePoint, exitFullscreenButton)) {
            isFullscreen = false;
            RestoreOriginalSize(); // Resize the image back to its original size
        }
    }
}

void CameraView::CameraUpdate() {
    HandleInput();
}

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

void CameraView::CameraDraw() {
    DrawCameraPanel();

    if (currentTexture.id != 0) {
        DrawTexture(currentTexture, 10, 90, WHITE);
    }

    DrawControls();

    if (isRecording) {
        DrawText("Recording...", 30, 100, 40, RED);
    }
}

void CameraView::DrawCameraPanel() {
    DrawRectangle(10, 90, 800, 500, DARKGRAY);
    DrawText("Camera View", 20, 100, 40, WHITE);
}

void CameraView::DrawControls() {
    if (!isFullscreen) {
        // Calculate the scale factor to fit the icons within the buttons
        float scale = 0.15f;

        // Draw the up button icon scaled
        Vector2 upButtonPosition = { upButton.x, upButton.y };
        DrawTextureEx(upTexture, upButtonPosition, 0.0f, scale, WHITE);

        // Draw the down button icon scaled
        Vector2 downButtonPosition = { downButton.x, downButton.y };
        DrawTextureEx(downTexture, downButtonPosition, 0.0f, scale, WHITE);

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

        // Draw the record button rectangle and label
        DrawRectangle(recordButton.x, recordButton.y, recordButton.width, recordButton.height, GRAY);
        DrawText(isRecording ? "STOP" : "RECORD", recordButton.x + 15, recordButton.y + 5, 20, BLACK);

        // Draw the full screen button rectangle and label
        DrawRectangle(fullscreenButton.x, fullscreenButton.y, fullscreenButton.width, fullscreenButton.height, GRAY);
        DrawText("FULL SCREEN", fullscreenButton.x + 5, fullscreenButton.y + 5, 10, BLACK);

        // Draw the button outlines for visual feedback
        DrawRectangleLines(upButton.x, upButton.y, upButton.width, upButton.height, GetButtonColor(upButton));
        DrawRectangleLines(downButton.x, downButton.y, downButton.width, downButton.height, GetButtonColor(downButton));
        DrawRectangleLines(leftButton.x, leftButton.y, leftButton.width, leftButton.height, GetButtonColor(leftButton));
        DrawRectangleLines(rightButton.x, rightButton.y, rightButton.width, rightButton.height, GetButtonColor(rightButton));
        DrawRectangleLines(zoomInButton.x, zoomInButton.y, zoomInButton.width, zoomInButton.height, GetButtonColor(zoomInButton));
        DrawRectangleLines(zoomOutButton.x, zoomOutButton.y, zoomOutButton.width, zoomOutButton.height, GetButtonColor(zoomOutButton));
        DrawRectangleLines(recordButton.x, recordButton.y, recordButton.width, recordButton.height, GetButtonColor(recordButton));
        DrawRectangleLines(fullscreenButton.x, fullscreenButton.y, fullscreenButton.width, fullscreenButton.height, GetButtonColor(fullscreenButton));
    }
    if (isFullscreen) {
        // Draw the exit full screen button at the bottom right corner
        DrawRectangle(exitFullscreenButton.x, exitFullscreenButton.y, exitFullscreenButton.width, exitFullscreenButton.height, DARKGRAY);
        DrawText("EXIT FULLSCREEN", exitFullscreenButton.x + 5, exitFullscreenButton.y + 5, 10, WHITE);
    }
}

void CameraView::ResizeToPanel() {
    if (currentTexture.id != 0) {
        // Define the size of the control panel
        int panelWidth = 1490 - 10; 
        int panelHeight = 990 - 90;

        // Load the current image from the texture
        Image img = LoadImageFromTexture(currentTexture);
        if (img.data == nullptr) {
            std::cerr << "Failed to load image from texture" << std::endl;
            return;
        }

        // Resize the image to fit the control panel
        ImageResize(&img, panelWidth, panelHeight);
        UnloadTexture(currentTexture); // Unload previous texture
        currentTexture = LoadTextureFromImage(img);
        UnloadImage(img);
    }
}

void CameraView::RestoreOriginalSize() {
    if (currentTexture.id != 0) {
        // Get the original size of the image
        int originalWidth = 800;
        int originalHeight = 500;

        // Load the current image from the texture
        Image img = LoadImageFromTexture(currentTexture);
        if (img.data == nullptr) {
            std::cerr << "Failed to load image from texture" << std::endl;
            return;
        }

        // Resize the image to its original size
        ImageResize(&img, originalWidth, originalHeight);
        UnloadTexture(currentTexture); // Unload previous texture
        currentTexture = LoadTextureFromImage(img);
        UnloadImage(img);
    }
}
// Clean up textures
CameraView::~CameraView() {
    if (currentTexture.id != 0) {
        UnloadTexture(currentTexture);
    }
    UnloadTexture(upTexture);
    UnloadTexture(downTexture);
    UnloadTexture(leftTexture);
    UnloadTexture(rightTexture);
    UnloadTexture(zoomInTexture);
    UnloadTexture(zoomOutTexture);
}
