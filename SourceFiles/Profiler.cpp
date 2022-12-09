#include <iostream>
#include <chrono>

using namespace std;


class Profiler
{
private:
    chrono::steady_clock::time_point start_time;

public:
    Profiler()
    {
        start_time = chrono::steady_clock::now();
    }

    ~Profiler()
    {
        auto end_time = chrono::steady_clock::now();
        auto delta_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
        cout << delta_time << endl;
    }
};