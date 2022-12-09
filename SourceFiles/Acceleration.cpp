#include <iostream>
#include <string>
#include <random>

#include "../HeaderFiles/Acceleration.h"
#include "./Profiler.cpp"

using namespace std;



Acceleration::Acceleration()
{
    name = "Acceleration";
    measurement_unit = "m/c^2";
    minValue = 0;
    maxValue = 1;
}

Acceleration::Acceleration(string name_init)
{
    name = name_init;
    measurement_unit = "m/c^2";
    minValue = 0;
    maxValue = 1;
}


double Acceleration::measure()
{
    Profiler pro("Accelerometer");
    random_device rd;
    mt19937 e2(rd());
    uniform_real_distribution<> dist(minValue, maxValue);
    return dist(e2);

}