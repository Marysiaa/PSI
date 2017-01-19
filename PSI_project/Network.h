/*
 * Network.h
 *
 *  Created on: Dec 10, 2016
 *      Author: maria
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#include"RBF_neuron.h"
#include"Linear_neuron.h"
#include<math.h>

using namespace std;

class Network
{
private:
	int size_of_input, size_of_rbf_layer, size_of_linear_layer;
public:
	RBF_neuron * rbf_layer;
	Linear_neuron * linear_layer;

public:
	Network()
	{

	}
	~Network()
	{
		if (rbf_layer)
			delete[] rbf_layer;
		if (linear_layer)
			delete[] linear_layer;
	}

	void initialize_netowrk(
			int size_of_input,
			int size_of_rbf_layer,
			int size_of_linear_layer)
	{
		this->size_of_input= size_of_input;
		this->size_of_rbf_layer = size_of_rbf_layer;
		this->size_of_linear_layer = size_of_linear_layer;

		rbf_layer = new RBF_neuron[size_of_rbf_layer];
		for(int i =0; i<size_of_rbf_layer; i++)
		{
			rbf_layer[i].init(size_of_input);
		}

		linear_layer = new Linear_neuron[size_of_linear_layer];
		for(int i =0; i<size_of_linear_layer; i++)
		{
			linear_layer[i].init(size_of_rbf_layer);
		}
	}

	double ask_network(double * input)
	{
		double * network_out = new double[size_of_linear_layer];
		double * rbf_outs = new double[size_of_rbf_layer];
		double * linear_outs = new double[size_of_linear_layer];

		for(int i =0; i<size_of_rbf_layer; i++)
		{
			rbf_outs[i] = rbf_layer[i].ask(input);
		}
		normalize_vector(rbf_outs, size_of_rbf_layer );
/*
cout << "rbf layer outputs: "<< endl;
for(int i =0; i<size_of_rbf_layer; i++)
	cout << rbf_outs[i] << "\t";
cout << endl;
*/
		for(int i =0; i<size_of_linear_layer; i++)
		{
			linear_outs[i] = linear_layer[i].ask(rbf_outs);
		}
/*
cout << "linear layer outputs: "<< endl;
for(int i =0; i<size_of_linear_layer; i++)
	cout << linear_outs[i] << "\t";
cout << endl << endl;
*/
		for(int i =0; i< size_of_linear_layer; i++)
		{
/*
			if(linear_outs[i] == 1)
			{
				if(network_out != -1)
				{
					cout << "ERROR \nwejscie przydzielone do wiecej niz jednej grupy!" << endl;
					exit(-1);
				}
				network_out = i;
			}
*/
			network_out[i] = linear_outs[i];
		}
		return network_out[0];
	}

	// wykorzystanie wstecznej propagacji
	void learn_network(double * input, int wanted_out)
	{
		double mistake;
		double out = ask_network(input);
		mistake = wanted_out - out;
		linear_layer->mistake = mistake;
		if(mistake != 0)
		{
			for(int i =0; i<size_of_rbf_layer; i++)
			{
				rbf_layer[i].mistake = mistake * linear_layer->weights[i];
			}

			for(int i =0; i<size_of_rbf_layer; i++)
			{
				rbf_layer[i].correct_weights(input);
			}
			for(int i =0; i<size_of_linear_layer; i++)
			{
				linear_layer[i].correct_weights(input);
			}
		}
	}

private:
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

#endif /* NETWORK_H_ */
