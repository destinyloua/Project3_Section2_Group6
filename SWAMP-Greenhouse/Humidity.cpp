#define _CRT_SECURE_NO_WARNINGS
// Humidity.h implementation
// Liam
#include "Humidity.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h> // for srand() and rand()
#include <time.h> // for time()
#include <thread> // for sleep
#include <chrono> // date and time
#include <iomanip> // for put time
#include <string> 

// Constructor to initialize the Humidity class
Humidity::Humidity()
    : humidityLevel(0.0), showTable(false), scrollOffset(0), scrollSpeed(20.0f) {
    srand((unsigned int)time(0)); // initialize random number generation
    lastUpdateTime = std::chrono::high_resolution_clock::now();
    generateRandomHumidity();
}

// Update method to check the elapsed time and generate new humidity value if necessary
void Humidity::update() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = currentTime - lastUpdateTime;

    if (elapsed.count() >= 15.0) {
        generateRandomHumidity();
        lastUpdateTime = currentTime;
    }
}

// Generate a random humidity value and log it
void Humidity::generateRandomHumidity() {
    bool isOutOfRange = (rand() % 100) < 25; // 25% chance of being out of range

    if (isOutOfRange) {
        if (rand() % 2 == 0) {
            humidityLevel = 49.0 * rand() / RAND_MAX; // Generate below 50%
        }
        else {
            humidityLevel = 80.0 + 20.0 * rand() / RAND_MAX; // Generate above 80%
        }
    }
    else {
        humidityLevel = 50.0 + 30.0 * rand() / RAND_MAX; // Generate within 50% to 80%
    }

    // Format humidity level to two decimal places
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << humidityLevel;
    stream >> humidityLevel;

    logHumidityToFile(); // log humidity to file
}

// Alert if the humidity level is out of range
std::string Humidity::alertHumidityChange() {
    if (humidityLevel < 50.0) {
        return "Alert: Humidity level out of range! Too low!";
    }
    else if (humidityLevel > 80.0) {
        return "Alert: Humidity level out of range! Too high!";
    }
    return "Humidity level within range.";
}

void Humidity::displayWarning() {
    if (humidityLevel < 50.0) {
        DrawText("Alert: Humidity level TOO LOW!", 310, 830, 20, RED);
        DrawText("PLANT HEALTH HAZARD!", 310, 850, 20, RED);
    }
    else if (humidityLevel > 80.0) {
        DrawText("Alert: Humidity level TOO HIGH", 310, 830, 20, RED);
        DrawText("PLANT HEALTH HAZARD!", 310, 850, 20, RED);
    }
}

// Get the current date as a string
std::string Humidity::getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm;
    localtime_s(&now_tm, &now_c);

    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%Y-%m-%d");
    return oss.str();
}

// Get the current time as a string
std::string Humidity::getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm;
    localtime_s(&now_tm, &now_c);

    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%H:%M:%S");
    return oss.str();
}

// Log the humidity data to a file
void Humidity::logHumidityToFile() {
    std::ofstream fout("HumidityLog.txt", std::ios::app);
    if (!fout) {
        std::cerr << "Failed to open HumidityLog.txt" << std::endl;
        return;
    }

    std::string currentTime = getCurrentTime();
    std::string currentDate = getCurrentDate();
    std::string alertStatus = alertHumidityChange();

    fout << "Date: " << currentDate << " | Time: " << currentTime << " | Humidity Level: " << humidityLevel << " | Status: " << alertStatus << "\n";
}

// Read the humidity log from a file and return it as a vector of strings
std::vector<std::string> Humidity::readHumidityLog() {
    std::vector<std::string> logEntries;
    std::ifstream fin("HumidityLog.txt");
    if (!fin) {
        std::cerr << "Failed to open HumidityLog.txt" << std::endl;
        return logEntries;
    }

    std::string line;
    while (std::getline(fin, line)) {
        logEntries.push_back(line);
    }

    return logEntries;
}

// Draw the humidity panel with current humidity level
void Humidity::drawHumidityPanel() {
    Color panelColor = ORANGE; // Default panel color
    if (humidityLevel < 50.0 || humidityLevel > 80.0) {
        panelColor = RED; // Out of range color
    }

    Vector2 mousePosition = GetMousePosition();
    Rectangle panelRect = { 850, 450, 600, 100 };

    if (CheckCollisionPointRec(mousePosition, panelRect)) {
        panelColor = { 255, 140, 0, 255 }; // Use RGB values for dark orange when hovered

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            handleHumidityPanelClick(); // Handle click
        }
    }

    DrawRectangleRec(panelRect, panelColor);
    DrawText("Humidity", 860, 460, 40, BLACK);

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << humidityLevel << "%";
    std::string humidityText = oss.str();
    DrawText(humidityText.c_str(), 860, 510, 30, BLACK);

    if (showTable) {
        drawHumidityLogTable(); // Draw the log table if flag is true
    }
}

// Handle click event for the humidity panel
void Humidity::handleHumidityPanelClick() {
    logEntries = readHumidityLog();
    showTable = !showTable;
    scrollOffset = 0;
}

// Draw the humidity log table
void Humidity::drawHumidityLogTable() {
    // Define the height of each line
    int lineHeight = 30;
    int headerHeight = 200; 

    // Calculate the total height of the content
    int contentHeight = headerHeight + logEntries.size() * lineHeight;
    int visibleHeight = 1000;
    float maxScrollOffset = contentHeight > visibleHeight ? contentHeight - visibleHeight : 0;

    // Update the scroll offset based on mouse wheel input
    scrollOffset -= GetMouseWheelMove() * scrollSpeed;

    // Clamp the scroll offset to the valid range
    if (scrollOffset < 0) {
        scrollOffset = 0;
    }
    else if (scrollOffset > maxScrollOffset) {
        scrollOffset = maxScrollOffset;
    }

    // Draw the background
    DrawRectangle(0, 0, 1500, visibleHeight, LIGHTGRAY);

    // Starting position for the entire content (header + log entries)
    int startX = 100;
    int startY = -scrollOffset;

    // Draw the header at different positions
    DrawText("Humidity Log:", 100, startY + 50, 40, BLACK);
    DrawText("Minimum: 50%, Maximum: 80%, Average: 60-70%", 100, startY + 100, 40, BLACK);

    // Starting position for the log entries (below the header)
    int logStartX = 100; 
    int logStartY = startY + headerHeight; 
    for (size_t i = 0; i < logEntries.size(); i++) {
        DrawText(logEntries[i].c_str(), logStartX, logStartY + (i * lineHeight), 25, BLACK);
    }

    // Draw the back button
    Rectangle backButton = { 1500 - 110, 10, 100, 40 };
    DrawRectangleRec(backButton, DARKGRAY);
    DrawText("Back", backButton.x + 10, backButton.y + 10, 25, RAYWHITE);

    // Check for back button click
    Vector2 mousePosition = GetMousePosition();
    if (CheckCollisionPointRec(mousePosition, backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        showTable = false;
    }
}

// Added for testing
double Humidity::getHumidityLevel() {
    return humidityLevel;
}

void Humidity::setHumidityLevel(double level) {
    humidityLevel = level;
}


Humidity::~Humidity() {}
