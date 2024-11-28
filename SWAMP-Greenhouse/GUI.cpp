#define _CRT_SECURE_NO_WARNINGS

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

GUI::GUI() : showTable(false), scrollOffset(0), scrollSpeed(20.0f) {
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
    while (page == LoginPage && !WindowShouldClose()) {
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
            else {
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

void GUI::DrawPanels(CO2& c, Energy& e, SoilMoisture& s, Humidity& h) {
    // Camera view
    DrawRectangle(10, 90, 800, 500, DARKGRAY); // x, y, length, height, colour
    DrawText("Camera View", 20, 100, 40, WHITE); // x, y, size, colour

    // Lights
    DrawRectangle(850, 90, 600, 100, YELLOW); // x, y, length, height, colour
    DrawText("Lights", 860, 100, 40, BLACK); // x, y, size, colour

    if (CheckButtonClick(850, 90, 600, 100)) {
        page = LightsPage; // Go to lights screen
    }

    // Temp
    DrawRectangle(850, 210, 600, 100, BLUE); // x, y, length, height, colour
    DrawText("Temperature", 860, 220, 40, BLACK); // x, y, size, colour

    if (CheckButtonClick(850, 210, 600, 100)) {
        page = TemperaturePage; // Go to Temp screen
    }
    // CO2
    Rectangle co2Button = { 850, 330, 600, 100 };
    c.drawCO2Button(co2Button);
    //DrawRectangle(850, 330, 600, 100, PINK); // x, y, length, height, colour
    //DrawText("CO2", 860, 340, 40, BLACK); // x, y, size, colour

    // Humidity
    h.drawHumidityPanel();

    // Soil Moisture
    Rectangle soilButton = { 850,570,600,100 };
    DrawRectangleRec(soilButton, BROWN);
    Rectangle irrigationSwitch = { 1128,580,300,40 };
    if (s.GetIrrigation()) {
        DrawRectangleRec(irrigationSwitch, GREEN);
    }
    else {
        DrawRectangleRec(irrigationSwitch, RED);
    }
    DrawText("Irrigation System", 1150, 590, 30, BLACK);
    DrawText("Soil Moisture", 860, 580, 40, BLACK); // x, y, size, colour
    //if (s.GetIrrigation()) {
    //    DrawText("Irrigation On", 1142, 580, 40, GREEN); // x, y, size, colour
    //}
    //else {
    //    DrawText("Irrigation Off", 1142, 580, 40, RED); // x, y, size, colour
    //}
    if (s.GetData()>s.GetThreshold()) {
        DrawText(TextFormat("Current: %.2f%%", s.GetData()), 860, 623, 30, BLACK); // x, y, size, colour
    }
    else
    {
        DrawText(TextFormat("Current: %.2f%%", s.GetData()), 860, 623, 30, RED); // x, y, size, colour
    }
    if (CheckCollisionPointRec(GetMousePosition(), irrigationSwitch) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        s.SetIrrigationStatus();
    }
    Rectangle upButton = { 1366 ,628,30,30 };
    Rectangle downButton = { 1406 ,628,30,30 };
    DrawRectangleRec(upButton, WHITE);
    DrawRectangleRec(downButton, WHITE);
    DrawText("U", 1371, 630, 30, BLACK);
    DrawText("D", 1411, 630, 30, BLACK);
    if (CheckCollisionPointRec(GetMousePosition(), upButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && s.GetThreshold() <100) {
        s.IncreaseThreshold();
    }
    if (CheckCollisionPointRec(GetMousePosition(), downButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && s.GetThreshold()>0) {
        s.DecreaseThreshold();
    }

    DrawText(TextFormat("Thrhd: %.2f%%", s.GetThreshold()), 1128, 623, 30, BLACK);

    // Energy
    Rectangle energyButton = { 850, 690, 600, 100 };
    e.drawEnergyButton(energyButton);
    //DrawRectangle(850, 690, 600, 100, PURPLE); // x, y, length, height, colour
    //DrawText("Energy Management", 860, 700, 40, BLACK); // x, y, size, colour

    // Notification
    DrawRectangle(300, 650, 500, 300, WHITE); // x, y, length, height, colour
    DrawText("Notifications", 310, 655, 40, BLACK); // x, y, size, colour
    if (s.GetData() < s.GetThreshold()) {
        DrawText(TextFormat("SOIL MOISTURE: Below threshold, irrigation on"), 310, 712, 20, RED); // x, y, size, colour
    }
    // for co2 notifications
    if (c.isDanger) {
        c.displayWarning();
    }

    // for energy notification
    if (e.tooMuchPower) {
        e.displayWarning();
    }

    h.displayWarning();
    // User info
    DrawRectangle(10, 950, 200, 100, WHITE); // x, y, length, height, colour
    DrawText("User: 0000", 15, 955, 20, DARKBLUE); // x, y, size, colour

    Rectangle quitButton = { 850,838,600,100 };
    DrawRectangleRec(quitButton, RED); // x, y, length, height, colour
    DrawText("Quit", 1103, 861, 40, BLACK); // x, y, size, colour
    if (CheckCollisionPointRec(GetMousePosition(), quitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        page = Quit;
    }

}

void GUI::UpdateDrawing(CO2 &c, Energy& e, SoilMoisture& s, Humidity& h) {
    // Background
    Color customBackground = { 204, 204, 204, 255 }; // red, green, blue, opacity
    ClearBackground(customBackground);
    // SWAMP
    DrawText("Sustainable Water Application for Monitoring Plants", 10, 10, 56, DARKGREEN); // x, y, size, colour
    // Panels and camera controls
    DrawPanels(c, e, s, h);
    h.update();
}

bool GUI::CheckButtonClick(int x, int y, int width, int height) {
    Vector2 mousePos = GetMousePosition(); // Get the mouse position
    return (mousePos.x >= x && mousePos.x <= x + width && mousePos.y >= y && mousePos.y <= y + height) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void GUI::DrawLightsScreen(Lights& l) {

    static int simulatedTime = 0;
    static float timeAccumulator = 0.0f;

    Color tempColorSwitch;
    string tempstring;

    if (page == LightsPage) {

        l.displayLightStatus();

        // Timer logic: Simulate time increment (1 simulated hour every 5 seconds)
        timeAccumulator += GetFrameTime();
        if (timeAccumulator >= 5.0f) {
            simulatedTime = (simulatedTime + 1) % 24;
            timeAccumulator = 0.0f;
        }

        // Schedule logic: Turn lights on/off based on start/stop time
        if (l.startTime >= simulatedTime && l.stopTime > simulatedTime  ) {
            l.setLightSwitch(true);
        }

        // Display simulated time
        DrawText(("Simulated Time: " + std::to_string(simulatedTime) + ":00").c_str(), 600, 100, 20, BLACK);

        if (l.isLightOn) {
            tempColorSwitch = GREEN;
            tempstring = "light is on";
        }
        else {
            tempColorSwitch = RED;
            tempstring = "light is off";
        }

        DrawText("Lights Control", 400, 50, 40, DARKBLUE);

        // master light switch
        DrawRectangle(350, 150, 200, 50, tempColorSwitch);
        DrawText(tempstring.c_str(), 400, 160, 20, BLACK);

        // slider info
        int sliderX = 350;
        int sliderY = 250;
        int sliderWidth = 200;
        int sliderHeight = 20;

        Color sliderBarColor;
        if (l.actualLightLevel < l.minLightLevel || l.actualLightLevel > l.maxLightLevel) {
            sliderBarColor = RED;
        }
        else if (l.actualLightLevel >= l.minLightLevel + UNSAFE_BUFFER_LIGHTS && l.actualLightLevel <= l.maxLightLevel - UNSAFE_BUFFER_LIGHTS) {
            sliderBarColor = GREEN;
        }
        else {
            sliderBarColor = YELLOW;
        }

        // Draw the slider 
        DrawRectangle(sliderX, sliderY, sliderWidth, sliderHeight, LIGHTGRAY);

        // Calculate the slider's position based on the current light level 
        int sliderPos = sliderX + (l.getActualLightLevel() * sliderWidth / 100);  // This keeps it within 0-100

        // Draw the filled part of the slider
        DrawRectangle(sliderX, sliderY, sliderPos - sliderX, sliderHeight, sliderBarColor);

        // Check for mouse input to move the slider
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            int mouseX = GetMouseX();

            // Calculate the new slider value based on mouse position
            if (mouseX >= sliderX && mouseX <= sliderX + sliderWidth) {
                int newSliderValue = (mouseX - sliderX) * 100 / sliderWidth;

                // keep slider between minLightLevel and maxLightLevel
                if (newSliderValue < l.minLightLevel) {
                    newSliderValue = l.minLightLevel;
                }
                else if (newSliderValue > l.maxLightLevel) {
                    newSliderValue = l.maxLightLevel;
                }

                l.setActualLightLevel(newSliderValue);
            }
        }
        // Display the light level 
        tempstring = "Light Level: " + to_string(l.getActualLightLevel()) + "%";
        DrawText(tempstring.c_str(), 360, 280, 20, BLACK);

        // schduel info
        int scheduleX = 600;
        int scheduleY = 140;

        DrawText("Schedule", scheduleX, scheduleY, 20, DARKBLUE);

        // Drawing the "Start Time" label and input
        DrawText("Start Time:", scheduleX, scheduleY + 40, 20, BLACK);
        DrawText(("Start: " + to_string(l.startTime)).c_str(), scheduleX, scheduleY + 70, 20, BLACK);

        // Drawing the "Stop Time" label and input
        DrawText("Stop Time:", scheduleX, scheduleY + 120, 20, BLACK);
        DrawText(("Stop: " + to_string(l.stopTime)).c_str(), scheduleX, scheduleY + 150, 20, BLACK);

        // Button to set the schedule
        DrawRectangle(scheduleX, scheduleY + 180, 200, 40, LIGHTGRAY);
        DrawText("Set Schedule", scheduleX + 30, scheduleY + 190, 20, BLACK);

        // Button to turn off the schedule 
        DrawRectangle(scheduleX, scheduleY + 230, 200, 40, LIGHTGRAY);
        DrawText("Turn Off Schedule", scheduleX, scheduleY + 240, 20, BLACK);

        // Check for "Set Schedule" button click
        if (CheckButtonClick(scheduleX, scheduleY + 180, 200, 40)) {
            l.setScheduel(l.startTime, l.stopTime);
        }

        // Check for "Turn Off Schedule" button click
        if (CheckButtonClick(scheduleX, scheduleY + 230, 200, 40)) {
            l.setScheduel(0, 0);
        }

        // "+" Button for Start Time
        DrawRectangle(scheduleX + 200, scheduleY + 40, 30, 30, LIGHTGRAY);
        DrawText("+", scheduleX + 210, scheduleY + 42, 20, BLACK);
        if (CheckButtonClick(scheduleX + 200, scheduleY + 40, 30, 30)) {
            if (l.startTime < 23) { // Ensure it doesn't exceed 23
                l.startTime++;
            }
        }

        // "-" Button for Start Time
        DrawRectangle(scheduleX + 240, scheduleY + 40, 30, 30, LIGHTGRAY);
        DrawText("-", scheduleX + 250, scheduleY + 42, 20, BLACK);
        if (CheckButtonClick(scheduleX + 240, scheduleY + 40, 30, 30)) {
            if (l.startTime > 0) { // Ensure it doesn't go below 0
                l.startTime--;
            }
        }

        // "+" Button for Stop Time
        DrawRectangle(scheduleX + 200, scheduleY + 80, 30, 30, LIGHTGRAY);
        DrawText("+", scheduleX + 210, scheduleY + 82, 20, BLACK);
        if (CheckButtonClick(scheduleX + 200, scheduleY + 80, 30, 30)) {
            if (l.stopTime < 23) { // Ensure it doesn't exceed 23
                l.stopTime++;
            }
        }

        // "-" Button for Stop Time
        DrawRectangle(scheduleX + 240, scheduleY + 80, 30, 30, LIGHTGRAY);
        DrawText("-", scheduleX + 250, scheduleY + 82, 20, BLACK);
        if (CheckButtonClick(scheduleX + 240, scheduleY + 80, 30, 30)) {
            if (l.stopTime > 0) { // Ensure it doesn't go below 0
                l.stopTime--;
            }
        }

        // Back to main button
        DrawRectangle(350, 350, 200, 50, LIGHTGRAY);
        DrawText("Back to Main", 380, 360, 20, BLACK);

        // lights on button
        if (CheckButtonClick(350, 150, 200, 50)) {
            // Toggle the light state
            l.setLightSwitch(!l.isLightOn);  // Switch the light state (if it's ON, turn it OFF, and vice versa)
        }
        if (CheckButtonClick(350, 350, 200, 50)) {
            page = MainPage;  // Go back to main screen
        }
    }
}

void GUI::DrawTemperatureScreen(Temperature& t) {

    if (page == TemperaturePage) {

        t.displayTempStatus();

        DrawText("Temperature Control", 500, 50, 40, DARKBLUE);

        Color tempColor;
        string tempText;

        if (t.isTempOn) {
            tempColor = GREEN;
            tempText = "temp is on";
        }
        else {
            tempColor = RED;
            tempText = "temp is off";
        }
        // master switch
        DrawRectangle(600, 100, 200, 50, tempColor);
        DrawText(tempText.c_str(), 640, 110, 20, WHITE);

        if (CheckButtonClick(600, 100, 200, 50)) {
            t.setTempSwitch(!t.isTempOn);
        }

        // Increase temperature button
        DrawRectangle(600, 200, 200, 50, BLACK);
        DrawText("Turn Up Temp", 625, 210, 20, WHITE);

        if (CheckButtonClick(600, 200, 200, 50) && t.isTempOn) {
            int newTemp = t.getActualTemperature() + 1;
            if (newTemp <= t.getMaxThreshold()) {
                t.setActualTemperature(newTemp);
            }
            else {
                printf("Maximum temperature reached.\n");
            }
        }

        // Decrease temperature button
        DrawRectangle(600, 300, 200, 50, BLACK);
        DrawText("Turn Down Temp", 620, 310, 20, WHITE);

        if (CheckButtonClick(600, 300, 200, 50) && t.isTempOn) {
            int newTemp = t.getActualTemperature() - 1;
            if (newTemp >= t.getMinThreshold()) {
                t.setActualTemperature(newTemp);
            }
            else {
                printf("Minimum temperature reached.\n");
            }
        }

        // Switch between Celsius and Fahrenheit button
        DrawRectangle(600, 400, 200, 50, LIGHTGRAY);
        DrawText("Switch Units", 630, 410, 20, BLACK);

        if (CheckButtonClick(600, 400, 200, 50)) {
            if (t.getUnit() == "C") {
                t.convertToFahrenheit();
            }
            else {
                t.convertToCelsius();
            }
        }

        // Back to main button
        DrawRectangle(600, 500, 200, 50, LIGHTGRAY);
        DrawText("Back to Main", 630, 510, 20, BLACK);

        if (CheckButtonClick(600, 500, 200, 50)) {
            page = MainPage;
        }
    }
}
GUI::~GUI() {}