/*
 * pattern-based.cc
 *
 *  Created on: 24/08/2011
 *      Author: sergio
 */

#include "pattern-based.h"
#include "utils.h"

#include <cstdio>

PatternBased::PatternBased(Lottery *lottery) {
	lottery_ = lottery;
	next_game_probability_ = NULL;
	aux = NULL;
}

Numbers** PatternBased::generate(int max_numbers, int num_games) {
	int precision = 2;
	//if (aux == NULL) {
	calc(max_numbers, precision);
	//}
	Numbers** result = new Numbers*[num_games];
	for (int i = 0; i < num_games; i++) {
		result[i] = new Numbers();
	}

	int count = 0;

	RandomInitialise(good_seed(), good_seed());
	Numbers tmp;
	while (count < num_games) {
		int* guess = roulette(aux, lottery_->getN(), lottery_->getM());
		qsort(guess, lottery_->getN(), sizeof(int), compare);
		tmp.setNumbers(guess, lottery_->getN());
		if ((!lottery_->find(&tmp)) && (lottery_->findPattern(&tmp))) {
			result[count]->setNumbers(guess, lottery_->getN());
			double fit = fitness(probability_frequency_, 5, result[count],
					lottery_, max_numbers, precision);
			result[count]->setFitness(fit);
			count++;
		}
	}

	return result;
}

void PatternBased::calc(int draw_start, int precision) {
	probability_frequency_ = stats_.getProbabilityFrequency(lottery_,
			draw_start, precision);
	/*
	for (map<double, double>::iterator it = probability_frequency_.begin(); it
			!= probability_frequency_.end(); it++) {
		printf("%.4f %.4f\n", (*it).first, (*it).second);
	}
	*/
	next_game_probability_ = stats_.getProbability(lottery_, draw_start);
	aux = warmup(probability_frequency_, next_game_probability_,
			lottery_->getM(), precision);

}
