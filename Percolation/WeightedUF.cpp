#include "stdafx.h"

WeightedUF::WeightedUF(int input_size) : nodes(input_size, 0), depth(input_size, 0)
{
	for (int i = 0; i < input_size; i++)
	{
		nodes[i] = i;
		depth[i] = 0;
	}
}

int WeightedUF::root(int p)
{
	while (nodes[p] != p)
	{
		p = nodes[p];
	}
	return p;
}

void WeightedUF::join(int p, int q)
{
	int i = root(p);
	int j = root(q);

	if (depth[p] < depth[q])
	{
		nodes[q] = i;
		depth[q]++;
	}
	else if (depth[q] >= depth[p])
	{
		nodes[p] = j;
		depth[p]++;
	}
}

bool WeightedUF::connected(int p, int q)
{
	if (nodes[p] == nodes[q])
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
 