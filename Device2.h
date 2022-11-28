#pragma once
#include "Device.h"

class Device2 : public Device
{
	void startMeasurement() override;

public:
	Device2(std::string name, std::string measurementType);
	virtual ~Device2() {}
};
