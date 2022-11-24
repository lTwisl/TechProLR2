#pragma once

#include "Sensor.h"

class Position : public Sensor
{
public:
    Position();
    double measure() override;
}; #pragma once
