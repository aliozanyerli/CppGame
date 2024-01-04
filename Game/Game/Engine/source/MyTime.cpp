#include "MyTime.h"


mTime::mTime(){
    start = high_resolution_clock::now();
    last = start;
    deltaTime = 0.0;
    time = 0.0;
}
void mTime::updateTime(){
    last = high_resolution_clock::now();
}
void mTime::calculateDelta(){
    deltaTime = (time_point_cast<microseconds>(high_resolution_clock::now()).time_since_epoch().count() - time_point_cast<microseconds>(last).time_since_epoch().count()) * 0.000001;
    time += deltaTime;
}

mTime Time = mTime();


Timer::Timer(){
    start = high_resolution_clock::now();
    name = "Benchmark";
}
Timer::Timer(string name){
    start = high_resolution_clock::now();
    this->name = name;
}
Timer::~Timer(){
    auto endT = high_resolution_clock::now();
    auto t1 = time_point_cast<microseconds>(start).time_since_epoch().count();
    auto t2 = time_point_cast<microseconds>(endT).time_since_epoch().count();
    cerr << '\n' << name << ":    " << (t2 - t1) * 0.001 << "ms\n\n";
}