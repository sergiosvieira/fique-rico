/*
 * transfer-function.cc
 *
 *  Created on: 26/07/2011
 *      Author: sergio
 */

#include "transfer-function.h"
#include <cstdio>

TransferFunction::TransferFunction() {
}

TransferFunction::~TransferFunction() {
}

double TransferFunction::get_result(double value) {
	return 0.0;
}

double StepFunction::get_result(double value) {
	return (value <= 0.0) ? 0.0 : 1.0;
}


