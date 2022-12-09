#include <iostream>
#include <string>
#include <random>

#include "../HeaderFiles/Position.h"
#include "./Profiler.cpp"

using namespace std;

Position::Position()
{
    name = "Position";
    measurement_unit = "Meters";
    minValue = 0;
    maxValue = 15;
}

Position::Position(string name_init)
{
    name = name_init;
    measurement_unit = "Meters";
    minValue = 0;
    maxValue = 15;
}
double Position::measure()
{
    Profiler pro("Time pos::measure");
    random_device rd;
    mt19937 e2(rd());
    uniform_real_distribution<> dist(minValue, maxValue);
    return dist(e2);
}