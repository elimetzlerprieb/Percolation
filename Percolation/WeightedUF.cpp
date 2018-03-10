#include "stdafx.h"

WeightedUF::WeightedUF(int input_size) : nodes(input_size, 0), size(input_size, 0)
{
	for (int i = 0; i < input_size; i++)
	{
		nodes[i] = i;
		size[i] = 1;
	}
}

int WeightedUF::root(int p)
{
	while (p != nodes[p])
	{
		//nodes[p] = nodes[nodes[p]];
		p = nodes[p];
	}
	return p;
}

void WeightedUF::join(int p, int q)
{
	int a = root(p);
	int b = root(q);
	
	if (a == b)
	{
		return;
	}

	if (size[a] < size[b])
	{
		nodes[a] = b;
		size[b] += size[a];
	}
	else if (size[a] >= size[b])
	{
		nodes[b] = a;
		size[a] += b;
	}
}

bool WeightedUF::connected(int p, int q)
{
	if (root(p) == root(q))
	{
		return true;
	}
	return false;
}

int WeightedUF::count()
{
	return 1;
}

int WeightedUF::find(int p)
{
	return root(p);
}
 