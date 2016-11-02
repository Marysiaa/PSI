#ifndef LOGIC_GATES_H
#define LOGIC_GATES_H

#include<iostream>
#include"PerceptronController.h"

using namespace std;

class LogicGates
{
private:
	PerceptronController * network_controller_OR;
	PerceptronController * network_controller_AND;
	PerceptronController * network_controller_NOT;

	double * input_0 = new double[1]{ 0 };
	double * input_1 = new double[1]{ 1 };

	double * input_00 = new double[2]{ 0,0 };
	double * input_01 = new double[2]{ 0,1 };
	double * input_10 = new double[2]{ 1,0 };
	double * input_11 = new double[2]{ 1,1 };

	double learn_number = 0.6;

public:
	LogicGates()
	{
		int * size_of_lay = new int[2]{ 2,1 };
		network_controller_OR = new PerceptronController(2, size_of_lay);
		network_controller_AND = new PerceptronController(2, size_of_lay);

		int * size_of_lay_NOT = new int[2]{ 1,1 };
		network_controller_NOT = new PerceptronController(2, size_of_lay_NOT);
				
		delete[] size_of_lay_NOT;
		delete[] size_of_lay;
	}
		
	void asking_OR()
	{
		network_controller_OR->put_input(input_00);
		cout << "0,0\t" << network_controller_OR->ask_network() << "\n";

		network_controller_OR->put_input(input_01);
		cout << "0,1\t" << network_controller_OR->ask_network() << "\n";

		network_controller_OR->put_input(input_10);
		cout << "1,0\t" << network_controller_OR->ask_network() << "\n";

		network_controller_OR->put_input(input_11);
		cout << "1,1\t" << network_controller_OR->ask_network() << "\n";
	}

	void learning_OR()
	{
		network_controller_OR->put_input(input_00);
		network_controller_OR->learn_network(input_0,learn_number);

		network_controller_OR->put_input(input_01);
		network_controller_OR->learn_network(input_1, learn_number);

		network_controller_OR->put_input(input_10);
		network_controller_OR->learn_network(input_1, learn_number);

		network_controller_OR->put_input(input_11);
		network_controller_OR->learn_network(input_1, learn_number);
	}

	void asking_AND()
	{
		network_controller_AND->put_input(input_00);
		cout << "0,0\t" << network_controller_AND->ask_network() << "\n";

		network_controller_AND->put_input(input_01);
		cout << "0,1\t" << network_controller_AND->ask_network() << "\n";

		network_controller_AND->put_input(input_10);
		cout << "1,0\t" << network_controller_AND->ask_network() << "\n";

		network_controller_AND->put_input(input_11);
		cout << "1,1\t" << network_controller_AND->ask_network() << "\n";
	}

	void learning_AND()
	{
		network_controller_AND->put_input(input_00);
		network_controller_AND->learn_network(input_0, learn_number);

		network_controller_AND->put_input(input_01);
		network_controller_AND->learn_network(input_0, learn_number);

		network_controller_AND->put_input(input_10);
		network_controller_AND->learn_network(input_0, learn_number);

		network_controller_AND->put_input(input_11);
		network_controller_AND->learn_network(input_1, learn_number);
	}

	void asking_NOT()
	{
		network_controller_NOT->put_input(input_0);
		cout << "0\t" << network_controller_NOT->ask_network() << "\n";

		network_controller_NOT->put_input(input_1);
		cout << "1\t" << network_controller_NOT->ask_network() << "\n";
	}

	void learning_NOT()
	{
		network_controller_NOT->put_input(input_0);
		network_controller_NOT->learn_network(input_1, learn_number);

		network_controller_NOT->put_input(input_1);
		network_controller_NOT->learn_network(input_0, learn_number);
	}

};

#endif