#pragma once

#include "Sensor.h"

class Acceleration : public Sensor
{
public:
    Acceleration();
    double measure() override;
};