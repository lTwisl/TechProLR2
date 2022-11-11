#pragma once

#include <string>

using namespace std;

class Sensor
{
public:
    string name;
    string measurement_unit;

    double minValue;
    double maxValue;

    Sensor();
    virtual double measure();
};