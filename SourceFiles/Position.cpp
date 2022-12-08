#include <iostream>
#include <string>
#include <random>

#include "../HeaderFiles/Position.h"

using namespace std;

Position::Position()
{
    name = "Position";
    measurement_unit = "Meters";
    minValue = 0;
    maxValue = 15;
}

Position::Position("Position")
{
    name = name_init;
    measurement_unit = "Meters";
    minValue = 0;
    maxValue = 15;
}
double Position::measure()
{
    random_device rd;
    mt19937 e2(rd());
    uniform_real_distribution<> dist(minValue, maxValue);
    return dist(e2);
}