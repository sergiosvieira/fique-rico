/*
 * probability-factory.h
 *
 *  Created on: 14/08/2011
 *      Author: sergio
 */

#include "probability.h"

#ifndef PROBABILITY_FACTORY_H_
#define PROBABILITY_FACTORY_H_

class ProbabilityFactory {
public:
	ProbabilityFactory();
	Probability* createFDBased();
};

#endif /* PROBABILITY_FACTORY_H_ */
