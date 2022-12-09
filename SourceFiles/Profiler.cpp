#include <iostream>
#include <chrono>

using namespace std;


class Profiler
{
private:
    chrono::steady_clock::time_point start_time;
    string name;

public:
    Profiler(string name)
    {
        start_time = chrono::steady_clock::now();
        this->name = name;
    }

    ~Profiler()
    {
        auto end_time = chrono::steady_clock::now();
        auto delta_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
        cout << name << ": " << delta_time << endl;
    }
};