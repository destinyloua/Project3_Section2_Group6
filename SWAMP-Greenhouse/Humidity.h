#pragma once
// Humidity header file
#include <string>

class HumiditySensor {
private:
    double humidityLevel;
public:
    HumiditySensor();
    void generateRandomHumidity();
    std::string alertHumidityChange();
    std::string getCurrentTime();
    std::string getCurrentDate();
    void logHumidityToFile();
    ~HumiditySensor();
};
