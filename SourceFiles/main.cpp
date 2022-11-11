#include <iostream>
#include <string>

#include "../HeaderFiles/IntegratedNavigationSystem.h"

using namespace std;

int main(int argc, char* argv[])
{
    IntegratedNavigationSystem ins;
    Sensor s;
    Acceleration a;
    ins.add_sensor(s);
    ins.add_sensor(a);

    for(auto value : ins.measure_acc())
    {
        cout << value << endl;
    }
    return 0;
}