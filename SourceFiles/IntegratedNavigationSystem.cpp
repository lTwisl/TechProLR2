#include <iostream>

#include "../HeaderFiles/IntegratedNavigationSystem.h"

#include "./Profiler.cpp"

void IntegratedNavigationSystem::add_sensor(Sensor& sensor)
{
    Profiler p_add("time ins::addSensor");
    _allSensors.push_back(&sensor);
}

vector<double> IntegratedNavigationSystem::measure_acc()
{
    Profiler p_acc("time ins::measure_acc");
   vector<double> measures;

   for(size_t i = 0; i < _allSensors.size(); ++i)
   {
        if(typeid(*_allSensors[i]) == typeid(Acceleration))
        {
            Acceleration* a = static_cast<Acceleration*>(_allSensors[i]);
            measures.push_back(a->measure());
        }
   }

   return measures;
}

vector<double> IntegratedNavigationSystem::measure_position()
{
    Profiler p_acc("time ins::measure_position");
   vector<double> measures;
   for(size_t i = 0; i < _allSensors.size(); ++i)
   {
       if (typeid(*_allSensors[i]) == typeid(Position))
       {
            Position* a = static_cast<Position*>(_allSensors[i]);
            measures.push_back(a->measure());
       }
   }

   return measures;
}

vector<double> IntegratedNavigationSystem::measure_gyro()
{
    Profiler p_acc("time ins::measure_gyro");
    vector<double> measures;
    for(size_t i = 0; i < _allSensors.size(); ++i)
    {
        if (typeid(*_allSensors[i]) == typeid(Gyroscop))
        {
            Gyroscop* a = static_cast<Gyroscop*>(_allSensors[i]);
            measures.push_back(a->measure());
        }
    }

    return measures;
}

void IntegratedNavigationSystem::list_sensors()
{
    for(size_t i = 0; i < _allSensors.size(); ++i)
    {
        std::cout << _allSensors[i]->name << std::endl;
    }
}