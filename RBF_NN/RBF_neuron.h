/*
 * RBF_neuron.h
 *
 *  Created on: Dec 6, 2016
 *      Author: maria
 */

#ifndef RBF_NEURON_H_
#define RBF_NEURON_H_

#include <math.h>

class RBF_neuron
{
private:
	double * weights;
	double output, sigma;
	int size_of_input;

public:
	RBF_neuron(){}
	~RBF_neuron()
	{
		if (weights)
			delete[] weights;
	}

	void init(int size_of_input, double sigma)
	{
		this->sigma = sigma;
		this->size_of_input = size_of_input;
		weights = new double[size_of_input];

		initialize_weight();
	}

	double ask(double * input)
	{
//		s = || W - X || * bias
//		a(s) = e^ [- S^2 ]

		double a, s;
		double * diff = new double[size_of_input];

		for(int i =0; i< size_of_input; i++ )
		{
			diff[i] = weights[i] - input[i];
		}
		s = get_vector_length( diff, size_of_input);
//		cout << endl << "bias: "<< bias << "\t s: " << s << endl;
		a = gauss_function(s);

		output = a;
		return a;
	}

	void learn(double * input)
	{

	}

	double * get_weights()
	{
		return weights;
	}

private:
	double gauss_function(double s)
	{
		double result = exp(-(s * s) / (2*sigma*sigma));
//		cout << endl << s << "\tresult: " << result << endl;
		return result;
	}

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

	void initialize_weight()
	{
		for (int i = 0; i < size_of_input; i++){
			weights[i] = (double)rand() / (double)RAND_MAX;
		}
	}



};

#endif /* RBF_NEURON_H_ */
