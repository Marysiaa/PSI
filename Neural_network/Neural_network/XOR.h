/*
 * XOR.h
 *
 *      Author: maria
 */

#ifndef XOR_H_
#define XOR_H_

#include <iostream>
#include"Adaline_MLP.h"

using namespace std;

class XOR
{
private:
	Adaline_MLP * adaline_mlp;
	Learn_data * learn_data;

public:
	XOR(){
		int size_of_lay[] = {2, 4, 1};
		int * wsk = &size_of_lay[0];

		double err = 0.4;
		adaline_mlp = new Adaline_MLP( 3, wsk, err);

		learn_data = new Learn_data[4];

		learn_data[0].input = new double[2];
		learn_data[0].input[0] = 0;
		learn_data[0].input[1] = 0;
		learn_data[0].wanted_output = new double[1];
		learn_data[0].wanted_output[0] = 1;

		learn_data[1].input = new double[2];
		learn_data[1].input[0] = 0;
		learn_data[1].input[1] = 1;
		learn_data[1].wanted_output = new double[1];
		learn_data[1].wanted_output[0] = 0;

		learn_data[2].input = new double[2];
		learn_data[2].input[0] = 1;
		learn_data[2].input[1] = 0;
		learn_data[2].wanted_output = new double[1];
		learn_data[2].wanted_output[0] = 0;

		learn_data[3].input = new double[2];
		learn_data[3].input[0] = 1;
		learn_data[3].input[1] = 1;
		learn_data[3].wanted_output = new double[1];
		learn_data[3].wanted_output[0] = 1;
	}

	void learn_until_learned()
	{
		cout << "zaczynam... " << endl;
		int iterations_until_learned = adaline_mlp->learn_until_learned( learn_data, 4);
		cout << "iterations_until_learned:\t" << iterations_until_learned << endl;
	}

	void learn(int amount_of_iterations )
	{

		double mistake = adaline_mlp->learn_function(amount_of_iterations, learn_data, 4 );
		cout << "mistake:\t" << mistake << endl;
	}

	void ask_xor( double x1, double x2)
	{
		double * data = new double[2];
		data[0] = x1;
		data[1] = x2;

		double * wynik =  adaline_mlp->ask_function(data);

		cout << "x1 = " << x1 << " x2 = " << x2 << " wynik: " << wynik[0] << endl;
		delete [] wynik;
	}

};

#endif /* XOR_H_ */
