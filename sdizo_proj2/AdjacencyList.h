#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <iomanip>

using namespace std;

struct listElem {
	size_t v;
	int capacity;
};

class AdjacencyList
{
private:
	size_t v;
	vector<list<listElem>> verticies;
	bool directed;
public:
	AdjacencyList();
	AdjacencyList(size_t v, bool directed);
	void createEdge(size_t v1, size_t v2, int capacity);
	int getCapacity(size_t v1, size_t v2);
	list<listElem> getNeighbours(size_t v);
	size_t getVerticiesCount();
	void print();
	~AdjacencyList();
};

