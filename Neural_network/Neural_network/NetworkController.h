#ifndef NETWORK_CONTROLLER_H
#define NETWORK_CONTROLLER_H

#include<string>
#include <sstream>

#include"Perceptron.h"

using namespace std;

class NetworkController
{
private:
	Perceptron ** perceptrons;
	int amount_of_lays;
	int * size_of_lay;

public:
	NetworkController(int amount_of_lays , int * size_of_lay)
	{
		this->amount_of_lays = amount_of_lays;

		this->size_of_lay = new int[amount_of_lays];
		for (int i = 0; i < amount_of_lays; i++)
		{
			this->size_of_lay[i] = size_of_lay[i];
		}

		initialize_network();
	}

	~NetworkController()
	{
		if (size_of_lay)
			delete [] size_of_lay;
		if (perceptrons)
		{
			for (int i = 0; i < amount_of_lays; i++)
				delete[] perceptrons[i];
			delete [] perceptrons;
		}

	}

private:
	void initialize_network()
	{
		perceptrons = new Perceptron*[amount_of_lays];
		for (int i = 0; i < amount_of_lays; i++)
		{
			perceptrons[i] = new Perceptron[size_of_lay[i]];
			for (int j = 0; j < size_of_lay[i]; j++)
			{
				Perceptron * tmp_perceptron = NULL;
				if (i != 0)
					tmp_perceptron = new Perceptron(size_of_lay[i - 1], perceptrons[i - 1]);
				else
					tmp_perceptron = new Perceptron(0, NULL);
				perceptrons[i][j] = *tmp_perceptron;
			}
		}

	}

public:
	void put_input(double * input)
	{
		for (int i = 0; i < size_of_lay[0]; i++)
		{
			perceptrons[0][i].output = input[i];
		}
	}

	string ask_network() 
	{
		for (int i = 1; i < amount_of_lays; i++)
		{
			for (int j = 0; j < size_of_lay[i]; j++)
			{
				perceptrons[i][j].ask();
			}
		}
		
		string result;
		for (int i = 0; i < size_of_lay[amount_of_lays - 1]; i++)
		{
			ostringstream strs;
			strs << perceptrons[amount_of_lays - 1][i].output;
			result += strs.str();
			result += " ";
		}

		return result;
	}

	void learn_network(double * wanted_out, double learn_number)
	{
		ask_network();

		for (int i = 0; i < size_of_lay[amount_of_lays - 1]; i++)
		{
				perceptrons[amount_of_lays -1][i].learn(wanted_out[i], learn_number);
		}
	}

};

#endif
