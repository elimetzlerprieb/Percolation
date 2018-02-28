#pragma once

class Percolator
{
public:
	Percolator(int size);

	int size;
	std::vector<int> grid;
	int convertCoordinatesToIndex(int row, int column); 

	void openSite(int row, int column);
	bool isSiteOpen(int row, int column);
	
	bool simulate();

private:

};



