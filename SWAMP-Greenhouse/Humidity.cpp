#define _CRT_SECURE_NO_WARNINGS
// Humidity.h implementation
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

// constructor
HumiditySensor::HumiditySensor() : humidityLevel(0.0) {
    srand((unsigned int)time(0)); // initialize random number generation
}

// generate random humidity level
void HumiditySensor::generateRandomHumidity() {
    while (true) {
        bool isOutOfRange = (rand() % 100) < 25; // had to add a 25% chance of getting an out off range level just for simulation

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

        logHumidityToFile(); // log humidity to file

        std::this_thread::sleep_for(std::chrono::seconds(15)); // sleep to generate a value every 15 seconds
    }
}

// detects if the humidity is under or over the desired range
std::string HumiditySensor::alertHumidityChange() {
    if (humidityLevel < 50.0) {
        return "Alert: Humidity level out of range! Too low!";
    }
    else if (humidityLevel > 80.0) {
        return "Alert: Humidity level out of range! Too high!";
    }
    return "Humidity level within range.";
}

std::string HumiditySensor::getCurrentDate() {
    // get current date
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);

    // convert to string
    std::ostringstream oss;
    oss; oss << std::put_time(now_tm, "%Y-%m-%d");
    return oss.str();
}

std::string HumiditySensor::getCurrentTime() {
    // get current time
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);

    // convert to string
    std::ostringstream oss;
    oss; oss << std::put_time(now_tm, "%H:%M:%S");
    return oss.str();
}

void HumiditySensor::logHumidityToFile() {
    // open file in append mode 
    std::ofstream fout("HumidityLog.txt", std::ios::app);
    if (!fout) {
        std::cerr << "Failed to open HumidityLog.txt" << std::endl;
        return;
    }
    // get current time, date, and alert
    std::string currentTime = getCurrentTime();
    std::string currentDate = getCurrentDate();
    std::string alertStatus = alertHumidityChange();

    // log humidity and time to file
    fout << "Date: " << currentDate << " | Time: " << currentTime << " | Humidity Level: " << humidityLevel << " | Status: " << alertStatus << "\n";
    std::cout << "Date: " << currentDate << " Time: " << currentTime << ", Humidity Level: " << humidityLevel << std::endl;
    std::cout << alertHumidityChange() << "\n";
}

HumiditySensor::~HumiditySensor() {}
