#pragma once
#include <thread>
#include <string>

class Device
{
    std::string deviceName;
    std::string deviceMeasurementType;
    double measuredValue;
    std::thread t;

    virtual void startMeasurement() = 0;

public:
    Device(std::string name, std::string measurementType);
    virtual ~Device() = 0 {};
    void Start();
    void Join();
    std::string getName() const { return deviceName; }
    std::string getMeasurementType() const { return deviceMeasurementType; }
    double getMeasuredValue() const { return measuredValue; }
    void setMeasuredValue(double& value);
    void sendMessage() const;
};