#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class IncidenceMatrix
{
private:
	size_t v, e, current_e;
	vector<vector<int>> matrix;
public:
	IncidenceMatrix(size_t v, size_t e);
	void createEdge(size_t v1, size_t v2, int capacity, bool directed);
	vector<int> getNeighbours(size_t v, bool directed);
	int getCapacity(size_t v1, size_t v2);
	int getCapacity(size_t e);
	void print();
	~IncidenceMatrix();
};

