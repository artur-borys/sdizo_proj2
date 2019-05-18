#pragma once
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"
#include <random>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

void randomGraph(string path, size_t verticies, double density);
IncidenceMatrix randomGraphMatrix(size_t verticies, double density, bool directed = true);
AdjacencyList randomGraphList(size_t verticies, double density, bool directed = true);