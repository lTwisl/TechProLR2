#pragma once

#include "Sensor.h"

class Gyroscop : public Sensor
{
public:
    Gyroscop();
    double measure() override;
};