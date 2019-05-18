#include "pch.h"
#include "AdjacencyList.h"


AdjacencyList::AdjacencyList()
{
}

AdjacencyList::AdjacencyList(size_t v, bool directed)
{
	verticies.resize(v);
	this->v = v;
	this->directed = directed;
}

void AdjacencyList::createEdge(size_t v1, size_t v2, int capacity)
{
	listElem v1_neighbour;
	v1_neighbour.v = v2;
	v1_neighbour.capacity = capacity;
	verticies[v1].push_back(v1_neighbour);
	if (!this->directed) {
		listElem v2_neighbour;
		v2_neighbour.v = v1;
		v2_neighbour.capacity = capacity;
		verticies[v2].push_back(v2_neighbour);
	}
	this->e++;
}

int AdjacencyList::getCapacity(size_t v1, size_t v2)
{
	for (auto it = verticies[v1].begin(); it != verticies[v1].end(); ++it) {
		if (it->v == v2) {
			return it->capacity;
		}
	}
	return 0;
}

list<listElem> AdjacencyList::getNeighbours(size_t v) {
	return verticies[v];
}

size_t AdjacencyList::getVerticiesCount()
{
	return v;
}

double AdjacencyList::getDensity()
{
	return (double)e / (v*(v - 1) / 2);
}

AdjacencyList AdjacencyList::readFromFile(string path, bool directed)
{
	fstream f;
	size_t e, v, v1, v2;
	int capacity;
	string line;
	stringstream str_stream;
	f.open(path);
	if (f.is_open()) {
		getline(f, line);
		str_stream = stringstream(line);
		str_stream >> v >> e;
		AdjacencyList G(v, directed);
		while (getline(f, line)) {
			str_stream = stringstream(line);
			str_stream >> v1 >> v2 >> capacity;
			G.createEdge(v1, v2, capacity);
		}
		return G;
	}
	else {
		cout << "Blad poczas odczytywania pliku" << endl;
		return AdjacencyList(0, false);
	}
	f.close();
}

void AdjacencyList::print()
{
	for (size_t i = 0; i < verticies.size(); i++) {
		cout << i << ": [";
		for (auto it = verticies[i].begin(); it != verticies[i].end(); ++it) {
			cout << setw(4) << it->v;
		}
		cout << "]" << endl;
	}
}


AdjacencyList::~AdjacencyList()
{
}
