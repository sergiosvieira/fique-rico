/*
 * generator-factory.cpp
 *
 *  Created on: 21/08/2011
 *      Author: sergio
 */

#include "generator-factory.h"
#include "pf-based.h"
#include "rnd-based.h"
#include "pattern-based.h"
#include "rnd-based-pattern.h"

GeneratorFactory::GeneratorFactory(Lottery* lottery) {
	lottery_ = lottery;
}

Generator* GeneratorFactory::createPFBased() {
	Generator* result = NULL;

	result = new PFBased(lottery_);

	return result;
}

Generator* GeneratorFactory::createRndBased() {
	Generator* result = NULL;

	result = new RndBased(lottery_);

	return result;
}

Generator* GeneratorFactory::createPatternBased() {
	Generator* result = NULL;

	result = new PatternBased(lottery_);

	return result;
}

Generator* GeneratorFactory::createRndPatternBased() {
	Generator* result = NULL;

	result = new RndPatternBased(lottery_);

	return result;
}
