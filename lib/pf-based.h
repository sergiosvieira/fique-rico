/*
 * pf-based.h
 *
 *  Created on: 15/08/2011
 *      Author: sergio
 */

#include "generator.h"
#include "game.h"
#include "lottery.h"
#include "stats.h"
#include <map>

#ifndef PF_BASED_H_
#define PF_BASED_H_

class PFBased : public Generator {
public:
	PFBased(Lottery *lottery);
	Numbers** generate(int max_numbers, int num_games);
private:
	void calc(int draw_start, int precision);
	bool find(Numbers** numbers, int total, Numbers* n, int size);
	std::map<double, double> probability_frequency_;
	double* next_game_probability_;
	double* aux;
	Stats stats_;
	Lottery* lottery_;
};

#endif /* PF_BASED_H_ */

