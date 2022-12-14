#include <iostream>
#include <string>

#include "../HeaderFiles/IntegratedNavigationSystem.h"

#include "./Profiler.cpp"

using namespace std;

int main(int argc, char* argv[])
{
    Profiler pp("main");
    IntegratedNavigationSystem ins;
    Acceleration a("accelerometr");
    Acceleration a1;
    Gyroscop g;
    Position p;

    ins.add_sensor(a);
    ins.add_sensor(a1);
    ins.add_sensor(g);
    ins.add_sensor(p);

    for(auto value : ins.measure_acc())
    {
        cout << "acc: ";
        cout << value << " " << a1.measurement_unit << endl;
    }

    for(auto value : ins.measure_gyro())
    {
        cout << "gyro: ";
        cout << value << " " <<  g.measurement_unit << endl;
    }

    for(auto value : ins.measure_position())
    {
        cout << "pos: ";
        cout << value << " " << p.measurement_unit << endl;
    }
    cout <<"---------------------------------------------------"<<endl;
    ins.list_sensors();
    return 0;
}