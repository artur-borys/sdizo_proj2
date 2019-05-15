#pragma once
#include <vector>
#include <list>
#include <iomanip>
#include "IncidenceMatrix.h"
#include <queue>
#include <set>

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

vector<set<size_t>>::iterator FindSet(size_t v, vector<set<size_t>> *sets) {
	for (auto it = sets->begin(); it != sets->end(); ++it) {
		if (it->find(v) != it->end()) {
			return it;
		}
	}
	return sets->end();
}

void UnionSets(Edge e, vector<set<size_t>> *sets) {
	auto set1 = FindSet(e.v1, sets);
	auto set2 = FindSet(e.v2, sets);
	for (auto it = set2->begin(); it != set2->end(); ++it) {
		set1->insert(*it);
	}
	sets->erase(set2);
}

IncidenceMatrix kruskal_matrix(IncidenceMatrix *G, bool show_results = false) {
	vector<set<size_t>> Z;
	priority_queue<Edge, vector<Edge>, keyComparison> Q;
	/*for (auto it = G->getMatrix()->begin(); it != G->getMatrix()->end(); ++it) {
		int v1 = -1, v2 = -1, capacity = 0;
		for (size_t i = 0, found = 0; i < it->size() || found == 2; i++) {
			if ((*it)[i] != 0) {
				if (found == 0) {
					v1 = (*it)[i];
				}
				else {
					v2 = (*it)[i];
				}
				found++;
			}
		}
		Edge e;
		e.v1 = v1;
		e.v2 = v2;
		e.capacity = G->getCapacity(v1, v2);
		Q.push(e);
	}*/
	size_t n = G->getVerticiesCount();
	IncidenceMatrix T(n, false);
	Edge e;
	int sum = 0;
	for (size_t v = 0; v < n; v++) {
		set<size_t> s;
		s.insert(v);
		Z.push_back(s);
		vector<size_t> neighbours = G->getNeighbours(v);
		for (auto it = neighbours.begin(); it != neighbours.end(); ++it) {
			if (G->getCapacity(v, *it)) {
				e.v1 = v;
				e.v2 = *it;
				e.capacity = G->getCapacity(v, *it);
				Q.push(e);
			}
		}
	}
	for (size_t i = 1; i < n; i++) {
		do {
			e = Q.top();
			Q.pop();
		} while (FindSet(e.v1, &Z) == FindSet(e.v2, &Z));
		T.createEdge(e.v1, e.v2, e.capacity);
		UnionSets(e, &Z);
		sum += e.capacity;
	}
	if (show_results) {
		T.print();
		cout << "Suma wag krawedzi: " << sum << endl;
	}
	return T;
}