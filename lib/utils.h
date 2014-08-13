/*
 * utils.h
 *
 *  Created on: 14/08/2011
 *      Author: sergio
 */

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <fstream>
#include "randomlib.h"
#include "stats.h"

#ifndef UTILS_H_
#define UTILS_H_

bool value_comparer(map<double, double>::value_type &i1,
		map<double, double>::value_type &i2);
double setprecision(double x, int prec);
double fitness(map<double, double> map_, int rows, Numbers* numbers,
		Lottery *lottery, int start, int precision);
unsigned int good_seed();
void normalize(double *u, int k);
int* roulette(double probability[], int size, int size_);
double* warmup(map<double, double> pf, double* pg, int k, int precision);
int compare(const void * a, const void * b);
void print(int u[], int m);
void print_(int **u, int rows, int cols);
void printd(double u[], int m);
void print_map(tp_mapint *u);
Numbers* pattern(Numbers* n);

#endif /* UTILS_H_ */
