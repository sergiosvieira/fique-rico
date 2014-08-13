/*
 * fique-rico.h
 *
 *  Created on: 12/08/2011
 *      Author: sergio
 */

#include "lottery.h"
#include <map>

#ifndef __STATS__
#define __STATS__

typedef map<int, map<int, int> > tp_mapint;

class Stats {
public:
	Stats();
	int *getFrequency(Lottery *lottery);
	int **getHistoryDelay(Lottery *lottery, int k);
	int *getMaxDelay(Lottery *lottery, int k);
	tp_mapint getDelayHistogram(Lottery *lottery, int k);
	map<double, double> getProbabilityFrequency(Lottery *lottery, int start, int precision);
	double* getProbability(Lottery* lottery, int start);
	void setNullProbability();
private:
	double* probability;
};

#endif /* __STATS__ */
