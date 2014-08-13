/*
 *
 *  Created on: 14/08/2011
 *      Author: sergio
 */

#include "stats.h"

#ifndef PROBABILITY_H_
#define PROBABILITY_H_



class Probability {
public:
	Probability();
	virtual double* getProbability(tp_mapint delay_fd, int **current_delay, int k) = 0;
};


#endif /* PROBABILITY_H_ */
