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

int main()
{
	srand(time(NULL));
	cout << "\t -- RBF_NN --" << endl;

	Test_usage test;
	test.print_parameters();
	test.print_weights();

	test.print_test_results();


	return 0;
}
