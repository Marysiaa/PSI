/*
 * Classification.h
 *
 *  Created on: Jan 17, 2017
 *      Author: maria
 */

#ifndef CLASSIFICATION_H_
#define CLASSIFICATION_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Classification
{
private:
	Network * network;

	int amount_of_learn_data, amount_of_test_data, amount_of_parameters;
	int size_of_input, size_of_rbf_layer, size_of_linear_layer;

	double ** learn_data, ** test_data;
	int * learn_wanted_outs, * test_wanted_outs;

public:
	Classification(){}
	~Classification(){}

	void classification_init()
	{
		amount_of_learn_data = 49;
		amount_of_test_data = 21;
		amount_of_parameters = 12;

		learn_wanted_outs = new int[amount_of_learn_data];
		test_wanted_outs = new int [amount_of_test_data];

		learn_data = new double *[amount_of_learn_data];
		for(int j = 0; j< amount_of_learn_data; j++)
		{
			learn_data[j] = new double [amount_of_parameters];
		}

		test_data = new double *[amount_of_test_data];
		for(int j = 0; j< amount_of_test_data; j++)
		{
			test_data[j] = new double [amount_of_parameters];
		}

		network = new Network;

		size_of_input = amount_of_parameters;
		size_of_rbf_layer = 5;
		size_of_linear_layer = 1;

		network->initialize_netowrk(size_of_input,size_of_rbf_layer,size_of_linear_layer);

	}

	void read_learn_data()
	{
		string file_name = "dane_uczace.txt";
		ifstream data_file;
		data_file.open (file_name.c_str(), ios::in);

		if ( !data_file.is_open() ){
			cout << "problem with opening file!" << endl;
		}

		for(int i = 0; i< amount_of_learn_data; i++)
		{
			for(int j = 0; j< amount_of_parameters; j++)
			{
				data_file >> learn_data[i][j];
			}
			data_file >> learn_wanted_outs[i];
		}

	}

	void read_test_data()
	{
		string file_name = "dane_testujace.txt";
		ifstream data_file;
		data_file.open (file_name.c_str(), ios::in);

		if ( !data_file.is_open() ){
			cout << "problem with opening file!" << endl;
		}

		for(int i = 0; i< amount_of_test_data; i++)
		{
			for(int j = 0; j< amount_of_parameters; j++)
			{
				data_file >> test_data[i][j];
			}
			data_file >> test_wanted_outs[i];
		}

	}

	void learn(int learn_iterations)
	{
		for(int i = 0; i< learn_iterations; i++)
		{
			for(int j = 0; j< amount_of_learn_data; j++)
			{
				network->learn_network(learn_data[j], learn_wanted_outs[j]);
			}
		}
	}

	int * ask()
	{
		int * outs = new int[amount_of_test_data];
		for(int i = 0; i< amount_of_test_data; i++)
		{
			outs[i] = network->ask_network( test_data[i] ) ;
		}
		return outs;
	}

	/*
	 * 1/n sum(Xi - X')
	 * X' = (X1 + ... + Xn )/n
	 */
	double test()
	{
		double mistake = 0;
		int sum = 0, tmp_mistake = 0;
		int* outs = ask();

		for(int j = 0; j< amount_of_test_data; j++)
		{
			sum += outs[j];
		}
		sum /= amount_of_test_data;

		for(int i = 0; i< amount_of_test_data; i++)
		{
			tmp_mistake += ((test_wanted_outs[i] - sum) * (test_wanted_outs[i] - sum));
		}
		mistake = (double)tmp_mistake/ (double)amount_of_test_data;
		mistake /= 100;

		return mistake;
	}

	void print_weights()
	{
		cout << endl << "\t   rbf_layer \n weights:" << endl;
		for(int i=0; i < size_of_rbf_layer; i++)
		{
			for(int j=0; j < size_of_input; j++)
			{
				cout << network->rbf_layer[i].get_weights()[j] << "\t  ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "\t   linear_layer \n weights:" << endl;
		for(int i=0; i < size_of_linear_layer; i++)
		{
			for(int j=0; j < size_of_rbf_layer; j++)
			{
				cout << network->linear_layer[i].get_weights()[j] << "\t  ";
			}
			cout << endl;
		}
		cout << endl;
	}

	void print_parameters()
	{
		cout << endl;
		cout << "size_of_input \t\t" << size_of_input << endl;
		cout << "size_of_rbf_layer \t" << size_of_rbf_layer << endl;
		cout << "size_of_linear_layer \t" << size_of_linear_layer << endl;
		cout << endl;
	}

};


#endif /* CLASSIFICATION_H_ */

