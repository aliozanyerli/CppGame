#include "MyTime.h"


mTime::mTime(){
    start = std::chrono::high_resolution_clock::now();
    last = start;
    deltaTime = 0.0;
    time = 0.0;
}
void mTime::updateTime(){
    last = std::chrono::high_resolution_clock::now();
}
void mTime::calculateDelta(){
    deltaTime = (std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count() - std::chrono::time_point_cast<std::chrono::microseconds>(last).time_since_epoch().count()) * 0.000001;
    time += deltaTime;
}

mTime Time = mTime();


Timer::Timer(){
    start = std::chrono::high_resolution_clock::now();
    name = "Benchmark";
}
Timer::Timer(std::string name){
    start = std::chrono::high_resolution_clock::now();
    this->name = name;
}
Timer::~Timer(){
    auto endT = std::chrono::high_resolution_clock::now();
    auto t1 = std::chrono::time_point_cast<std::chrono::microseconds>(start).time_since_epoch().count();
    auto t2 = std::chrono::time_point_cast<std::chrono::microseconds>(endT).time_since_epoch().count();
    std::cout << '\n' << name << ":    " << (t2 - t1) * 0.001 << "ms\n\n";
}