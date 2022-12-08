#pragma once

#include "Sensor.h"

class Acceleration : public Sensor
{
public:
    Acceleration();
    Acceleration(string name_init);
    double measure() override;
};