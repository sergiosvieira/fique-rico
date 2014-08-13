/*
 * fd-based.h
 *
 *  Created on: 14/08/2011
 *      Author: sergio
 */

#include "stats.h"
#include "probability.h"

#ifndef FD_BASED_H_
#define FD_BASED_H_


class FDBased: public Probability {
public:
	FDBased();
	double* getProbability(tp_mapint delay_fd, int **current_delay, int k);
};

#endif /* FD_BASED_H_ */
