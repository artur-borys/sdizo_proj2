#pragma once
#include <vector>
#include <list>
#include <iomanip>
#include "IncidenceMatrix.h"
#include <queue>

using namespace std;

struct Edge {
	int v1, v2;
	int capacity;
};

class keyComparison {
public:
	bool operator() (const Edge& lhs, const Edge& rhs) const {
		return lhs.capacity > rhs.capacity;
	}
};

IncidenceMatrix prim_matrix(IncidenceMatrix *G, size_t v, bool show_results = false) {
	priority_queue<Edge, vector<Edge>, keyComparison> Q;
	vector<bool> visited;
	size_t n = G->getVerticiesCount();
	visited.resize(n);
	IncidenceMatrix T(n, false);
	visited[v] = true;
	int sum = 0;
	for (size_t i = 1; i < n; i++) {
		vector<size_t> neighbours = G->getNeighbours(v);
		for (auto it = neighbours.begin(); it != neighbours.end(); ++it) {
			if (visited[*it] == false) {
				if (G->getCapacity(v, *it)) {
					Edge e;
					e.v1 = v;
					e.v2 = *it;
					e.capacity = G->getCapacity(v, *it);
					Q.push(e);
				}
			}
		}
		Edge e;
		do {
			e = Q.top();
			Q.pop();
		} while (visited[e.v2]);
		T.createEdge(e.v1, e.v2, e.capacity);	
		visited[e.v2] = true;
		sum += e.capacity;
		v = e.v2;
	}
	if (show_results) {
		T.print();
		cout << "Suma wag krawedzi: " << sum << endl;
	}
	return T;
}

AdjacencyList prim_list(AdjacencyList *G, size_t v, bool show_results = false) {
	priority_queue<Edge, vector<Edge>, keyComparison> Q;
	vector<bool> visited;
	size_t n = G->getVerticiesCount();
	visited.resize(n);
	AdjacencyList T(n, false);
	visited[v] = true;
	int sum = 0;
	for (size_t i = 1; i < n; i++) {
		list<listElem> neighbours = G->getNeighbours(v);
		for (auto it = neighbours.begin(); it != neighbours.end(); ++it) {
			if (visited[it->v] == false) {
				if (G->getCapacity(v, it->v)) {
					Edge e;
					e.v1 = v;
					e.v2 = it->v;
					e.capacity = G->getCapacity(v, it->v);
					Q.push(e);
				}
			}
		}
		Edge e;
		do {
			e = Q.top();
			Q.pop();
		} while (visited[e.v2]);
		T.createEdge(e.v1, e.v2, e.capacity);
		visited[e.v2] = true;
		sum += e.capacity;
		v = e.v2;
	}
	if (show_results) {
		T.print();
		cout << "Suma wag krawedzi: " << sum << endl;
	}
	return T;
}

IncidenceMatrix kruskal_matrix(IncidenceMatrix *G, bool show_results = false) {
	vector<Edge> edges;
	for (auto it = G->getMatrix()->begin(); it != G->getMatrix()->end(); ++it) {
		for (auto it2 = it->begin(); it2 != it->end(); ++it2) {

		}
	}
}