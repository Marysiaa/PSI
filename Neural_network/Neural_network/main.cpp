#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

#include"LogicGates.h"
#include"ClassificationFunction.h"
#include"XOR.h"
#include"HebbAll.h"

#include"KohenNeuron.h"

using namespace std;

void logic_gates();
void classification_function();
void XOR_function();
void Hebb();
void KohenNetwork();

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
	 */

	KohenNetwork();

//	system("pause");
	return 0;
}

void KohenNetwork(){


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
