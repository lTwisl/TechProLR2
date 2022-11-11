#include <iostream>
#include <string>
#include <random>

#include "../HeaderFiles/Acceleration.h"

using namespace std;

Acceleration::Acceleration()
{
    name = "Acceleration";
    measurement_unit = "m/c^2";
    minValue = 0;
    maxValue = 1;
}

double Acceleration::measure()
{
    random_device rd;
    mt19937 e2(rd());
    uniform_real_distribution<> dist(minValue, maxValue);
    return dist(e2);
}