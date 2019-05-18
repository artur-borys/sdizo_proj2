#include "pch.h"
#include "utils.h"

using namespace std;

IncidenceMatrix randomGraphMatrix(size_t verticies, double density, bool directed)
{
	random_device r;
	default_random_engine el(r());
	uniform_int_distribution<int> weight_dist(1, 10);
	uniform_int_distribution<size_t> verticies_dist(0, verticies - 1);
	IncidenceMatrix G(verticies, directed);
	vector<size_t> connected;
	for (size_t i = 0; i < verticies - 1 && connected.size() < verticies; i++) {
		connected.push_back(i);
		size_t target = verticies_dist(el);
		while (find(connected.begin(), connected.end(), target) != connected.end()) {
			target = verticies_dist(el);
		}
		//connected.push_back(target);
		G.createEdge(i, target, weight_dist(el));
	}
	while (G.getDensity() < density) {
		G.createEdge(verticies_dist(el), verticies_dist(el), weight_dist(el));
	}
	return G;
}
