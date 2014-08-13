/*
 * read-result.h
 *
 *  Created on: 12/08/2011
 *      Author: sergio
 */

#include "lottery.h"

#ifndef READ_RESULT_H_
#define READ_RESULT_H_

class ReadResult {
public:
	ReadResult();
	Lottery *read(const char *filename, int n, int m);
	Lottery *read(const char *filename, int n, int m, int* matches, int matches_size);
};

#endif /* READ_RESULT_H_ */
