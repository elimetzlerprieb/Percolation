// Percolation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	PercolatorStats percolatorStats;
	percolatorStats.run(2, 1000);


	std::cout << "Mean:                 " << percolatorStats.mean() << std::endl;
	std::cout << "Std deviation:        " << percolatorStats.stddev() << std::endl;
	std::cout << "Confidence interval: [" << percolatorStats.confidenceLo() << "," << percolatorStats.confidenceHi() << "]" << std::endl;



	//Percolator percolator(10);
	//percolator.simulate();


	/*
	WeightedUF weightedUF(20);
	weightedUF.join(0, 1);
	weightedUF.join(2, 3);
	weightedUF.join(4, 5);
	weightedUF.join(6, 7);
	weightedUF.join(8, 9);
	weightedUF.join(7, 9);
	weightedUF.join(9, 1);

	int rc;
	rc = weightedUF.find(7);
	rc = weightedUF.find(3);

	bool r;
	r = weightedUF.connected(1, 2);
	r = weightedUF.connected(3, 9);
		
	for (int i = 0; i < weightedUF.getSize(); i++)
	{
		std::cout << i << "," << weightedUF.nodes[i] << "," << weightedUF.depth[i] << std::endl;
	}
	*/
	int get_input = 0;
	std::cin >> get_input;

    return 0;
}

