#pragma once
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"
#include <random>
#include <vector>
#include <algorithm>

IncidenceMatrix randomGraphMatrix(size_t verticies, double density, bool directed = true);
AdjacencyList randomGraphList(size_t verticies, bool directed = true);