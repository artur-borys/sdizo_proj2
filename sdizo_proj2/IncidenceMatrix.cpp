#include "pch.h"
#include "IncidenceMatrix.h"

IncidenceMatrix::IncidenceMatrix(size_t v, bool directed)
{
	this->v = v;
	this->directed = directed;
}

IncidenceMatrix::IncidenceMatrix(size_t v, size_t e, bool directed)
{
	this->v = v;
	this->e = e;
	matrix.resize(e);
	for (auto it = matrix.begin(); it != matrix.end(); ++it) {
		it->resize(v);
	}
}

void IncidenceMatrix::createEdge(size_t v1, size_t v2, int capacity)
{
	vector<int> edge((size_t) this->v);
	matrix.push_back(edge);
	matrix[e][v1] = capacity;
	if (!directed) {
		matrix[e][v2] = capacity;
	}
	else {
		matrix[e][v2] = -capacity;
	}
	
	this->e++;
}

vector<size_t> IncidenceMatrix::getNeighbours(size_t v)
{
	vector<size_t> neighbours;
	for (size_t i = 0; i < this->e; i++) {
		if (this->matrix[i][v] != 0) {
			if (directed) {
				if (this->matrix[i][v] < 0) {
					return neighbours;
				}
			}
			for (size_t j = 0; j < this->v; j++) {
				if (j != v) {
					if (this->matrix[i][v] != 0) {
						neighbours.push_back(j);
					}
				}
			}
		}
	}
	return neighbours;
}

int IncidenceMatrix::getCapacity(size_t v1, size_t v2)
{
	for (size_t i = 0; i < e; i++) {
		if (matrix[i][v1] != 0 && matrix[i][v2] != 0) {
			if (matrix[i][v1] > 0) {
				return matrix[i][v1];
			}
			else if (!directed && matrix[i][v1] < 0) {
				return abs(matrix[i][v1]);
			}
		}
	}
	return 0;
}

int IncidenceMatrix::getCapacity(size_t e)
{
	for (size_t i = 0; i < this->v; i++) {
		if (this->matrix.at(e).at(i) != 0) {
			return abs(this->matrix.at(e).at(i));
		}
	}
	return 0;
}

size_t IncidenceMatrix::getVerticiesCount()
{
	return v;
}

size_t IncidenceMatrix::getEdgesCount()
{
	return e;
}

vector<vector<int>>* IncidenceMatrix::getMatrix()
{
	return &this->matrix;
}

void IncidenceMatrix::print()
{
	cout << setw(5);
	cout << "|";
	for (size_t i = 0; i < this->e; i++) {
		cout << setw(5);
		cout << i;
	}
	cout << endl;
	for (size_t i = 0; i <= this->e; i++) {
		cout << setfill('=') << setw(5);
		cout << '=';
	}
	cout << setfill(' ');
	for (size_t i = 0; i < this->v; i++) {
		cout << endl;
		cout << setw(4);
		cout << i << "|";
		for (size_t j = 0; j < this->e; j++) {
			cout << setw(5);
			cout << this->matrix.at(j).at(i);
		}
	}
	cout << endl;
}

IncidenceMatrix::~IncidenceMatrix()
{
}
