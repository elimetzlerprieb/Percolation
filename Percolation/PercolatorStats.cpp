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

	std::vector<float> threshold(trials, 0);

	for (int i = 0; i < trials; i++)
	{	
		int rc = percolator.simulate();
		threshold[i] = float(rc) / (size * size);
	}

	float val = 0.00;

	for (int i = 0; i < trials; i++)
	{
		val += threshold[i];
	}
	resultsMean = val / trials;


	val = 0.00;

	for (int i = 0; i < trials; i++)
	{
		val += std::pow((threshold[i] - resultsMean), 2);	
	}
	resultsStddev = std::sqrt((val / trials));


	val = (1.96 * resultsStddev) / (std::sqrt(trials));

	resultsConfidenceHi = resultsMean + val;
	resultsConfidenceLo = resultsMean - val; 
}

void PercolatorStats::calculateStats()
{

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