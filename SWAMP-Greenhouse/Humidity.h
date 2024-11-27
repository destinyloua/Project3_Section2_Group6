
#pragma once
// Humidity header file
#include <string>
#include <vector>
#include <chrono>
#include "raylib.h"

class Humidity {
private:
    double humidityLevel;
    std::vector<std::string> logEntries;
    float scrollOffset;
    const float scrollSpeed;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastUpdateTime;
public:
    Humidity();
    double getHumidityLevel();
    void setHumidityLevel(double level);
    void generateRandomHumidity();
    void logHumidityToFile();
    std::string getCurrentDate();
    std::string getCurrentTime();
    void drawHumidityLogTable();
    void handleHumidityPanelClick();
    void update();
    void displayWarning();
    bool showTable;
    std::string alertHumidityChange();
    void drawHumidityPanel();
    std::vector<std::string> readHumidityLog();
    ~Humidity();

};
