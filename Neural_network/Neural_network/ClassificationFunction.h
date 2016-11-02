#ifndef CLASSIFICATION_FUNCTION_H
#define CLASSIFICATION_FUNCTION_H

#include<iostream>
#include<math.h>
#include"PerceptronController.h"

using namespace std;

class ClassificationFunction
{
private:
	PerceptronController * controller;
	double learn_number; // = 0.6;

	double function(double x) 
	{
		double tmp_result = sin(x);
		if (tmp_result > 0)
			return 1;
		else
			return 0;
	}

public:

	ClassificationFunction() 
	{
		learn_number = 0.6;

		int * size_of_lay = new int[2]; //{ 1,1 };
		size_of_lay[0]=1;
		size_of_lay[1]=1;

		controller = new PerceptronController(2, size_of_lay);
	}

	void asking(double x)
	{
		double input = x;
		controller->put_input(&input);
		cout << input << "\t" << controller->ask_network() << "\n";
	}

	double testing()
	{
		double input, wanted, progress = 0, count =0;

		for (double i = -0.22; i < 0.69; i+= 0.1)
		{
			input = i;
			controller->put_input(&input);
//			cout << input << "\t" << controller->ask_network() << "\n";
			
			count++;
			wanted = function(input);
			if (atof(controller->ask_network().c_str()) == wanted)
			{
				progress++;
			}
		}
		progress = (progress / count) * 100;
		return progress;
	}

	void learning()
	{
		double input, output;
		for (double i = -1.55; i < 1.36; i+= 0.1) 
		{
			input = i;
			output = function(i);
			
			controller->put_input(&input);
			do
			{
				controller->learn_network(&output, learn_number);
			}
			while (atof(controller->ask_network().c_str()) != output);	
		}
	}

};

#endif
