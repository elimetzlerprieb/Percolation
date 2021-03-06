#pragma once

class PercolatorStats
{
public:
	PercolatorStats();
	void run(int size, int trials);
	double mean();
	double stddev();
	double confidenceLo();
	double confidenceHi();

private:
	void clearStats();
	void calculateStats();
	double resultsMean;
	double resultsStddev;
	double resultsConfidenceLo;
	double resultsConfidenceHi;
};