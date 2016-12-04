/*
 * KohenNeuron.h
 *
 *  Created on: Dec 2, 2016
 *      Author: maria
 */

#ifndef KOHENNEURON_H_
#define KOHENNEURON_H_

#include<math.h>
#include<stdlib.h>

class KohenNeuron
{
public:
	double * weights, * input;
	double w_0, learn_number, output, zapominanie;
	int size;


};

#endif /* KOHENNEURON_H_ */
