/*
 * fd-based.cc
 *
 *  Created on: 14/08/2011
 *      Author: sergio
 */

#include "fd-based.h"
#include "utils.h"
#include <cstdio>

FDBased::FDBased() {

}

double *FDBased::getProbability(tp_mapint delay_fd, int **current_delay, int k) {
	double* result = new double[delay_fd.size()];
	int size = delay_fd.size();

	for (int i = 0; i < size; i++) {
		int first = delay_fd[i][0];
		int next = 0;

		int next_index = current_delay[k - 1][i] + 1;

		int size = delay_fd[i].size();

		for (int j = next_index; j < size; j++) {
			next += delay_fd[i][j];
		}

		/*
		if (next_index < size - 1) {
			next = delay_fd[i][next_index];
		} else {
			next = first;
		}
		*/
		result[i] = 1.0 - (double(first) / double(first + next));

		//printf("first: %d next: %d next_index: %d size: %d result:%.2f\n", first, next, next_index, delay_fd[i].size(), result[i]);

	}

	//printd(result, size);

	return result;
}

