/*
 * pattern-based.h
 *
 *  Created on: 24/08/2011
 *      Author: sergio
 */

#include "generator.h"
#include "game.h"
#include "lottery.h"
#include "stats.h"
#include <map>

#ifndef PATTERN_BASED_H_
#define PATTERN_BASED_H_

class PatternBased : public Generator {
public:
	PatternBased(Lottery *lottery);
	Numbers** generate(int draw_start, int num_games);
private:
	void calc(int draw_start, int precision);
	//bool find(Numbers** numbers, int total, Numbers* n, int size);
	std::map<double, double> probability_frequency_;
	double* next_game_probability_;
	double* aux;
	Stats stats_;
	Lottery* lottery_;
};

#endif /* PATTERN_BASED_H_ */
