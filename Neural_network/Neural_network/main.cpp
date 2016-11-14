#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

#include"LogicGates.h"
#include"ClassificationFunction.h"
#include"XOR.h"
#include"HebbUsage.h"

using namespace std;

void logic_gates();
void classification_function();
void XOR_function();
void Hebb();

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
 */
	Hebb();


//	system("pause");

	return 0;
}

void Hebb(){
	cout << "\t\tHebb\n";

	//int amonut_of_iterations = 1;
	int rows_of_data = 9;
	int columns_of_data = 2;
	double result;

	HebbUsage * hebbUsage = new HebbUsage( columns_of_data, rows_of_data);

	double ** learn_data = new double* [rows_of_data];
	for( int i = 0; i< rows_of_data; i ++){
		learn_data[i] = new double [columns_of_data];
	}
	double * learn_data_1 = new double[9];
	double * learn_data_2 = new double[9];

	//dane 1:
	learn_data_1[0] = -1;
	learn_data_1[1] = 1;
	learn_data_1[2] = -1;
	learn_data_1[3] = 1;
	learn_data_1[4] = -1;
	learn_data_1[5] = 1;
	learn_data_1[6] = -1;
	learn_data_1[7] = 1;
	learn_data_1[8] = -1;

	//dane 2:
	learn_data_2[0] = -1;
	learn_data_2[1] = 1;
	learn_data_2[2] = 1;
	learn_data_2[3] = 1;
	learn_data_2[4] = 1;
	learn_data_2[5] = 1;
	learn_data_2[6] = 1;
	learn_data_2[7] = 1;
	learn_data_2[8] = 1;

	learn_data[0] = learn_data_1;
	learn_data[1] = learn_data_2;

	//-------------------------------------------

/*
		cout << "\nlearn_without_supervisor\n";

	hebbUsage->learn_without_supervisor(learn_data, 1);
		result = hebbUsage->ask( learn_data_1 );
		cout << "\t" << result << "\n";
		result = hebbUsage->ask( learn_data_2 );
		cout << "\t" << result << "\n";

	hebbUsage->learn_without_supervisor(learn_data, 3);
		result = hebbUsage->ask( learn_data_1 );
		cout << "\t" << result << "\n";
		result = hebbUsage->ask( learn_data_2 );
		cout << "\t" << result << "\n";
*/
/*
		cout << "\nlearn_with_supervisor\n";
	hebbUsage->learn_with_supervisor(learn_data, 1);
		result = hebbUsage->ask( learn_data_1 );
		cout << "\t" << result << "\n";
		result = hebbUsage->ask( learn_data_2 );
		cout << "\t" << result << "\n";

	hebbUsage->learn_without_supervisor(learn_data, 3);
		result = hebbUsage->ask( learn_data_1 );
		cout << "\t" << result << "\n";
		result = hebbUsage->ask( learn_data_2 );
		cout << "\t" << result << "\n";
*/

	//------------------------------------------
	/*
	for (int i = 0; i< columns_of_data; i++){
		cout << result[i] << "\t";
	}
	*/

	for( int i = 0; i< rows_of_data; i ++){
		delete [] learn_data[i];
	}
	delete learn_data;
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
