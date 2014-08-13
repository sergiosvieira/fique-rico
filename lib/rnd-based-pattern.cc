/*
 * pattern-based.cc
 *
 *  Created on: 24/08/2011
 *      Author: sergio
 */

#include "rnd-based-pattern.h"
#include "utils.h"

#include <cstdio>

RndPatternBased::RndPatternBased(Lottery *lottery) {
	lottery_ = lottery;
}

Numbers** RndPatternBased::generate(int max_numbers, int num_games) {
	Numbers** result = new Numbers*[num_games];
	for (int i = 0; i < num_games; i++) {
		result[i] = new Numbers();
	}

	double aux[lottery_->getM()];

	double total = 1.0 / lottery_->getM();
	for (int i = 0; i < lottery_->getM(); i++) {
		aux[i] = total;
	}

	RandomInitialise(good_seed(), good_seed());

	int count = 0;

	while (count < num_games) {
		int* guess = roulette(aux, lottery_->getN(), lottery_->getM());
		qsort(guess, lottery_->getN(), sizeof(int), compare);
		Numbers tmp;
		tmp.setNumbers(guess, lottery_->getN());

		if ((!lottery_->find(&tmp)) && (lottery_->findPattern(&tmp))) {
			result[count]->setNumbers(guess, lottery_->getN());
			count++;
		}
	}

	return result;
}

