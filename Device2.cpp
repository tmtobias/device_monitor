#include "Device2.h"

Device2::Device2(std::string name, std::string measurementType) :
	Device(name, measurementType)
{
}

void Device2::startMeasurement()
{
	using namespace std::chrono_literals;

	while (true)
	{
		std::this_thread::sleep_for(100ms);
		double value = rand();
		setMeasuredValue(value);
		sendMessage();
	}
}
