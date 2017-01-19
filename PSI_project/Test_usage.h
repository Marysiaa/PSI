/*
 * Test_usage.h
 *
 *  Created on: Dec 10, 2016
 *      Author: maria
 */

#ifndef TEST_USAGE_H_
#define TEST_USAGE_H_

#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;

#include "Network.h"

class Test_usage
{
private:
	Network * network;

	double *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8;
	double *test1, *test2, *test3;
	int * wanted_outs;

public:
	int size_of_input, size_of_rbf_layer, size_of_linear_layer;

public:
	Test_usage()
	{
		network = new Network;

		size_of_input = 2;
		size_of_rbf_layer = 2;
		size_of_linear_layer = 1;

		network->initialize_netowrk(
				size_of_input,
				size_of_rbf_layer,
				size_of_linear_layer);

		init_inputs();

		wanted_outs = new int[11];
		wanted_outs[0] = 1;
		wanted_outs[1] = 1;
		wanted_outs[2] = -1;
		wanted_outs[3] = -1;
		wanted_outs[4] = 1;
		wanted_outs[5] = 1;
		wanted_outs[6] = -1;
		wanted_outs[7] = 1;
		wanted_outs[8] = 1;
		wanted_outs[9] = -1;
		wanted_outs[10] = 1;
	}

	~Test_usage(){}


	void test_learn()
	{
		cout << "test learn " << endl << endl;
		for(int i = 0; i< 50; i++)
		{
			network->learn_network(input1, wanted_outs[0]);
			network->learn_network(input2, wanted_outs[1]);
			network->learn_network(input3, wanted_outs[2]);
			network->learn_network(input4, wanted_outs[3]);
			network->learn_network(input5, wanted_outs[4]);
			network->learn_network(input6, wanted_outs[5]);
			network->learn_network(input7, wanted_outs[6]);
			network->learn_network(input8, wanted_outs[7]);
		}
	}

	void test_ask_and_print_results()
	{
		double outs1, outs2, outs3;
		outs1 = network->ask_network(test1);
		outs2 = network->ask_network(test2);
		outs3 = network->ask_network(test3);

		if( outs1 == wanted_outs[8])
			cout << " test 1 - okay " << endl;
		if( outs2 == wanted_outs[9])
			cout << " test 2 - okay " << endl;
		if( outs3 == wanted_outs[10])
			cout << " test 3 - okay " << endl;

		cout << endl;
		for (int i = 0; i< size_of_linear_layer; i++)
			cout << outs1 << "\t ";
		cout << endl << endl;

		for (int i = 0; i< size_of_linear_layer; i++)
			cout << outs2 << "\t ";
		cout << endl << endl;

		for (int i = 0; i< size_of_linear_layer; i++)
			cout << outs3 << "\t ";
		cout << endl << endl;
	}

	void init_inputs()
	{
		//uczace
		input1 = new double [2];
		input1[0] = 0.97;
		input1[1] = 0.2;
		input2 = new double [2];
		input2[0] = -0.72;
		input2[1] = 0.7;
		input3 = new double [2];
		input3[0] = -0.8;
		input3[1] = 0.6;
		input4 = new double [2];
		input4[0] = 0.2;
		input4[1] = -0.97;
				input5 = new double [2];
				input5[0] = 1.0;
				input5[1] = 0.0;
				input6 = new double [2];
				input6[0] = -0.67;
				input6[1] = 0.74;
				input7 = new double [2];
				input7[0] = 0.0;
				input7[1] = -1.0;
				input8 = new double [2];
				input8[0] = 0.3;
				input8[1] = -0.95;

		//testujace
		test1 = new double [2];
		test1[0] = 0.8;
		test1[1] = 0.1;
		test2 = new double [2];
		test2[0] = -0.47;
		test2[1] = 0.8;
		test3 = new double [2];
		test3[0] = 0.1;
		test3[1] = -0.65;
	}

	void print_parameters()
	{
		cout << endl;
		cout << "size_of_input \t\t" << size_of_input << endl;
		cout << "size_of_rbf_layer \t" << size_of_rbf_layer << endl;
		cout << "size_of_linear_layer \t" << size_of_linear_layer << endl;
		cout << endl;
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


	int * test_ask()
	{
		int * outs = new int[3];
		outs[0] = network->ask_network(test1);
		outs[1] = network->ask_network(test2);
		outs[2] = network->ask_network(test3);
		return outs;
	}

	double test_mistake()
	{
		double mistake = 0;
		int sum = 0, tmp_mistake = 0, amount_of_test_data=3;
		int* outs = test_ask();

		for(int j = 0; j< amount_of_test_data; j++)
		{
			sum += outs[j];
		}
		sum /= amount_of_test_data;

		tmp_mistake += ((wanted_outs[8] - sum) * (wanted_outs[8] - sum));
		tmp_mistake += ((wanted_outs[9] - sum) * (wanted_outs[9] - sum));
		tmp_mistake += ((wanted_outs[10] - sum) * (wanted_outs[10] - sum));

		mistake = (double)tmp_mistake/ (double)amount_of_test_data;
		mistake /= 100;

		return mistake;
	}

};

#endif /* TEST_USAGE_H_ */
