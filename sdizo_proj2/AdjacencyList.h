#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

struct listElem {
	size_t v;
	int capacity;
};

class AdjacencyList
{
private:
	size_t v, e = 0;
	vector<list<listElem>> verticies;
	bool directed;
public:
	AdjacencyList();
	AdjacencyList(size_t v, bool directed);
	void createEdge(size_t v1, size_t v2, int capacity);
	int getCapacity(size_t v1, size_t v2);
	list<listElem> getNeighbours(size_t v);
	size_t getVerticiesCount();
	double getDensity();
	static AdjacencyList readFromFile(string path, bool directed);
	void print();
	~AdjacencyList();
};

