/*
 * HebbAll.h
 *
 *  Created on: Dec 2, 2016
 *      Author: maria
 */

#ifndef HEBBALL_H_
#define HEBBALL_H_

#include<math.h>
#include<stdlib.h>

class HebbAll
{
public:
	double * weight, * input;
	double w_0, learn_number, output, zapominanie;
	int size, moja_warstwa;

	HebbAll(){	}

	void init(int size){
		learn_number = 0.6;
		zapominanie = 0.1;
		this->size = size;

		weight = new double[size];

		initialize_weight();
	}

	~HebbAll()
	{
		if (weight)
			delete[] weight;
	}

	void initialize_weight()
	{
		w_0 = (double)rand() / (double)RAND_MAX;
		for (int i = 0; i < size; i++)
		{
			weight[i] = (double)rand() / (double)RAND_MAX;
		}
	}

	double activation_function(double s)
	{
		double ret;
		if(s < 0.0)	ret = -1;
		else		ret = 1;
		return ret;
	}

	double get_and_set_output(double * input)
	{
		double s = w_0;
		for(int i = 0; i < size; i++)
			s += weight[i] * input[i];

//		output = activation_function(s);
		output = s;
		return output;
	}

	void learn(double * input)
	{
		get_and_set_output(input);
		double deltaW = 0.0;
		for(int i = 0; i < size; i++)
		{
			deltaW = learn_number * output * input[i];
			weight[i] = ( weight[i] *(1-zapominanie) + deltaW );
		}

		w_0 = (w_0 *(1-zapominanie) + learn_number * output);
	}

	void learn_with_teacher(double * input, double d)
	{
		get_and_set_output(input);
		double deltaW = 0.0;
		for(int i = 0; i < size; i++)
		{
			deltaW = learn_number * d * input[i];
			weight[i] = ( weight[i] *(1-zapominanie) + deltaW );
		}

		w_0 = (w_0 *(1-zapominanie) + learn_number * d);
	}

};

#endif /* HEBBALL_H_ */
