#include <iostream>
#include "../HeaderFiles/Sensor.h"

using namespace std;

Sensor::Sensor()
{
    name = "Sensor";
    measurement_unit = "null";
    minValue = 0;
    maxValue = 10;
}

Sensor::Sensor(string name_init)
{
    name = name_init;
    measurement_unit = "null";
    minValue = 0;
    maxValue = 10;
}

double Sensor::measure()
{
    cout << "Number" << endl;
    return 0;
}