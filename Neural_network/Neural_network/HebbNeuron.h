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
	//HebbNeuron ** input;
	HebbNeuron * input;
	int size;
	double w_0;

	double learn_number;
	double output;

	HebbNeuron(){}

	HebbNeuron(int size, HebbNeuron * hebb_neuron){
		learn_number = 0.6;
		this->size = size;

		weight = new double[size];
		initialize_weight();

		input = new HebbNeuron [size];
		for (int i = 0; i < size; i++)
		{
			input[i] = hebb_neuron[i];
		}
		output = -1;
	}

	~HebbNeuron()
	{
		if (weight)
			delete[] weight;
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
		double alfa = 0.6;
		double result = 1.0 / (1.0 + exp((-alfa) * s));
		return result;
	}

	void ask()
	{
		double s = w_0;
		for(int i = 0; i < size; i++)
			s += weight[i] * input[i].output;

		//output = activation_function(s);
		output = s;
	}

	void learn(double d)
	{
		for(int i = 0; i < size; i++)
			weight[i] += learn_number * d * input[i].output;
		w_0 += learn_number * d;
	}

	void learn()
	{
		for(int i = 0; i < size; i++)
			weight[i] += learn_number * output * input[i].output;
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
