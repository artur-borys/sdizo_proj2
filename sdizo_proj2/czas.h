#pragma once
#include <chrono>
#include <iostream>

using namespace std;

class Czas {
private:
	chrono::high_resolution_clock::time_point startTime, endTime;
public:
	void start();
	void stop();
	void printResult();
	long result();
};