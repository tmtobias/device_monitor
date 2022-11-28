#pragma once
#include "Device.h"

class Device1 : public Device
{
	void startMeasurement() override;

public:
	Device1(std::string name, std::string measurementType);
	virtual ~Device1() {}
};
