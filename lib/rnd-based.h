/*
 * rnd-based.h
 *
 *  Created on: 21/08/2011
 *      Author: sergio
 */

#include "generator.h"
#include "lottery.h"

#ifndef RND_BASED_H_
#define RND_BASED_H_

class RndBased: public Generator {
public:
	RndBased(Lottery* lottery);
	Numbers** generate(int max_numbers, int num_games);
private:
	Lottery* lottery_;
	bool find(Numbers** numbers, int total, Numbers* n, int size);
};

#endif /* RND_BASED_H_ */
