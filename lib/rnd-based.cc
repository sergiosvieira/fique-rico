/*
 * rnd-based.cc
 *
 *  Created on: 21/08/2011
 *      Author: sergio
 */

#include "rnd-based.h"
#include "utils.h"

RndBased::RndBased(Lottery* lottery) {
	lottery_ = lottery;
}

bool RndBased::find(Numbers** numbers, int total, Numbers* n, int size) {
	for (int i = 0; i < total; i++) {
		if (numbers[i]->match(n) == size) {
			return true;
		}
	}
	return false;
}

Numbers** RndBased::generate(int max_numbers, int num_games) {
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

		if (!lottery_->find(&tmp, lottery_->getMatches(), lottery_->getMatchesSize())) {
			if (!find(result, count, &tmp, lottery_->getN())) {
				result[count]->setNumbers(guess, lottery_->getN());
				count++;
			}
		}
	}

	return result;

}
