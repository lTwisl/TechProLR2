#pragma once

#include "Sensor.h"

class Gyroscop : public Sensor
{
public:
    Gyroscop();
    Gyroscop(string name_init);
    double measure() override;
};