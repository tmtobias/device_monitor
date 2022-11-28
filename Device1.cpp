#include "Device1.h"

Device1::Device1(std::string name, std::string measurementType) :
	Device(name, measurementType)
{
}

void Device1::startMeasurement()
{
	using namespace std::chrono_literals;

	while (true)
	{
		std::this_thread::sleep_for(500ms);
		double value = rand();
		setMeasuredValue(value);
		sendMessage();
	}
}
