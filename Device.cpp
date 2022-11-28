#include "Device.h"
#include "Message.h"

Device::Device(std::string name, std::string measurementType) :
	deviceName(name),
	deviceMeasurementType(measurementType),
	measuredValue(0.0)
{
}

void Device::Start()
{
	t = std::thread(&Device::startMeasurement, this);
}

void Device::Join()
{
	if (t.joinable())
	{
		t.join();
	}
}

void Device::setMeasuredValue(double& value)
{
	measuredValue = value;
}

void Device::sendMessage() const
{
	Message& message = Message::getInstance();
	message.sendMessage(getName(), getMeasurementType(), getMeasuredValue());
}
