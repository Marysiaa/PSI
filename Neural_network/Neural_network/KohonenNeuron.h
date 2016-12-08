/*
 * KohenNeuron.h
 *
 *  Created on: Dec 2, 2016
 *      Author: maria
 */

#ifndef KOHONENNEURON_H_
#define KOH0NENNEURON_H_

#include<math.h>
#include<stdlib.h>

class KohonenNeuron
{
public:
	double * weights;
	double learn_number, output;
	int size;

	KohonenNeuron(){ }

	void init(int size)
	{
		learn_number = 0.1;
		this->size = size;
		weights = new double[size];
		initialize_weight();
	}

	~KohonenNeuron()
	{
		if (weights)
			delete[] weights;
	}

	void initialize_weight()
	{
		for (int i = 0; i < size; i++){
			weights[i] = (double)rand() / (double)RAND_MAX;
		}
		cout << endl;
	}


	double get_euclidean_length(double *input)
	{
		double tmp = 0.0, length = 0.0;
		for(int i=0; i< size; i++)
			tmp += (input[i] - weights[i]) * (input[i] - weights[i]);

		length = sqrt(tmp);
		return length;
	}

	double ask(double* input)
	{
		return get_euclidean_length(input);
	}

	void learn_WTA(double * input)
	{
		double dif;
		for(int i =0; i< size; i++)
		{
			dif = input[i] - weights[i];
			weights[i] += learn_number * dif;

		}
	}

};

#endif /* KOHONENNEURON_H_ */
