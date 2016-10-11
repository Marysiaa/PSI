#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

#include"Perceptron.h"
#include"NetworkController.h"
#include"LogicGates.h"

using namespace std;

int main() 
{
	srand(time(NULL));

	LogicGates logic_gates;

	cout << "\nOR\nbez uczenia:\n";
	logic_gates.asking_OR();
	for (int i = 0; i < 3; i++)
	{
		cout << "po uczeniu "<< i+1 << ":\n";
		logic_gates.learning_OR();
		logic_gates.asking_OR();
	}

	cout << "\nAND\nbez uczenia:\n";
	logic_gates.asking_AND();
	for (int i = 0; i < 3; i++)
	{
		cout << "po uczeniu " << i+1 << ":\n";
		logic_gates.learning_AND();
		logic_gates.asking_AND();
	}

	cout << "\nNOT\nbez uczenia:\n";
	logic_gates.asking_NOT();
	for (int i = 0; i < 3; i++)
	{
		cout << "po uczeniu " << i+1 << ":\n";
		logic_gates.learning_NOT();
		logic_gates.asking_NOT();
	}

	system("pause");
	return 0;
}