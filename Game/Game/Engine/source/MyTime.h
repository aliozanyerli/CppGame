#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;


class mTime{
public:
    double deltaTime, time;
    mTime();
    void updateTime();
    void calculateDelta();
private:
    time_point<high_resolution_clock> start, last;
};
extern mTime Time;


class Timer{
public:
    Timer();
    Timer(string name);
    ~Timer();
private:
    string name;
    time_point<high_resolution_clock> start;
};