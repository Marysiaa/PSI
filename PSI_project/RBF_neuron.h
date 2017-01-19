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
	double output;
	int size_of_input, K;
	double *c, sigma, d, learn_number;

public:
	double mistake;
	double * weights, w_0, bias;

	RBF_neuron(){}
	~RBF_neuron(){}

	void init(int size_of_input)
	{
		learn_number = 0.6;
		bias = 1;
		this->size_of_input = size_of_input;
		weights = new double[size_of_input];
		initialize_weight();

		this->K = size_of_input;
		this->c = new double[K];

		set_random_center(c);
		set_max_d();
		set_sigma();
	}

	double ask(double * input)
	{
		double result, dist = 0, tmp_dist = 0;
//		double  sum = 0;
		for(int i=0; i< size_of_input; i++)
		{
//			sum += (weights[i] * input[i]);
			tmp_dist += ((weights[i] - input[i])*(weights[i] - input[i]));
		}
		dist = sqrt(tmp_dist);
		dist *= (bias*w_0);

		result = extend_gauss_function(dist);
//		result = radbas(dist);
		output = result;
		return result;
	}

//----------------------------------------------------
	void correct_weights(double * input)
	{
		for(int i = 0 ; i< size_of_input; i++)
		{
			weights[i] += (learn_number * mistake * input[i] * function(input[i]) );
//			weights[i] += (learn_number * mistake * input[i] * pochodna_radbas(input[i]) );
		}
		normalize_vector(weights, size_of_input);
	}

	double * get_centers()
	{
		return c;
	}

	double * get_weights()
	{
		return weights;
	}

private:

	double function(double x)
	{
		double r_tmp = 0, result = 0, r = 0;
		for(int j = 0; j < K; j++)
		{
			r_tmp += ((x - c[j])*(x - c[j]));
		}
		r = sqrt(r_tmp);
		result = ((r_tmp / (r * 2*sigma*sigma))) * exp( (- r*r) / (2*sigma*sigma) ) ;
		return result;
	}

	void set_random_center(double * c)
	{
		for(int i =0; i< K; i++)
		{
			c[i] = ((double)rand() / (double)RAND_MAX);
//			c[i] = ((double)rand() / (double)RAND_MAX)*2 - 1;
		}
	}

	void set_max_d()
	{
		double d_tmp = 0.0;
		for(int i = 0; i < K; i++)
		{
			if(i != K-1)
				d_tmp = bezwzgledna(c[i] - c[i+1]);
			else
				d_tmp = bezwzgledna(c[i] - c[0]);

			if(d_tmp > d)
				d = d_tmp;
		}
//		cout << "\t max odleglosc miedzy centrami: " << d_tmp << endl;
	}

	void set_sigma()
	{
		sigma = d / sqrt(2*K*K);
	}

	double radbas(double x)
	{
		return (exp(- x * x));
	}

	double pochodna_radbas(double x)
	{
		return (-2.0 * x * exp(- x * x));
	}

	double extend_gauss_function(double x)
	{
		double result = 0, r = 0, tmp_r = 0, potega = 0;

		// || x - c || = sqrt( (x_j - c_j)^2 + ... + (x_i - c_i)^2 )
		for(int j = 0; j < K; j++)
		{
			tmp_r += ((x - c[j])*(x - c[j]));
		}
		r = sqrt(tmp_r);
		potega = ((- r*r ) / 2*sigma*sigma) ;
		result += exp(potega);

//		cout << "rbf : " << result << endl;
		return result;
	}

	double extend_gauss_function(double * x)
	{
		// d - max odleglosc miedzy centrami
		// K - ilosc centrow
		// x - wejscie
		// c - centra

		double result = 0, tmp = 0, norma;

		for(int i = 0; i < size_of_input; i++)
		{
			for(int j = 0; j < K; j++)
			{
				norma = sqrt((x[i] - c[j])*(x[i] - c[j]));
				tmp = ((- norma*norma) / ((d*d)) / (double)K) ;
				result += exp(tmp);
			}
		}
//		cout << "rbf : " << result << endl;
		return result;
	}

	double bezwzgledna( double x)
	{
		if(x < 0)
			x *= (-1.0);
		return x;
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
		w_0 = (double)rand() / (double)RAND_MAX;
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

#endif /* RBF_NEURON_H_ */
