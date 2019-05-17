#include "pch.h"
#include "spa.h"

void dijkstra(IncidenceMatrix *G, size_t v)
{
	vector<size_t> d;
	vector<int> p;
	MyQueue Q(&d);
	size_t n = G->getVerticiesCount();
	d.resize(n);
	p.resize(n);
	for (size_t i = 0; i < G->getVerticiesCount(); i++) {
		d[i] = INT_MAX;
		p[i] = -1;
		Q.insert(i);
	}
	d[v] = 0;
	Q.buildFloyd();
	while (!Q.empty()) {
		size_t u = Q.pop();
		vector<size_t> neighbours = G->getNeighbours(u);
		for (auto it = neighbours.begin(); it != neighbours.end(); ++it) {
			if (d[*it] > d[u] + G->getCapacity(u, *it)) {
				d[*it] = d[u] + G->getCapacity(u, *it);
				p[*it] = u;
				Q.buildFloyd();
			}
		}
	}
	for (size_t i = 0; i < n; i++) {
		if (i == v)
			continue;
		size_t j = i;
		cout << v << "-" << i << ": ";
		while (j != v) {
			cout << j << "<=";
			j = p[j];
		}
		cout << v << ", d=" << d[i] << endl;
	}
	return;
}

void dijkstra(AdjacencyList *G, size_t v)
{
	vector<size_t> d;
	vector<int> p;
	MyQueue Q(&d);
	size_t n = G->getVerticiesCount();
	d.resize(n);
	p.resize(n);
	for (size_t i = 0; i < G->getVerticiesCount(); i++) {
		d[i] = INT_MAX;
		p[i] = -1;
		Q.insert(i);
	}
	d[v] = 0;
	Q.buildFloyd();
	while (!Q.empty()) {
		size_t u = Q.pop();
		list<listElem> neighbours = G->getNeighbours(u);
		for (auto it = neighbours.begin(); it != neighbours.end(); ++it) {
			if (d[it->v] > d[u] + it->capacity) {
				d[it->v] = d[u] + it->capacity;
				p[it->v] = u;
				Q.buildFloyd();
			}
		}
	}
	for (size_t i = 0; i < n; i++) {
		if (i == v)
			continue;
		size_t j = i;
		cout << v << "-" << i << ": ";
		while (j != v) {
			cout << j << "<=";
			j = p[j];
		}
		cout << v << ", d=" << d[i] << endl;
	}
	return;
}

void bellman_ford(IncidenceMatrix * G, size_t v)
{
	vector<size_t> d;
	vector<int> p;
	size_t n = G->getVerticiesCount();
	d.resize(n, INT_MAX);
	p.resize(n, -1);
	d[v] = 0;
	bool test;
	bool result = true;
	for (size_t i = 0; i < n; i++) {
		test = true;
		for (size_t u = 0; u < n; u++) {
			vector<size_t> neighbours = G->getNeighbours(u);
			for (auto it = neighbours.begin(); it != neighbours.end(); ++it) {
				int capacity = G->getCapacity(u, *it);
				if (d[*it] > d[u] + capacity) {
					test = false;
					d[*it] = d[u] + capacity;
					p[*it] = u;
				}
			}
		}
		if (test) {
			break;
		}
	}
	if (!test) {
		for (size_t i = 0; i < n; i++) {
			vector<size_t> neighbours = G->getNeighbours(i);
			for (auto it = neighbours.begin(); it != neighbours.end(); ++it) {
				if (d[*it] > d[i] + G->getCapacity(i, *it)) result = false;
			}
		}
	}
	if (result) {
		for (size_t i = 0; i < n; i++) {
			if (i == v)
				continue;
			size_t j = i;
			cout << v << "-" << i << ": ";
			while (j != v) {
				cout << j << "<=";
				j = p[j];
			}
			cout << v << ", d=" << d[i] << endl;
		}
	}
}

void bellman_ford(AdjacencyList * G, size_t v)
{
	vector<size_t> d;
	vector<int> p;
	size_t n = G->getVerticiesCount();
	d.resize(n, INT_MAX);
	p.resize(n, -1);
	d[v] = 0;
	bool test;
	bool result = true;
	for (size_t i = 0; i < n; i++) {
		test = true;
		for (size_t u = 0; u < n; u++) {
			list<listElem> neighbours = G->getNeighbours(u);
			for (auto it = neighbours.begin(); it != neighbours.end(); ++it) {
				int capacity = it->capacity;
				if (d[it->v] > d[u] + capacity) {
					test = false;
					d[it->v] = d[u] + capacity;
					p[it->v] = u;
				}
			}
		}
		if (test) {
			break;
		}
	}
	if (!test) {
		for (size_t i = 0; i < n; i++) {
			list<listElem> neighbours = G->getNeighbours(i);
			for (auto it = neighbours.begin(); it != neighbours.end(); ++it) {
				if (d[it->v] > d[i] + it->capacity) result = false;
			}
		}
	}
	if (result) {
		for (size_t i = 0; i < n; i++) {
			if (i == v)
				continue;
			size_t j = i;
			cout << v << "-" << i << ": ";
			while (j != v) {
				cout << j << "<=";
				j = p[j];
			}
			cout << v << ", d=" << d[i] << endl;
		}
	}
}

MyQueue::MyQueue()
{
}

MyQueue::MyQueue(vector<size_t>* d)
{
	this->d = d;
}

void MyQueue::insert(size_t v)
{
	verticies.push_back(v);
	fixUp(verticies.size() - 1);
}

size_t MyQueue::pop()
{
	int min = verticies[0];
	verticies[0] = verticies[verticies.size() - 1];
	verticies.pop_back();
	fixDown(0);
	return min;
}

void MyQueue::swap(size_t v1, size_t v2)
{
	int temp = verticies[v1];
	verticies[v1] = verticies[v2];
	verticies[v2] = temp;
}

void MyQueue::fixUp(size_t s)
{
	while (s != 0) {
		if (d->at(verticies[s]) < d->at(verticies[s / 2])) {
			swap(s, s / 2);
			s = s / 2;
		}
		else {
			break;
		}
	}
}

void MyQueue::fixDown(size_t s)
{
	while (s < verticies.size()) {
		int l = 2 * s + 1;
		int r = 2 * s + 2;
		if (l < verticies.size() && d->at(verticies[s]) > d->at(verticies[l])) {
			swap(s, 2 * s + 1);
			s = 2 * s + 1;
		}
		else if (r < verticies.size() && d->at(verticies[s]) > d->at(verticies[r])) {
			swap(s, 2 * s + 2);
			s = 2 * s + 2;
		}
		else {
			break;
		}
	}
}

void MyQueue::buildFloyd()
{
	for (int i = (verticies.size() - 2) / 2; i >= 0; --i) {
		fixDown(i);
	}
}

void MyQueue::print()
{
	for (auto it = verticies.begin(); it != verticies.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

bool MyQueue::empty()
{
	return verticies.empty();
}
