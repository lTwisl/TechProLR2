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
        if(_allSensors[i]->name == "Acceleration")
        {
            measures.push_back(_allSensors[i]->measure());
        }
   }

   return measures;
}

//vector<double> IntegratedNavigationSystem::measure_position()
//{
//    vector<double> measures;
//    for(int i = 0; i < _allSensors.size(); ++i)
//    {
//        if (typeid(_allSensors[i]) == typeid(PosSensor))
//        {
//            measures.push_back(_allSensors[i].measure());
//        }
//    }
//
//    return measures;
//}

//vector<double> IntegratedNavigationSystem::measure_gyro()
//{
//    vector<double> measures;
//    for(int i = 0; i < _allSensors.size(); ++i)
//    {
//        if (typeid(_allSensors[i]) == typeid(Gyro))
//        {
//            measures.push_back(_allSensors[i].measure());
//        }
//    }
//
//    return measures;
//}

void IntegratedNavigationSystem::list_sensors()
{
    for(size_t i = 0; i < _allSensors.size(); ++i)
    {
        std::cout << _allSensors[i]->name << std::endl;
    }
}