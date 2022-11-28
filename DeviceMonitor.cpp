#include <iostream>
#include "Receiver.h"
#include "Device1.h"
#include "Device2.h"
#include "Device3.h"

int main()
{
    Receiver deviceMonitor;
    Device1 temperatureMeasurementSystem("Temperature Measurement System", "Temperature");
    Device2 pressureMeasurementSystem("Pressure Measurement System", "Pressure");
    Device3 humidityMeasurementSystem("Humidity Measurement System", "Humidity");

    deviceMonitor.Start();
    temperatureMeasurementSystem.Start();
    pressureMeasurementSystem.Start();
    humidityMeasurementSystem.Start();

    deviceMonitor.Join();
    temperatureMeasurementSystem.Join();
}
