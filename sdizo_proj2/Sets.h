#pragma once
#include <vector>

using namespace std;

struct SetStruct {
	size_t parent;
	int rank;
};
class Sets
{
private:
	vector<SetStruct> sets;
public:
	Sets(int n);
	void makeSet(size_t v);
	size_t findSet(size_t v);
	void unionSets(size_t v1, size_t v2);
	~Sets();
};

