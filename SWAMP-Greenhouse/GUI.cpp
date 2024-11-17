#include "GUI.h"
#include "raylib.h"
#include <iostream>
using namespace std;

InputField::InputField()
{
    this->inputText[0] = '\0';
    this->isActive = false;
    this->textLength = 0;
    this->hasDecimalPoint = false;
}

void InputField::Clear()
{
    this->inputText[0] = '\0';
    this->isActive = false;
    this->textLength = 0;
    this->hasDecimalPoint = false;
}

GUI::GUI(){
    this->userId = 0000;
    this->page = LoginPage;
}

void GUI::SetUser(int userId) {
    this->userId = userId;
}

void GUI::Login() {
    // Rectangle for input field
    Rectangle inputBox = { 500, 475, 500, 50 };
    InputField inputField;
    bool uservalidation = true;
    int inputUserId;
    while (page == LoginPage) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Welcome to SWAMP! Please enter User ID to Login:", 231, 368, 40, DARKGREEN);

        // Draw the input field
        InputFieldDraw(inputBox, inputField, LIGHTGRAY, DARKGRAY, BLACK, 20, MAX_CHARS);

        // Draw login button
        Rectangle loginButton = { 650, 565, 200, 70 };
        DrawRectangleRec(loginButton, DARKGRAY);
        DrawText("Login", 701, 574, 40, WHITE);

        // Handle login button click
        if (CheckCollisionPointRec(GetMousePosition(), loginButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            uservalidation = true;
            if (inputField.textLength > 0 && userId == userId) {
                inputUserId = atoi(inputField.inputText); // Convert text to integer
                if (inputUserId == userId) {
                    cout << "User logged in with ID: " << userId << std::endl;
                    page = MainPage;
                }
                else {
                    uservalidation = false;
                }
            }
            else{
                uservalidation = false;
            }
        }

        if (uservalidation == false) {
            DrawText("Invalid User ID!", 500, 525, 25, RED);
        }

        EndDrawing();
    }
}

void GUI::InputFieldDraw(Rectangle rec, InputField& inputField, Color bColor, Color lColor, Color tColor, int fontSize, int maxChars) {
    DrawRectangleRec(rec, bColor); // Background color
    DrawRectangleLinesEx(rec, 2, lColor); // Border color

    // Handle focus on click
    if (CheckCollisionPointRec(GetMousePosition(), rec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        inputField.isActive = true;
    }
    else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        inputField.isActive = false;
    }

    if (inputField.isActive) {
        // Handle text input
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 32 && key <= 126) && inputField.textLength < maxChars) {
                if (key == '.' && inputField.hasDecimalPoint) {
                    key = GetCharPressed(); // Ignore additional decimal points
                    continue;
                }
                inputField.inputText[inputField.textLength] = (char)key;
                inputField.textLength++;
                inputField.inputText[inputField.textLength] = '\0';
            }
            key = GetCharPressed();
        }

        // Handle backspace
        if (IsKeyPressed(KEY_BACKSPACE) && inputField.textLength > 0) {
            if (inputField.inputText[inputField.textLength - 1] == '.') {
                inputField.hasDecimalPoint = false; // Remove the decimal point
            }
            inputField.textLength--;
            inputField.inputText[inputField.textLength] = '\0';
        }
    }

    // Display the current text
    DrawText(inputField.inputText, rec.x + 5, rec.y + 15, fontSize, tColor);
}

void GUI::DrawPanels() {
    // Camera view
    DrawRectangle(10, 90, 800, 500, DARKGRAY); // x, y, length, height, colour
    DrawText("Camera View", 20, 100, 40, WHITE); // x, y, size, colour

    // Lights
    DrawRectangle(850, 90, 600, 100, YELLOW); // x, y, length, height, colour
    DrawText("Lights", 860, 100, 40, BLACK); // x, y, size, colour

    // Temp
    DrawRectangle(850, 210, 600, 100, BLUE); // x, y, length, height, colour
    DrawText("Temperature", 860, 220, 40, BLACK); // x, y, size, colour

    // CO2
    DrawRectangle(850, 330, 600, 100, PINK); // x, y, length, height, colour
    DrawText("CO2", 860, 340, 40, BLACK); // x, y, size, colour

    // Humidity
    DrawRectangle(850, 450, 600, 100, ORANGE); // x, y, length, height, colour
    DrawText("Humidity", 860, 460, 40, BLACK); // x, y, size, colour

    // Soil Moisture
    DrawRectangle(850, 570, 600, 100, GREEN); // x, y, length, height, colour
    DrawText("Soil Moisture", 860, 580, 40, BLACK); // x, y, size, colour

    // Energy
    DrawRectangle(850, 690, 600, 100, PURPLE); // x, y, length, height, colour
    DrawText("Energy Management", 860, 700, 40, BLACK); // x, y, size, colour

    // Notification Panel
    DrawRectangle(10, 750, 800, 200, WHITE); // x, y, length, height, colour
    DrawText("Notifications", 15, 760, 20, BLACK); // x, y, size, colour
}

void GUI::DrawCameraControls() {
    // Camera Controls
    // UP
    DrawRectangle(10, 600, 100, 100, GRAY); // x, y, length, height, colour
    DrawText("Up", 15, 620, 20, BLACK); // x, y, size, colour
    // DOWN
    DrawRectangle(120, 600, 100, 100, GRAY); // x, y, length, height, colour
    DrawText("Down", 125, 620, 20, BLACK); // x, y, size, colour
    // LEFT
    DrawRectangle(230, 600, 100, 100, GRAY); // x, y, length, height, colour
    DrawText("Left", 235, 620, 20, BLACK); // x, y, size, colour
    // RIGHT
    DrawRectangle(340, 600, 100, 100, GRAY); // x, y, length, height, colour
    DrawText("Right", 345, 620, 20, BLACK); // x, y, size, colour
    // ZOOM IN
    DrawRectangle(450, 600, 150, 100, GRAY); // x, y, length, height, colour
    DrawText("Zoom In", 455, 620, 20, BLACK); // x, y, size, colour
    // ZOOM OUT
    DrawRectangle(620, 600, 150, 100, GRAY); // x, y, length, height, colour
    DrawText("Zoom Out", 625, 620, 20, BLACK); // x, y, size, colour
}

void GUI::UpdateDrawing() {
    while (page == MainPage) {
        BeginDrawing();
        // Background
        Color customBackground = { 204, 204, 204, 255 }; // red, green, blue, opacity
        ClearBackground(customBackground);
        // SWAMP
        DrawText("Sustainable Water Application for Monitoring Plants", 10, 10, 56, DARKGREEN); // x, y, size, colour
        // Panels and camera controls
        DrawPanels();
        DrawCameraControls();

        EndDrawing();
    }
}

GUI::~GUI() {}