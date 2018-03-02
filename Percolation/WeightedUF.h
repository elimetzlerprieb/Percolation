#pragma once

class WeightedUF
{
public:
	WeightedUF(int input_size);	

	void join(int p, int q);
	bool connected(int p, int q); //return true if p and q are connected 
	int count(); // return the number of connected sets
	int find(int p); //return the component identify of the set p belongs to 
	
	std::vector<int> nodes; 
	std::vector<int> depth;

	int root(int node);


	int getSize()
	{
		return nodes.size();
	}

};