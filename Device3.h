#pragma once
#include "Device.h"

class Device3 : public Device
{
	void startMeasurement() override;

public:
	Device3(std::string name, std::string measurementType);
	virtual ~Device3() {}
};
