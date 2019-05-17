#pragma once
#include "IncidenceMatrix.h"
#include "AdjacencyList.h"
#include <vector>
#include <queue>

class MyQueue {
private:
	vector<size_t> *d;
	vector<size_t> verticies;
public:
	MyQueue();
	MyQueue(vector<size_t> *d);
	void insert(size_t v);
	size_t pop();
	void swap(size_t v1, size_t v2);
	void fixUp(size_t s);
	void fixDown(size_t s);
	void buildFloyd();
	void print();
	bool empty();
};

void dijkstra(IncidenceMatrix *G, size_t v);
void dijkstra(AdjacencyList *G, size_t v);
void bellman_ford(IncidenceMatrix *G, size_t v);
void bellman_ford(AdjacencyList *G, size_t v);