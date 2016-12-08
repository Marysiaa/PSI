/*
 * KohenenNetwork.h
 *
 *  Created on: Dec 4, 2016
 *      Author: maria
 */

#ifndef KOHONENNETWORK_H_
#define KOHONENNETWORK_H_

#include "KohonenNeuron.h"
#include<math.h>

class KohonenNetwork
{
public:

	KohonenNeuron * neurons;
	int size_of_input, amount_of_neurons;

	KohonenNetwork(int size_of_input, int amount_of_neurons)
	{
		this->size_of_input = size_of_input;
		this->amount_of_neurons = amount_of_neurons;

		neurons = new KohonenNeuron[amount_of_neurons];
		for(int i  = 0; i< amount_of_neurons; i++)
		{
			neurons[i].init(size_of_input);
		}
	}

	double * ask_for_outputs(double * input)
	{
		double min;
		int id_min;

		normalize_vector(input);

		double * outputs = new double[amount_of_neurons];

		outputs[0] = neurons[0].ask(input);
		min = outputs[0];
		id_min = 0;

		for(int i=1; i< amount_of_neurons; i++)
		{
			outputs[i] = neurons[i].ask(input);
			if(outputs[i] < min)
			{
				min = outputs[i];
				id_min = i;
			}
		}
		for(int i=0; i< amount_of_neurons; i++)
		{
			if(i == id_min)
				outputs[i] = 1;
			else
				outputs[i] = 0;
		}
		return outputs;
	}

	int get_winner(double * input)
	{
		int winner = 0;
		double tmp, min ;

		tmp = neurons[0].get_euclidean_length(input);
		min = tmp;

		for(int i=1; i< amount_of_neurons; i++)
		{
			tmp = neurons[i].get_euclidean_length(input);
			if(tmp < min)
			{
				min = tmp;
				winner = i;
			}
		}
		return winner;
	}

	void normalize_vector(double * vector)
	{
		int size_of_vector = size_of_input;
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

	// ----------------- WTA - Winner Take All -----------------
	void learn_WTA(double * input)
	{
		normalize_vector(input);

		int winner = get_winner(input);
		neurons[winner].learn_WTA(input);
		normalize_vector(neurons[winner].weights);
	}


	// ----------------- WTM - Winner Take Most -----------------
	void learn_WTM(double *input, int promien_sasiedztwa)
	{

	}

};

#endif /* KOHONENNETWORK_H_ */
