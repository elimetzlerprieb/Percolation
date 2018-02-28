#include "stdafx.h"


Percolator::Percolator(int input_size) : grid(input_size * input_size, 1)
{
	size = input_size;
}

int Percolator::convertCoordinatesToIndex(int row, int column)
{
	return (row * size + column);
}

void Percolator::openSite(int row, int column)
{
	int index = convertCoordinatesToIndex(row, column);
	grid[index] = 0;
}

bool Percolator::isSiteOpen(int row, int column)
{
	int index = convertCoordinatesToIndex(row, column);
	if (grid[index] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Percolator::simulate()
{
	// initialize a virutal top and virtual bottom site 
	// randomly select a site and open it up
	// check to see if any adjacent sites are already open
	// if so, add the new site to the set of open sites that includes its neighbors, do for all neighbors
	// check to see if the top and bottom are connected
	// if not, repeat until they are



	return true; 
}



