/*
 * rnd-based-pattern.h
 *
 *  Created on: 24/08/2011
 *      Author: sergio
 */

#include "generator.h"
#include "game.h"
#include "lottery.h"
#include "stats.h"
#include <map>

#ifndef RND_BASED_PATTERN_H_
#define RND_BASED_PATTERN_H_

class RndPatternBased : public Generator {
public:
	RndPatternBased(Lottery *lottery);
	Numbers** generate(int draw_start, int num_games);
private:
	//bool find(Numbers** numbers, int total, Numbers* n, int size);
	Lottery* lottery_;
};

#endif /* RND_BASED_PATTERN_H_ */
