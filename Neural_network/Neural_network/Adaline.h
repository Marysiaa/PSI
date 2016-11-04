/*
 * Adaline.h
 *
 *      Author: maria
 */

#ifndef ADALINE_H
#define ADALINE_H

// Adaline - neuron implementujacy regule delty

#include<math.h>
#include<stdlib.h>

class Adaline
{
private:
	double * weight;
	Adaline ** input;
	int size;
	double w_0;
	double mistake;

public:
	double learn_number;
	double output, wanted_out;

	Adaline() {
//		learn_number = 0.6;

	}
	Adaline(int size, Adaline * adaline)
	{
		learn_number = 0.6;
		this->size = size;

		weight = new double[size];
		initialize_weight();

		input = new Adaline *[size];
		for (int i = 0; i < size; i++)
		{
			input[i] = &adaline[i];
		}
		output = -1;
	}
	Adaline(int size, Adaline ** adaline)
	{
		learn_number = 0.6;
		this->size = size;

		weight = new double[size];
		initialize_weight();

		input = new Adaline *[size];
		for (int i = 0; i < size; i++)
		{
			input[i] = adaline[i];
		}
		output = -1;
	}

	~Adaline()
	{
		if (weight)
			delete[] weight;
	}

	void ask()
	{
		mistake = 0;

		double s = 0;
		s += w_0;
		for (int i = 0; i < size; i++)
		{
			s += (weight[i] * input[i]->output);
		}

		double result = activation_function(s);
		output = result;
	}

	void learn_first(double wanted_out)		// pierwszy neuron
	{
		mistake = wanted_out -  output;
		for(int i =0; i< size; i++)
		{
			input[i]->mistake += mistake * weight[i];
		}

		mistake_function_set_weights();
	}

	void learn_next()						// pozostale neurony - tylko przekazuja wagi
	{
		for(int i =0; i< size; i++)
		{
			input[i]->mistake += mistake * weight[i];
		}

		mistake_function_set_weights();
	}

	void mistake_function_set_weights()		//ustwaianie wag
	{
		w_0 += mistake * learn_number * pochodna_activation_function(output);

		for (int i = 0; i < size; i++)
		{
//			weight[i] += (learn_number * mistake * pochodna_funkcji_aktywacji_po_outpucie * input[i]);
			weight[i] += (learn_number * mistake * pochodna_activation_function(output) * input[i]->output );
		}
	}

	//TODO
	Adaline & operator = (Adaline & p1)
	{
		this->input = p1.input;
		this->weight = p1.weight;
		this->size = p1.size;
		this->output = p1.output;
		this->w_0 = p1.w_0;
		this->learn_number = p1.learn_number;

		return *this;
	}

private:
	double activation_function(double s)
	{
		double result, beta = 0.6;
		result = 1 / (1 + exp(-beta * s));

		return result;
	}

	double pochodna_activation_function(double x)
	{
		double result = activation_function(x) * ( 1 - activation_function(x) );
		return result;
	}

	void initialize_weight()
	{
		w_0 = (double)rand() / (double)RAND_MAX;		// [0,...,1]
		for (int i = 0; i < size; i++)
		{
			weight[i] = (double)rand() / (double)RAND_MAX;
		}
	}

};

#endif
