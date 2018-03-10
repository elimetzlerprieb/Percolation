#pragma once
#include "WeightedUF.h"

class Percolator
{
public:
	Percolator(int size);

	int size;
	int top;
	int bottom;
	std::vector<int> grid;
	WeightedUF weightedUF;

	int openedSites;

	int convertCoordinatesToGridIndex(int row, int column); 

	void openSite(int row, int column);
	void openSite(int index);
	
	void joinSiteToAdjacentOpenSites(int row, int column);
	void joinSiteToAdjacentOpenSites(int index);

	bool isSiteOpen(int row, int column);
	bool isSiteOpen(int index);

	bool simulate();

	void outputGridToConsole();

private:

};



