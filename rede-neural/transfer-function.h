/*
 * transfer-function.h
 *
 *  Created on: 26/07/2011
 *      Author: sergio
 */

#ifndef TRANSFER_FUNCTION_H_
#define TRANSFER_FUNCTION_H_

class TransferFunction {
public:
	TransferFunction();
	~TransferFunction();
	double get_result(double value);
};

class StepFunction: public TransferFunction {
public:
	double get_result(double value);
};


#endif /* TRANSFER_FUNCTION_H_ */
