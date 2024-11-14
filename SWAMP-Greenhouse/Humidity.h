#pragma once
// Humidity header file
#include <string>
#include <vector>

class HumiditySensor {
private:
    std::string dataFilePath;
    float humidityLevel;
    float calibrationOffset;
    std::vector<float> humidityLog;
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
