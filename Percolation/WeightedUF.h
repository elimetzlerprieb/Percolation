#pragma once

class WeightedUF
{
public:

	void join(int p_index, int q_index);
	bool connected(int p_index, int q_index); //return true if p and q are connected 
	int count(); // return the number of connected sets
	int find(int p_index); //return the component identify of the set p belongs to 


private:
	std::vector<int> elements; 

};