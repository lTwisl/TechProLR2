#include <iostream>
#include <string>
#include <random>

#include "../HeaderFiles/Gyroscop.h"

using namespace std;

Gyroscop::Gyroscop()
{
    name = "Gyroscop";
    measurement_unit = "rad/sec";
    minValue = 0;
    maxValue = 1;
}

Gyroscop::Gyroscop(string name_init)
{
    name = name_init;
    measurement_unit = "rad/sec";
    minValue = 0;
    maxValue = 1;
}

double Gyroscop::measure()
{
    random_device rd;
    mt19937 e2(rd());
    uniform_real_distribution<> dist(minValue, maxValue);
    return dist(e2);
}