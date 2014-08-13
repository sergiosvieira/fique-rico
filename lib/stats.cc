/*
 * fique-rico.cc
 *
 *  Created on: 12/08/2011
 *      Author: sergio
 */

#include "stats.h"
#include "probability.h"
#include "probability-factory.h"
#include "utils.h"
#include <cstdio>

Stats::Stats() {
	probability = NULL;
}

int* Stats::getFrequency(Lottery *lottery) {
	lottery->print_all();
	int *result = new int[lottery->getM()];
	memset(result, 0, lottery->getM() * sizeof(int));

	Game *game = NULL;

	while ((game = lottery->getNext()) != NULL) {
		int value;
		while ((value = game->getNumbers()->getNext()) != -1) {
			result[value - 1]++;
		}
	}

	return result;
}

int** Stats::getHistoryDelay(Lottery *lottery, int k) {
	int m_ = lottery->getM();
	int size_ = k;

	int **result = new int*[size_];
	for (int i = 0; i < size_; i++) {
		result[i] = new int[m_];
	}
	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < m_; j++) {
			result[i][j] = 0;
		}
	}

	Game *game = NULL;

	int game_counter = 0;

	while ((game = lottery->getNext()) != NULL && game_counter < k) {
		int value;

		for (int j = 0; j < m_; j++) {
			if (game_counter > 0) {
				result[game_counter][j] += result[game_counter - 1][j] + 1;
			} else {
				result[game_counter][j] += 1;
			}
		}

		while ((value = game->getNumbers()->getNext()) != -1) {
			result[game_counter][value - 1] = 0;
		}

		game_counter++;
	}

	return result;
}

int* Stats::getMaxDelay(Lottery *lottery, int k) {
	int *result = new int[lottery->getM()];
	memset(result, 0, lottery->getM() * sizeof(int));

	int **history = getHistoryDelay(lottery, k);

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < lottery->getM(); j++) {
			if (result[j] < history[i][j]) {
				result[j] = history[i][j];
			}
		}
	}

	return result;
}

tp_mapint Stats::getDelayHistogram(Lottery *lottery, int k) {
	tp_mapint result;

	int **history = getHistoryDelay(lottery, k);

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < lottery->getM(); j++) {
			if (result.find(j) != result.end()) {
				result[j][history[i][j]] += 1;
			} else {
				result[j][history[i][j]] = 1;
			}
		}
	}

	return result;
}


map<double, double> Stats::getProbabilityFrequency(Lottery *lottery, int start,
		int precision) {
	map<double, double> result;
	ProbabilityFactory pf;
	Probability* fd = pf.createFDBased();
	double *p;
	for (int i = start; i < lottery->getSize(); i++) {
		tp_mapint map_ = getDelayHistogram(lottery, i);

		int **delay_ = getHistoryDelay(lottery, i);
		p = fd->getProbability(map_, delay_, i);

		for (int j = 0; j < lottery->getM(); j++) {
			double index = setprecision(p[j], precision);
			if (result.find(index) != result.end()) {
				result[index] += 1.0;
			} else {
				result[index] = 1.0;
			}
		}
	}

	//printd(p, lottery->getM());

	return result;
}

double* Stats::getProbability(Lottery* lottery, int start) {
	if (probability == NULL) {
		probability = new double[lottery->getM()];
		ProbabilityFactory pf;
		Probability* fd = pf.createFDBased();
		tp_mapint mapdelay_ = getDelayHistogram(lottery, start);
		int **delay_ = getHistoryDelay(lottery, start);
		probability = fd->getProbability(mapdelay_, delay_, start);
	}

	return probability;
}

void Stats::setNullProbability() {
	probability = NULL;
}
