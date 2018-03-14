#include "stdafx.h"


Percolator::Percolator(int input_size) : grid(input_size * input_size, 1), weightedUF(input_size * input_size + 2)
{
	size = input_size;
	top = input_size * input_size;
	bottom = input_size * input_size + 1;
	openedSites = 0;
}

void Percolator::reset()
{
	for (int i = 0; i < (size * size); i++)
	{
		grid[i] = 1;
	}

	openedSites = 0;

	weightedUF.reset();
}

int Percolator::convertCoordinatesToGridIndex(int row, int column)
{
	return (row * size + column);
}

void Percolator::openSite(int row, int column)
{
	int index = convertCoordinatesToGridIndex(row, column);
	openSite(index);
	return;
}

void Percolator::outputGridToConsole()
{
	for (int i = 0; i < size * size; i++)
	{
		if ((i % size) == 0)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << grid[i]; 
		}
	}
	std::cout << std::endl;
}

void Percolator::openSite(int index)
{
	if (grid[index] == 0)
	{
		return;
	}
	else
	{
		grid[index] = 0;
		openedSites++;
		return; 
	}
}

bool Percolator::isSiteOpen(int row, int column)
{
	int index = convertCoordinatesToGridIndex(row, column);
	return isSiteOpen(index);
}

bool Percolator::isSiteOpen(int index)
{
	if (index < 0 || index >= (size * size))
	{
		return false; 
	}
	else if (grid[index] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Percolator::joinSiteToAdjacentOpenSites(int row, int column)
{
	int index = convertCoordinatesToGridIndex(row, column);
	return;
}

void Percolator::joinSiteToAdjacentOpenSites(int index)
{
	int up = -1;
	int down = -1;
	int right = -1;
	int left = -1;
	
	if (index < size)
	{
		up = top;
		weightedUF.join(index, up);
	}
	else
	{
		up = index - size;
	}

	if (index >= (size * size - size))
	{
		down = bottom;
		weightedUF.join(index, down);
	}
	else
	{
		down = index + size;
	}

	if ((index % size) == 0)
	{
		left = -1;
	}
	else
	{
		left = index - 1;
	}

	if ((index % (size - 1)) == 0)
	{
		right = -1;
	}
	else
	{
		right = index + 1;
	}

	if (isSiteOpen(up) == true)
	{ 
		weightedUF.join(index, up); 
	}
	if (isSiteOpen(down) == true)
	{
		weightedUF.join(index, down);
	}
	if (isSiteOpen(right) == true)
	{ 
		weightedUF.join(index, right); 
	}
	if (isSiteOpen(left) == true)	
	{ 
		weightedUF.join(index, left); 
	}

	return;
}

int Percolator::simulate()
{
	this->reset();
	
	bool percolated = false;

	while (percolated != true)
	{
		// randomly select a site and open it up if it isn't open already 
		int randomSite = ((std::rand()*std::rand()) % (size * size)); // pick a random cell 
		openSite(randomSite);

		// check to see if any adjacent sites are already open
		joinSiteToAdjacentOpenSites(randomSite);

		// check to see if the top and bottom are connected
		percolated = weightedUF.connected(top, bottom);	

		//outputGridToConsole();
		int breakpt = 32700;
		if (openedSites == breakpt)
		{
			continue;
		}
	}
	return openedSites; 
}

bool Percolator::runNSimulations(int n)
{
	for (int i = 0; i < n; i++)
	{
		simulate();
	}

	return true;
}



