/*
 * HopfieldNeuron.h
 *
 *  Created on: Dec 12, 2016
 *      Author: maria
 */

#ifndef HOPFIELDNEURON_H_
#define HOPFIELDNEURON_H_

#include<math.h>
#include<stdlib.h>

class HopfieldNeuron
{
public:

	double output, old_output;
	int number_of_neurons;

	HopfieldNeuron() { }

	void init(int number_of_neurons)
	{
		old_output = 0;
		this->number_of_neurons = number_of_neurons;
	}

	~HopfieldNeuron(){}
};

#endif /* HOPFIELDNEURON_H_ */
