#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

#include"LogicGates.h"
#include"ClassificationFunction.h"
#include"XOR.h"
#include"HebbAll.h"
#include"KohonenNetwork.h"
#include"HopfieldNewtork.h"
#include"HopfieldTest.h"

using namespace std;

void logic_gates();
void classification_function();
void XOR_function();
void Hebb();
void Kohonen();
void Hopfield();

int main() 
{
	srand(time(NULL));
/*
	bramki logiczne
	logic_gates();
 */

/*
	funkcja klasyfikujaca
	classification_function();
 */

/*
	adaline
	XOR_function();
 */

/*
	hebb
	Hebb();
 */

	/*
	 * siec Kohena
	Kohonen();
	 */

	/*
	 * siec Hopfielda
	Hopfield();
	 */

//	system("pause");



	return 0;
}

void Hopfield(){

cout << "sieci Hopfielda" << endl;

int size_of_input = 9, amount_of_learn_iters = 100;
HopfieldTest ht(size_of_input);

// *** uczace ***

int amount_of_input_vetors = 7;
double ** learn_input = new double *[amount_of_input_vetors];
for ( int i = 0; i < amount_of_input_vetors; ++i )
	learn_input[i] = new double [size_of_input];

double* input1 = new double [9] {1,-1,1,-1,1,-1,1,-1,1};	//win x
double* input2 = new double [9] {-1,-1,-1,1,1,-1,-1,1,1};	//win o
double* input3 = new double [9] {-1,-1,1,-1,1,-1,-1,-1,1};	//win x
double* input4 = new double [9] {1,-1,-1,-1,-1,1,1,-1,1};	//win o
double* input5 = new double [9] {1,1,-1,1,-1,-1,1,-1,1};	//win x
double* input6 = new double [9] {-1,-1,1,-1,-1,1,1,1,-1};	//not
double* input7 = new double [9] {-1,1,1,1,1,-1,-1,-1,1};	//not

for ( int j = 0; j < size_of_input; ++j )
{
	learn_input[0][j] = input1[j];
	learn_input[1][j] = input2[j];
	learn_input[2][j] = input3[j];
	learn_input[3][j] = input4[j];
	learn_input[4][j] = input5[j];
	learn_input[5][j] = input6[j];
	learn_input[6][j] = input7[j];
}

// ustawienie wektora uczacego
ht.set_input(amount_of_input_vetors, learn_input);

// *** testujace ***
double* input8 = new double [9] {1,1,1,-1,-1,1,1,-1,-1};	//win x
double* input9 = new double [9] {-1,1,-1,1,-1,1,-1,1,-1};	//win o
double* input10 = new double [9] {1,1,-1,1,1,-1,-1,-1,1};	//not

/*
amount_of_input_vetors = 3;
double ** test_input = new double *[amount_of_input_vetors];
for ( int i = 0; i < amount_of_input_vetors; ++i )
	test_input[i] = new double [size_of_input];
for ( int j = 0; j < size_of_input; ++j )
{
	test_input[0][j] = input8[j];
	test_input[1][j] = input9[j];
	test_input[2][j] = input10[j];
}
*/

cout << "poczatkowe losowe wagi: " << endl;
ht.print_weights();

cout << "uczenie - ilosc iteracji = " << amount_of_learn_iters << endl;
for(int i =0; i< amount_of_learn_iters; i++)
{
	ht.learn_network();
}

cout << endl << "wagi po uczeniu: " << endl;
ht.print_weights();

//cout << endl << "podanie wektora wejsciowego - testowego " << endl << endl;
ht.set_ask_input(input8);

cout << endl << "odpytanie (1) " << endl;
cout << "wynik: \t" << ht.ask_network();

ht.set_ask_input(input9);
cout << endl << "odpytanie (-1) " << endl;
cout << "wynik: \t" << ht.ask_network();

ht.set_ask_input(input1);
cout << endl << "odpytanie (1) " << endl;
cout << "wynik: \t" << ht.ask_network();

}

void Kohonen(){

	//uczace
	double* input1 = new double [2];
			input1[0] = 0.97;
			input1[1] = 0.2;
	double* input2 = new double [2];
			input2[0] = -0.72;
			input2[1] = 0.7;
	double* input3 = new double [2];
			input3[0] = -0.8;
			input3[1] = 0.6;
	double* input4 = new double [2];
			input4[0] = 0.2;
			input4[1] = -0.97;
			double* input5 = new double [2];
					input5[0] = 1.0;
					input5[1] = 0.0;
			double* input6 = new double [2];
					input6[0] = -0.67;
					input6[1] = 0.74;
			double* input7 = new double [2];
					input7[0] = 0.0;
					input7[1] = -1.0;
			double* input8 = new double [2];
					input8[0] = 0.3;
					input8[1] = -0.95;

	//testujace
	double* test1 = new double [2];
	test1[0] = 0.8;
	test1[1] = 0.1;
	double* test2 = new double [2];
	test2[0] = -0.47;
	test2[1] = 0.8;
	double* test3 = new double [2];
	test3[0] = 0.1;
	test3[1] = -0.65;


	int amount_of_neurons = 3;
	int size_of_input = 2;

	double *outs1 = new double[amount_of_neurons];
	double *outs2 = new double[amount_of_neurons];
	double *outs3 = new double[amount_of_neurons];

	KohonenNetwork * network = new KohonenNetwork(size_of_input, amount_of_neurons);

	outs1 = network->ask_for_outputs(test1);
	outs2 = network->ask_for_outputs(test2);
	outs3 = network->ask_for_outputs(test3);

	cout << "wyniki testu przed uczeniem " << endl;
	for(int i =0; i< amount_of_neurons; i++)
	{
		if(outs1[i] == 1)
			cout << "test: 1 \t" << "grupa: " << i+1 << endl;
		if(outs2[i] == 1)
			cout << "test: 2 \t" << "grupa: " << i+1 << endl;
		if(outs3[i] == 1)
			cout << "test: 3 \t" << "grupa: " << i+1 << endl;
	}
	cout << endl;
// ---------------------------------------------------
	int amount_of_iterations = 1, x = 0;

	for(int nr=1; nr<10; nr+=2){
		x+= nr;
		amount_of_iterations = nr;

		for(int i=0; i< amount_of_iterations; i++)
		{
			network->learn_WTA(input1);
			network->learn_WTA(input2);
			network->learn_WTA(input3);
			network->learn_WTA(input4);
			network->learn_WTA(input5);
			network->learn_WTA(input6);
			network->learn_WTA(input7);
			network->learn_WTA(input8);
		}
	// ---------------------------------------------------

		outs1 = network->ask_for_outputs(test1);
		outs2 = network->ask_for_outputs(test2);
		outs3 = network->ask_for_outputs(test3);

		cout << endl << "wyniki testu po " << x << " iteracjach uczenia" << endl;
		for(int i =0; i< amount_of_neurons; i++)
		{
			if(outs1[i] == 1)
				cout << "test: 1 \t" << "grupa: " << i+1 << endl;
			if(outs2[i] == 1)
				cout << "test: 2 \t" << "grupa: " << i+1 << endl;
			if(outs3[i] == 1)
				cout << "test: 3 \t" << "grupa: " << i+1 << endl;
		}
		cout << endl;
	}
}

void Hebb(){

	double* input1 = new double [3];
		input1[0] = -1.0;
		input1[1] = 1.0;
		input1[2] = -1.0;
	double* input2 = new double [3];
		input2[0] = 1.0;
		input2[1] = 1.0;
		input2[2] = 1.0;

		double d1 = -1;
		double d2 = 1;

		HebbAll * ha = new HebbAll();
		ha->init(3);
/*
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
			ha->learn(input1);
			ha->learn(input2);
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
			ha->learn(input1);
			ha->learn(input2);
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
			ha->learn(input1);
			ha->learn(input2);
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
			ha->learn(input1);
			ha->learn(input2);
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
			ha->learn(input1);
			ha->learn(input2);
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
			ha->learn(input1);
			ha->learn(input2);
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
*/
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
			ha->learn_with_teacher(input1, d1);
			ha->learn_with_teacher(input2, d2);
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
			ha->learn_with_teacher(input1, d1);
			ha->learn_with_teacher(input2, d2);
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
			ha->learn_with_teacher(input1, d1);
			ha->learn_with_teacher(input2, d2);
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
			ha->learn_with_teacher(input1, d1);
			ha->learn_with_teacher(input2, d2);
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
			ha->learn_with_teacher(input1, d1);
			ha->learn_with_teacher(input2, d2);
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;
			ha->learn_with_teacher(input1, d1);
			ha->learn_with_teacher(input2, d2);
		cout << ha->get_and_set_output(input1)<< endl;
		cout << ha->get_and_set_output(input2)<< endl;


}

void XOR_function(){

	cout << "\t\tXOR" << endl;
	int x = 0;

	XOR xor_f;
	cout << "\n\tbez uczenia:" << endl;
	xor_f.ask_xor(0, 0);
	xor_f.ask_xor(1, 0);
	xor_f.ask_xor(0, 1);
	xor_f.ask_xor(1, 1);

	x = 1;
	cout << "\n\tpo " << x <<" iteracjach:" << endl;

	xor_f.learn(x);

	xor_f.ask_xor(0, 0);
	xor_f.ask_xor(1, 0);
	xor_f.ask_xor(0, 1);
	xor_f.ask_xor(1, 1);

	x = 10;
	cout << "\n\tpo " << x <<" iteracjach:" << endl;

	xor_f.learn(x);

	xor_f.ask_xor(0, 0);
	xor_f.ask_xor(1, 0);
	xor_f.ask_xor(0, 1);
	xor_f.ask_xor(1, 1);

	x = 100;
	cout << "\n\tpo " << x <<" iteracjach:" << endl;

	xor_f.learn(x);

	xor_f.ask_xor(0, 0);
	xor_f.ask_xor(1, 0);
	xor_f.ask_xor(0, 1);
	xor_f.ask_xor(1, 1);

	x = 1000;
	cout << "\n\tpo " << x <<" iteracjach:" << endl;

	xor_f.learn(x);

	xor_f.ask_xor(0, 0);
	xor_f.ask_xor(1, 0);
	xor_f.ask_xor(0, 1);
	xor_f.ask_xor(1, 1);

	x = 10000;
	cout << "\n\tpo " << x <<" iteracjach:" << endl;

	xor_f.learn(x);

	xor_f.ask_xor(0, 0);
	xor_f.ask_xor(1, 0);
	xor_f.ask_xor(0, 1);
	xor_f.ask_xor(1, 1);

	x = 100000;
	cout << "\n\tpo " << x <<" iteracjach:" << endl;

	xor_f.learn(x);

	xor_f.ask_xor(0, 0);
	xor_f.ask_xor(1, 0);
	xor_f.ask_xor(0, 1);
	xor_f.ask_xor(1, 1);

	XOR xor_infinity;
	cout << "\n\tszybkosc uczenia:" << endl;
		xor_infinity.learn_until_learned();

	xor_infinity.ask_xor(0, 0);
	xor_infinity.ask_xor(1, 0);
	xor_infinity.ask_xor(0, 1);
	xor_infinity.ask_xor(1, 1);
}

void logic_gates(){

	LogicGates logic_gates;
	cout << "\nOR\nbez uczenia:\n";

	logic_gates.asking_OR();
	for (int i = 0; i < 5; i++)
	{
		cout << "po uczeniu "<< i+1 << ":\n";
		logic_gates.learning_OR();
		logic_gates.asking_OR();
	}

	cout << "\nAND\nbez uczenia:\n";
	logic_gates.asking_AND();
	for (int i = 0; i < 5; i++)
	{
		cout << "po uczeniu " << i+1 << ":\n";
		logic_gates.learning_AND();
		logic_gates.asking_AND();
	}

	cout << "\nNOT\nbez uczenia:\n";
	logic_gates.asking_NOT();
	for (int i = 0; i < 5; i++)
	{
		cout << "po uczeniu " << i+1 << ":\n";
		logic_gates.learning_NOT();
		logic_gates.asking_NOT();
	}
}

void classification_function(){

	ClassificationFunction classification;

	cout << "\nklasyfikacja\nbez uczenia:\t";
	cout << classification.testing() << "%" << endl;

	int amount_of_iterations = 10;
	for (int i = 0; i < amount_of_iterations; i++)
	{
		classification.learning();
		cout << "progres po " << i << " iteracjach:\t" << classification.testing() << "%\n";
	}
//	cout << "po " << amount_of_iterations << " iteracjach uczenia:\n";
//	classification.testing();

}
