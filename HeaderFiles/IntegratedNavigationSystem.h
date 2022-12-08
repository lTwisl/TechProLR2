#pragma once

#include <iostream>
#include <vector>

#include "Sensor.h"
#include "Acceleration.h"
#include "Gyroscop.h"
#include "Position.h"

using namespace std;

class IntegratedNavigationSystem
{
private:
    vector<Sensor*> _allSensors;

public:
    void add_sensor(Sensor& sensor);
    vector<double> measure_acc();
    vector<double> measure_gyro();
    vector<double> measure_position();
    void list_sensors();
};