#pragma once
#include <iostream>
#include <chrono>



class mTime{
public:
    double deltaTime, time;
    mTime();
    void updateTime();
    void calculateDelta();
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start, last;
};
extern mTime Time;


class Timer{
public:
    Timer();
    Timer(std::string name);
    ~Timer();
private:
    std::string name;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};