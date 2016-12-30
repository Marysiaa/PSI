/*
 * HopfieldNewtork.h
 *
 *  Created on: Dec 12, 2016
 *      Author: maria
 */

#ifndef HOPFIELDNEWTORK_H_
#define HOPFIELDNEWTORK_H_

#include"HopfieldNeuron.h"

class HopfieldNetwork
{
public:
	HopfieldNeuron * neurons;
	int size_of_input, number_of_neurons, amount_of_input_vetors;
	double ** weights, **input;


	HopfieldNetwork( int size_of_input)
	{
		this->size_of_input = size_of_input;
		this->number_of_neurons = size_of_input;

		neurons = new HopfieldNeuron[number_of_neurons];
		weights = new double *[number_of_neurons];

		for(int i = 0; i <number_of_neurons; i++)
			weights[i] = new double [number_of_neurons];

		initialize_weights();

		for(int i=0; i< number_of_neurons; i++)
			neurons[i].init(number_of_neurons);



	}

	~HopfieldNetwork()
	{
		if (neurons)
			delete[] neurons;
	}

	void set_input(int amount_of_input_vetors, double **set_input)
	{
		this->amount_of_input_vetors = amount_of_input_vetors;

		input = new double* [amount_of_input_vetors];
		for(int i = 0; i < amount_of_input_vetors; i++)
			input[i] = new double [size_of_input];

		for(int i = 0; i < amount_of_input_vetors; i++)
		{
			for (int j = 0; j < size_of_input; j++)
			{
				input[i][j] = set_input[i][j];
			}
		}
	}

	void ask_neuron(int neuron_number, double * ask_input)
	{
		double s;
		for (int j = 0; j < number_of_neurons; j++)
		{
			s += ((weights[neuron_number][j] * neurons[j].old_output) + ask_input[neuron_number]);

			activation_function(s, neuron_number);
			cout << neurons[neuron_number].output << "\t";
		}
		cout << endl;
	}

	void activation_function(double s, int neuron_number)
	{
		if(s < 0)
			neurons[neuron_number].output = 1.0;
		else if(s == 0)
			neurons[neuron_number].output = neurons[neuron_number].old_output;
		else if (s < 0)
			neurons[neuron_number].output = -1.0;
	}

	void learn_with_hebb_method()
	{
		double factor = (1.0 / number_of_neurons);
		for(int i = 0; i < number_of_neurons; i++)
		{
			for (int j = 0; j < number_of_neurons; j++)
			{
				//k - number of learn vector
				if(i != j){
					for(int k = 0; k < amount_of_input_vetors; k++)
					{
						weights[i][j] += input[k][i]*input[k][j];
					}
					weights[i][j] *= factor;
				}
				else
					weights[i][j] = 0;
			}
		}
	}

	void initialize_weights()
	{
		for (int i = 0; i < number_of_neurons; i++)
		{
			for (int j = 0; j < number_of_neurons; j++)
			{
				weights[i][j] = (double)rand() / (double)RAND_MAX;
			}
		}
	}


	/*
	void learn(double * input)
	{
		int id = get_neuron_to_change();
		neurons[id].learn_hebb_method(input);
	}

	int get_neuron_to_change()
	{
		int lowest = 0, highest = number_of_neurons;
		int range=(highest-lowest);
		int random_integer = lowest + rand() % range;

		return random_integer;
	}
	*/

};

#endif /* HOPFIELDNEWTORK_H_ */
