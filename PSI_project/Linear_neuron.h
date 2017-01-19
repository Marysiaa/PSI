/*
 * Linear_neuron.h
 *
 *  Created on: Dec 8, 2016
 *      Author: maria
 */

#ifndef LINEAR_NEURON_H_
#define LINEAR_NEURON_H_

#include<time.h>
#include<stdlib.h>
#include<math.h>
#include"RozwiazywanieUkladuRownanLiniowych.h"

class Linear_neuron
{
private:
	double bias, w0, learn_number;
	int size_of_input;

public:
	double * weights;
	double mistake;

	Linear_neuron(){}
	~Linear_neuron()
	{
		if (weights)
			delete[] weights;
	}

	void init(int size_of_input)
	{
		learn_number = 0.6;
		bias = 1;
		this->size_of_input = size_of_input;
		weights = new double[size_of_input];

		initialize_weight();
	}

	double ask(double * input)
	{
		double s;
		for(int i=0; i< size_of_input; i++ )
		{
			s += (weights[i] * input[i]);
		}
		s += (bias * w0);
//		cout << endl << "bias: " << bias << "\t w0: "<< w0 << "\t s:" << s << endl;

		return activation_function(s);
	}

//----------------------------------------------------
	void correct_weights(double * input)
	{
		for(int i = 0 ; i< size_of_input; i++)
		{
			weights[i] += (learn_number * mistake * input[i]);
		}
		normalize_vector(weights, size_of_input);
	}

	double * get_weights()
	{
		return weights;
	}

private:

	double get_vector_length(double * vector, int size_of_vector)
	{
		double vector_length = 0;
		for(int i = 0; i < size_of_vector; i++)
		{
			vector_length += (vector[i] * vector[i]);
		}
		vector_length = sqrt(vector_length);

//		cout << endl << "\t vetor_length: " << vector_length << endl;
		return vector_length;
	}

	double activation_function(double s)
	{
		if(s > 0)
			return 1.0;
		else
			return -1.0;
	}

	void initialize_weight()
	{
		for (int i = 0; i < size_of_input; i++){
			weights[i] = (double)rand() / (double)RAND_MAX;
		}
		w0 = (double)rand() / (double)RAND_MAX;
	}

	void normalize_vector(double * vector, int size_of_vector)
	{
		double vector_length = 0;
		for(int i = 0; i < size_of_vector; i++)
		{
			vector_length += (vector[i] * vector[i]);
		}
		vector_length = sqrt(vector_length);

		for(int i = 0; i < size_of_vector; i++)
		{
			vector[i] = (vector[i] / vector_length);
		}
	}
};

#endif /* LINEAR_NEURON_H_ */
