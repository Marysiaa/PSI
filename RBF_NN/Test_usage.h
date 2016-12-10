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


public:
	int size_of_input, size_of_rbf_layer, size_of_linear_layer;

public:
	Test_usage()
	{
		network = new Network;

		size_of_input = 2;
		size_of_rbf_layer = 3;
		size_of_linear_layer = 2;

		network->initialize_netowrk(
				size_of_input,
				size_of_rbf_layer,
				size_of_linear_layer);

		init_inputs();

	}
	~Test_usage(){}

	double get_result()
	{
		network->ask_network(test1);
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
		cout << "\t   rbf_layer \n wagi:" << endl;
		for(int i=0; i < size_of_rbf_layer; i++)
		{
			for(int j=0; j < size_of_input; j++)
			{
				cout << network->rbf_layer[i].get_weights()[j] << "\t  ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "\t   linear_layer \n wagi:" << endl;
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

};

#endif /* TEST_USAGE_H_ */
