#include <iostream>

#include "../HeaderFiles/IntegratedNavigationSystem.h"

void IntegratedNavigationSystem::add_sensor(Sensor& sensor)
{
    _allSensors.push_back(&sensor);
}

vector<double> IntegratedNavigationSystem::measure_acc()
{
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
   vector<double> measures;
   for(size_t i = 0; i < _allSensors.size(); ++i)
   {
           // cout <<"vfff"<<endl;
             //       cout <<typeid(*_allSensors[i]).name()<<endl;
                //    cout <<typeid(Position*).name()<<endl;
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