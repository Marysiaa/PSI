#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

#include"Perceptron.h"
#include"NetworkController.h"
#include"LogicGates.h"
#include"ClassificationFunction.h"

using namespace std;

int main() 
{
	srand(time(NULL));

	//bramki logiczne
	/*
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
	*/

	//funkcja klasyfikujaca
	ClassificationFunction classification;

	cout << "\nklasyfikacja\nbez uczenia:\t";
	cout << classification.testing() << "%" << endl;

	int amount_of_iterations = 100;
	for (int i = 0; i < amount_of_iterations; i++)
	{
		classification.learning();
		cout << "progres po " << i << " iteracjach:\t" << classification.testing() << "%\n";
	}
//	cout << "po " << amount_of_iterations << " iteracjach uczenia:\n";
//	classification.testing();

	system("pause");
	return 0;
}