#include "pch.h"
#include "czas.h"

void Czas::start()
{
	startTime = chrono::high_resolution_clock::now();
}

void Czas::stop()
{
	endTime = chrono::high_resolution_clock::now();
}

void Czas::printResult()
{
	long ms = chrono::duration_cast<chrono::milliseconds>(Czas::endTime - Czas::startTime).count();
	if (ms > 0) {
		cout << ms << " ms";
	}
	else {
		cout << chrono::duration_cast<chrono::microseconds>(Czas::endTime - Czas::startTime).count() << " mikrosekund";
	}
}

long Czas::result()
{
	return chrono::duration_cast<chrono::microseconds>(Czas::endTime - Czas::startTime).count();
}
