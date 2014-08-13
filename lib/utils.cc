/*
 * utils.cc
 *
 *  Created on: 21/08/2011
 *      Author: sergio
 */

#include "utils.h"

bool value_comparer(map<double, double>::value_type &i1,
		map<double, double>::value_type &i2) {
	return i1.second < i2.second;
}

double setprecision(double x, int prec) {
	return ceil(x * pow(10, (double) prec) - .4999999999999) / pow(10,
			(double) prec);
}

double fitness(map<double, double> map_, int rows, Numbers* numbers,
		Lottery *lottery, int start, int precision) {
	double result = 0.0;

	map<double, double>::iterator itor = std::max_element(map_.begin(),
			map_.end(), value_comparer);
	Stats stats;
	double *p = stats.getProbability(lottery, start);
	int value = 0;
	double ranking[rows];
	double standard = 0.0;

	for (int i = 0; i < rows; i++) {
		ranking[i] = (*itor).first;
		standard += 3.0 * ranking[i];
		if (i % 2 == 0) {
			for (int j = 0; j < (i + 1); j++) {
				itor++;
			}
		} else {
			for (int j = 0; j < (i + 1); j++) {
				itor--;
			}
		}
	}

	int frequency[rows];
	memset(&frequency, 0, sizeof(int) * rows);

	while ((value = numbers->getNext()) != -1) {
		double probability = setprecision(p[value - 1], precision);
		for (int i = 0; i < rows; i++) {
			if (probability == ranking[i]) {
				frequency[i]++;
			}
		}
	}

	for (int i = 0; i < rows; i++) {
		//printf("%d %d %f\n", i, frequency[i], ranking[i]);
		result += frequency[i] * ranking[i];
	}
	result = abs(standard - result);

	return result;
}

unsigned int good_seed() {
	unsigned int random_seed, random_seed_a, random_seed_b;
	std::ifstream file("/dev/urandom", std::ios::binary);
	if (file.is_open()) {
		char * memblock;
		int size = sizeof(int);
		memblock = new char[size];
		file.read(memblock, size);
		file.close();
		random_seed_a = *reinterpret_cast<int*> (memblock);
		delete[] memblock;
	}// end if
	else {
		random_seed_a = 0;
	}
	random_seed_b = std::time(0);
	random_seed = random_seed_a xor random_seed_b;
	//std::cout << "random_seed_a = " << random_seed_a << std::endl;
	//std::cout << "random_seed_b = " << random_seed_b << std::endl;
	//std::cout << " random_seed =  " << random_seed << std::endl;
	return random_seed % 30081;
} // end good_seed()

void normalize(double *u, int k) {
	double total = 0.0;
	for (int i = 0; i < k; i++) {
		total += u[i];
	}
	for (int i = 0; i < k; i++) {
		u[i] /= total;
	}
}

int* roulette(double probability[], int size, int size_) {
	double tmp[size_];
	memcpy(tmp, probability, sizeof(double) * size_);

	int *result = new int[size];

	normalize(tmp, size_);
	for (int i = 0; i < size; i++) {
		double acc = 0.0;
		double r = RandomUniform();
		for (int j = 0; j < size_; j++) {
			acc += tmp[j];
			if (r <= acc) {
				result[i] = j + 1;
				tmp[j] = 0.0;
				normalize(tmp, size_);
				break;
			}
		}
	}
	return result;
}

double* warmup(map<double, double> pf, double* pg, int k, int precision) {
	double* result = new double[k];

	for (int i = 0; i < k; i++) {
		double nv = setprecision(pg[i], precision);
		result[i] = pg[i] * pf[nv];
		//printf("-> %f %f\n", pg[i], pf[nv]);
	}

	return result;
}

int compare(const void * a, const void * b) {
	return (*(int*) a - *(int*) b);
}

void print(int u[], int m) {
	for (int i = 0; i < m; i++) {
		printf("%d %d\n", i + 1, u[i]);
	}
}

void print_(int **u, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		printf("[%d] = [", i + 1);
		for (int j = 0; j < cols; j++) {
			printf("%d", u[i][j]);
			if (j < cols) {
				printf(" ");
			}
		}
		printf("]\n");
	}
}

void printd(double u[], int m) {
	for (int i = 0; i < m; i++) {
		printf("%d %.4f\n", i + 1, u[i]);
	}
}

void print_map(tp_mapint *u) {
	for (tp_mapint::iterator it = u->begin(); it != u->end(); it++) {
		printf("[%d]\n", (*it).first + 1);
		map<int, int> aux = (*it).second;
		for (map<int, int>::iterator jt = aux.begin(); jt != aux.end(); jt++) {
			printf("\t%d %d\n", (*jt).first, (*jt).second);
		}
	}
}

Numbers* pattern(Numbers* n) {
	Numbers* result = new Numbers();
	if (n->getSize() < 2) {
		return result;
	}
	int* aux = new int[n->getSize()];
	int j = 1;
	for (int i = 0; i < n->getSize(); i++) {
		if (i == 0) {
			if (n->getNumbers()[i] == n->getNumbers()[i + 1] - 1) {
				aux[i] = j;
			} else {
				aux[i] = 0;
			}
		} else
		if (i == n->getSize() - 1) {
			if (n->getNumbers()[i] == n->getNumbers()[i - 1] + 1) {
				aux[i] = j;
			} else {
				aux[i] = 0;
			}
		} else {
			if ((n->getNumbers()[i] == n->getNumbers()[i - 1] + 1)
					|| (n->getNumbers()[i] == n->getNumbers()[i + 1] - 1)) {
				aux[i] = j;
			} else {
				aux[i] = 0;
			}
			if ((n->getNumbers()[i] == n->getNumbers()[i - 1] + 1)
					&& (n->getNumbers()[i] != n->getNumbers()[i + 1] - 1)) {
				j++;
			}
		}
	}
	result->setNumbers(aux, n->getSize());
	return result;
}
