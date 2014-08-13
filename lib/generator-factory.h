/*
 * generator-factory.h
 *
 *  Created on: 21/08/2011
 *      Author: sergio
 */

#include "generator.h"
#include "lottery.h"

#ifndef GENERATOR_FACTORY_H_
#define GENERATOR_FACTORY_H_

class GeneratorFactory {
public:
	GeneratorFactory(Lottery* lottery);
	Generator* createPFBased();
	Generator* createRndBased();
	Generator* createPatternBased();
	Generator* createRndPatternBased();
private:
	Lottery* lottery_;
};

#endif /* GENERATOR_FACTORY_H_ */
