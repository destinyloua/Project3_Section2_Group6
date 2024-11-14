#pragma once
// Humidity header file
#include <string>
#include <vector>

class HumiditySensor {
private:
    float humidityLevel;
public:
    HumiditySensor();
    void generateRandomHumidity();
    std::string alertHumidityChange();
    std::string getCurrentTime();
    std::string getCurrentDate();
    //void sendToHMI(std::string data);
    void logHumidityToFile();
    //void calibrate();
    ~HumiditySensor();
};
