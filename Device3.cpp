#include "Device3.h"

Device3::Device3(std::string name, std::string measurementType) :
	Device(name, measurementType)
{
}

void Device3::startMeasurement()
{
	using namespace std::chrono_literals;

	while (true)
	{
		std::this_thread::sleep_for(1000ms);
		double value = rand();
		setMeasuredValue(value);
		sendMessage();
	}
}
