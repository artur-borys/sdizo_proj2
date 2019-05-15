#include "pch.h"
#include "IncidenceMatrix.h"

IncidenceMatrix::IncidenceMatrix(size_t v, size_t e)
{
	this->e = e;
	this->v = v;
	this->matrix.resize(e);
	for (size_t i = 0; i < this->e; i++) {
		this->matrix.at(i).resize(v);
	}
}

void IncidenceMatrix::createEdge(size_t v1, size_t v2, int capacity, bool directed)
{
	if (this->current_e == this->e) {
		cout << "Nie mozna dodac wiecej krawedzi" << endl;
		return;
	}
	vector<int> vertices;
	vertices.resize(this->v);
	vertices.at(v1) = capacity;
	vertices.at(v2) = capacity;
	if (directed) {
		vertices.at(v2) = -vertices.at(v2);
	}

	this->matrix.at(this->current_e) = vertices;
	this->current_e++;
}

vector<int> IncidenceMatrix::getNeighbours(size_t v, bool directed)
{
	vector<int> neighbours;
	for (size_t i = 0; i < this->current_e; i++) {
		if (this->matrix[i][v] != 0) {
			if (directed) {
				if (this->matrix.at(i).at(v) < 0) {
					return neighbours;
				}
			}
			for (size_t j = 0; j < this->v; j++) {
				if (j != v) {
					if (this->matrix.at(i).at(j) != 0) {
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
	for (size_t i = 0; i < this->current_e; i++) {
		if (this->matrix.at(i).at(v1) != 0 && this->matrix.at(i).at(v2) != 0) {
			return abs(matrix.at(i).at(v1));
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
}

IncidenceMatrix::~IncidenceMatrix()
{
}
