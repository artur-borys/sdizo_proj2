#include "pch.h"
#include "utils.h"

using namespace std;

void randomGraph(string path, size_t verticies, double density)
{
	ofstream f;
	f.open(path);
	random_device r;
	default_random_engine el(r());
	uniform_int_distribution<int> weight_dist(1, 10);
	uniform_int_distribution<size_t> verticies_dist(0, verticies - 1);
	IncidenceMatrix G(verticies, false);
	vector<size_t> S;
	vector<size_t> T;
	vector<bool> visited;
	int capacity;
	visited.resize(verticies, false);
	for (int i = 0; i < verticies; i++) S.push_back(i);
	uniform_int_distribution<size_t> dist(0, S.size() - 1);
	size_t current_node = S[dist(el)];
	S.erase(find(S.begin(), S.end(), current_node));
	T.push_back(current_node);
	f << verticies << " " << 1 << endl;
	while (!S.empty()) {
		uniform_int_distribution<size_t> dist(0, S.size() - 1);
		size_t neighbour_node = S[dist(el)];
		if (find(T.begin(), T.end(), neighbour_node) == T.end()) {
			capacity = weight_dist(el);
			G.createEdge(current_node, neighbour_node, capacity);
			f << current_node << " " << neighbour_node << " " << capacity << endl;
			S.erase(find(S.begin(), S.end(), neighbour_node));
			T.push_back(neighbour_node);
		}
		current_node = neighbour_node;
	}
	while (G.getDensity() < density) {
		size_t v1 = verticies_dist(el), v2 = verticies_dist(el);
		if (v1 == v2) continue;
		if (G.getCapacity(v1, v2) != 0) continue;
		capacity = weight_dist(el);
		G.createEdge(v1, v2, capacity);
		f << v1 << " " << v2 << " " << capacity << endl;
	}
	f.close();
}

IncidenceMatrix randomGraphMatrix(size_t verticies, double density, bool directed)
{
	random_device r;
	default_random_engine el(r());
	uniform_int_distribution<int> weight_dist(1, 10);
	uniform_int_distribution<size_t> verticies_dist(0, verticies - 1);
	IncidenceMatrix G(verticies, directed);
	vector<size_t> S;
	vector<size_t> T;
	vector<bool> visited;
	int capacity;
	visited.resize(verticies, false);
	for (int i = 0; i < verticies; i++) S.push_back(i);
	uniform_int_distribution<size_t> dist(0, S.size() - 1);
	size_t current_node = S[dist(el)];
	S.erase(find(S.begin(), S.end(), current_node));
	T.push_back(current_node);
	while (!S.empty()) {
		uniform_int_distribution<size_t> dist(0, S.size() - 1);
		size_t neighbour_node = S[dist(el)];
		if (find(T.begin(), T.end(), neighbour_node) == T.end()) {
			capacity = weight_dist(el);
			G.createEdge(current_node, neighbour_node, capacity);
			S.erase(find(S.begin(), S.end(), neighbour_node));
			T.push_back(neighbour_node);
		}
		current_node = neighbour_node;
	}
	while (G.getDensity() < density) {
		size_t v1 = verticies_dist(el), v2 = verticies_dist(el);
		if (v1 == v2) continue;
		if (G.getCapacity(v1, v2) != 0) continue;
		capacity = weight_dist(el);
		G.createEdge(v1, v2, capacity);
	}
	return G;
}

AdjacencyList randomGraphList(size_t verticies, double density, bool directed)
{
	ofstream f;
	random_device r;
	default_random_engine el(r());
	uniform_int_distribution<int> weight_dist(1, 10);
	uniform_int_distribution<size_t> verticies_dist(0, verticies - 1);
	AdjacencyList G(verticies, directed);
	vector<size_t> S;
	vector<size_t> T;
	vector<bool> visited;
	int capacity;
	visited.resize(verticies, false);
	for (int i = 0; i < verticies; i++) S.push_back(i);
	uniform_int_distribution<size_t> dist(0, S.size() - 1);
	size_t current_node = S[dist(el)];
	S.erase(find(S.begin(), S.end(), current_node));
	T.push_back(current_node);
	while (!S.empty()) {
		uniform_int_distribution<size_t> dist(0, S.size() - 1);
		size_t neighbour_node = S[dist(el)];
		if (find(T.begin(), T.end(), neighbour_node) == T.end()) {
			capacity = weight_dist(el);
			G.createEdge(current_node, neighbour_node, capacity);
			S.erase(find(S.begin(), S.end(), neighbour_node));
			T.push_back(neighbour_node);
		}
		current_node = neighbour_node;
	}
	while (G.getDensity() < density) {
		size_t v1 = verticies_dist(el), v2 = verticies_dist(el);
		if (v1 == v2) continue;
		if (G.getCapacity(v1, v2) != 0) continue;
		capacity = weight_dist(el);
		G.createEdge(v1, v2, capacity);
	}
	return G;
}
