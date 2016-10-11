#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include<math.h>

class Perceptron 
{
private:
	double * weight;
	Perceptron ** input;
	int size;
	double w_0;

public:
	double output;

	Perceptron() {};
	Perceptron(int size, Perceptron * perceptron) 
	{
		this->size = size;

		weight = new double[size];
		initialize_weight();

		input = new Perceptron * [size];
		for (int i = 0; i < size; i++) 
		{
			input[i] = &perceptron[i];
		}

		output = -1;
	}

	~Perceptron() 
	{
		if (weight)
			delete[] weight;		
	}

	void ask()
	{
		double s = 0;
		s += w_0;
		for (int i = 0; i < size; i++) 
		{
			s += (weight[i] * input[i]->output );
		}

		double result = interpret(s);
		if (result >= 0)
			output = 1;
		else
			output = 0;
	}

	void learn(double wanted_out, double learn_number) 
	{
		ask();

		w_0 += (wanted_out - output) * learn_number;
		for (int i = 0; i < size; i++)
		{
			weight[i] += (input[i]->output * (wanted_out - output) * learn_number);
		}
	}

	//TODO
	Perceptron & operator = (Perceptron & p1) 
	{
		this->input = p1.input;
		this->weight = p1.weight;
		this->size = p1.size;
		this->output = p1.output;
		this->w_0 = p1.w_0;

		return * this;
	}

private:  
	double interpret(double s) 
	{
		return s;
	}

	void initialize_weight()
	{
		w_0 = (double) rand()/ (double)RAND_MAX;		// [0,...,1]
		for (int i = 0; i < size; i++)
		{
			weight[i] = (double)rand() / (double)RAND_MAX;
		}
	}

};

#endif

