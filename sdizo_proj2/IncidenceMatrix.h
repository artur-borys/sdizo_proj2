#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class IncidenceMatrix
{
private:
	size_t v, e = 0, current_e = 0;
	vector<vector<int>> matrix;
	bool directed;
public:
	IncidenceMatrix(size_t v, bool directed);
	IncidenceMatrix(size_t v, size_t e, bool directed);
	void createEdge(size_t v1, size_t v2, int capacity);
	vector<size_t> getNeighbours(size_t v);
	int getCapacity(size_t v1, size_t v2);
	int getCapacity(size_t e);
	size_t getVerticiesCount();
	size_t getEdgesCount();
	vector<vector<int>>* getMatrix();
	void print();
	~IncidenceMatrix();
};

