/*
 * probability-factory.cpp
 *
 *  Created on: 14/08/2011
 *      Author: sergio
 */

#include "probability-factory.h"
#include "fd-based.h"

ProbabilityFactory::ProbabilityFactory() {
}

Probability* ProbabilityFactory::createFDBased() {
	return new FDBased();
}
