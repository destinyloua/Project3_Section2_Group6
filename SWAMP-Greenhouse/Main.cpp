// CSCN72030 - Project III
// Aiden, Destiny, Liam, Tyler
// The SWAMP 

#include <iostream>
#include "raylib.h"
#include "Camera.h"

int main() {
    const int screenWidth = 1500;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "SWAMP - Camera View");

    CameraView cv;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        cv.CameraUpdate();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        cv.CameraDraw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

