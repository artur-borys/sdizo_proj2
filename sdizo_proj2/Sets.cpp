#include "pch.h"
#include "Sets.h"


Sets::Sets(int n)
{
	sets.resize(n);
}

void Sets::makeSet(size_t v)
{
	sets[v].parent = v;
	sets[v].rank = 0;
}

size_t Sets::findSet(size_t v)
{
	if (sets[v].parent != v) {
		sets[v].parent = findSet(sets[v].parent);
	}
	return sets[v].parent;
}

void Sets::unionSets(size_t v1, size_t v2)
{
	size_t a = findSet(v1);
	size_t b = findSet(v2);
	
	if (sets[a].rank < sets[b].rank) {
		sets[a].parent = b;
	}
	else {
		sets[b].parent = a;
	}

	if (sets[a].rank == sets[b].rank) {
		sets[a].rank = sets[a].rank + 1;
	}
}

Sets::~Sets()
{
	sets.clear();
}
