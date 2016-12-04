/*
 * HebbNeuron.h
 *
 *  Created on: Nov 14, 2016
 *      Author: maria
 */

#ifndef HEBBNEURON_H_
#define HEBBNEURON_H_

#include<math.h>
#include<stdlib.h>

class HebbNeuron
{
public:
	double * weight;
//	HebbNeuron * input;
	double * input;

	int size;
	double w_0;

	double learn_number;
	double output;

	HebbNeuron(){	}

	void init(int size){
		learn_number = 0.1;
		this->size = size;

		weight = new double[size];
		input = new double[size];

		initialize_weight();
		output = -1;
	}

	~HebbNeuron()
	{
		if (weight)
			delete[] weight;
		if (input)
			delete [] input;
	}

	void initialize_weight()
	{
		w_0 = (double)rand() / (double)RAND_MAX;		// [0,...,1]
		for (int i = 0; i < size; i++)
		{
			weight[i] = (double)rand() / (double)RAND_MAX;
		}
	}

	double activation_function(double s)
	{
//		double result, beta = 0.6;
//		result = 1.0 / (1.0 + exp((-beta) * s));

		double result;
		if(s < 0)	result = -1;
		else	result = 1;

		return result;
	}



	void ask(double * input)
	{
		double s = w_0;
		for(int i = 0; i < size; i++)
			s += weight[i] * input[i];

		activation_function(s);
		output = s;
	}

	void learn(double d, double * input)
	{
		for(int i = 0; i < size; i++)
			weight[i] += learn_number * d * input[i];

		w_0 += learn_number * d;
	}

	void learn(double * input)
	{
		for(int i = 0; i < size; i++)
			weight[i] += learn_number * output * input[i];

		w_0 += learn_number * output;
	}

	HebbNeuron & operator = (HebbNeuron & p1)
	{
		this->input = p1.input;
		this->weight = p1.weight;
		this->size = p1.size;
		this->output = p1.output;
		this->w_0 = p1.w_0;
		this->learn_number = p1.learn_number;

		return *this;
	}
};

#endif /* HEBBNEURON_H_ */
