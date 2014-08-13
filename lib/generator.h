/*
 * generator.h
 *
 *  Created on: 15/08/2011
 *      Author: sergio
 */


#ifndef GENERATOR_H_
#define GENERATOR_H_

#include "game.h"

class Generator {
public:
	virtual Numbers** generate(int draw_start, int num_games) = 0;
};

#endif /* GENERATOR_H_ */
