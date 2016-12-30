/*
 * HopfieldTest.h
 *
 *  Created on: Dec 12, 2016
 *      Author: maria
 */

#ifndef HOPFIELDTEST_H_
#define HOPFIELDTEST_H_

#include"KohonenNetwork.h"

class HopfieldTest
{
public:
	HopfieldNetwork * network;
	int size_of_input;

	HopfieldTest(int size_of_input)
	{
		this->size_of_input = size_of_input;
		network = new HopfieldNetwork(size_of_input);
	}

	~HopfieldTest() { }

	void set_input(int amount_of_input_vetors, double **input)
	{
		network->set_input(amount_of_input_vetors, input);
	}

	void print_weights()
	{
		cout << endl;
		for(int i=0; i< size_of_input; i++)
		{
			for(int j=0; j< size_of_input; j++)
			{
				cout << network->weights[i][j] << " \t ";
			}
			cout << endl;
		}
		cout << endl;
	}

	void ask_network(double *ask_input)
	{
		for(int i=0; i< size_of_input; i++)
			network->ask_neuron(i, ask_input);
	}

	void learn_network()
	{
		network->learn_with_hebb_method();
	}

};

#endif /* HOPFIELDTEST_H_ */
