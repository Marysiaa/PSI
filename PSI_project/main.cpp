/*
 * main.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: maria
 */

#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;

#include "Test_usage.h"
#include "Classification.h"

int main()
{
	srand(time(NULL));
	cout << "\t -- RBF_NN --" << endl;
/*
*/
	Classification classification;

	classification.classification_init();
	classification.print_parameters();

	classification.read_learn_data();
	classification.read_test_data();

	classification.print_weights();

	int amount_of_iterations = 1000;
	cout << "\n uczenie: " << amount_of_iterations << " iteracji" << endl;
	classification.learn(amount_of_iterations);

	classification.print_weights();

	double mistake = classification.test();
	cout << "blad sieci = " << mistake << " % " << endl ;


	/*
	Test_usage test;
	test.print_parameters();

	test.print_weights();

	test.test_learn();

	test.print_weights();

	double mistake = test.test_mistake();
	cout << "blad sieci = " << mistake << " % " << endl ;
	*/

	return 0;
}
