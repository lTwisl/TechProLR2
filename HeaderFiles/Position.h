#pragma once

#include "Sensor.h"

class Position : public Sensor
{
public:
    Position();
    Position(string name_init);
    double measure() override;
};