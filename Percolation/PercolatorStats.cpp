#include "stdafx.h"

PercolatorStats::PercolatorStats()
{
	resultsMean = 0.00;
	resultsStddev = 0.00;
	resultsConfidenceHi = 0.00;
	resultsConfidenceLo = 0.00;
}

void PercolatorStats::run(int size, int trials)
{
	clearStats();

	Percolator percolator(size);

	std::vector<int> sitesOpened(size, 0);
	
	for (int i = 0; i < trials; i++)
	{
		sitesOpened[i] = percolator.simulate();
	}
}

void PercolatorStats::clearStats()
{
	resultsMean = 0.00;
	resultsStddev = 0.00;
	resultsConfidenceHi = 0.00;
	resultsConfidenceLo = 0.00;
}

double PercolatorStats::mean()
{
	return resultsMean;
}

double PercolatorStats::stddev()
{
	return resultsStddev;
}

double PercolatorStats::confidenceLo()
{
	return resultsConfidenceLo;
}

double PercolatorStats::confidenceHi()
{
	return resultsConfidenceHi;
}

/*
public:
	void model();
	double mean();
	double stddev();
	double confidenceLo();
	double confidenceHi();

private:
	double mean;
	double stddev;
	double confidenceLo;
	double confidenceHi;
*/