/*
 * HebbNeuronController.h
 *
 *  Created on: Nov 14, 2016
 *      Author: maria
 */

#ifndef HEBBNEURONCONTROLLER_H_
#define HEBBNEURONCONTROLLER_H_

#include "HebbNeuron.h"

class HebbNeuronController
{
public:
	HebbNeuron ** hebb_neuron;
	int amount_of_lays;
	int * size_of_lay;
	double learn_number;

	HebbNeuronController( int amount_of_lays , int * size_of_lay )
	{
		this->amount_of_lays = amount_of_lays;

		//------------------------ STALA UCZENIA --------------------------//
		learn_number = 0.1;

		this->size_of_lay = new int[amount_of_lays];
		for (int i = 0; i < amount_of_lays; i++)
		{
			this->size_of_lay[i] = size_of_lay[i];
		}

		initialize_network();
	}

	~HebbNeuronController()
	{
		if (size_of_lay)
			delete [] size_of_lay;
		if (hebb_neuron)
		{
			for (int i = 0; i < amount_of_lays; i++)
				delete[] hebb_neuron[i];
			delete [] hebb_neuron;
		}
	}

	void initialize_network()
	{
		HebbNeuron * hebb_previous;
		hebb_neuron = new HebbNeuron *[amount_of_lays];

		for(int i = 0 ; i< amount_of_lays; i++){

			HebbNeuron * hebb_actual = new HebbNeuron[ size_of_lay[i] ];

			for( int j = 0; j<  size_of_lay[i]; j++){

				if(i != 0 ){
					hebb_actual[j] = *(new HebbNeuron(size_of_lay[i-1], hebb_previous));
					hebb_actual[j].learn_number = learn_number;
				}
				else{
					hebb_actual[j] = *(new HebbNeuron());
				}
			}

			hebb_previous = hebb_actual;
			hebb_neuron[i] = hebb_actual;
		}

	}

	void set_input(double * input)
	{
		for(int j = 0; j < size_of_lay[0]; j++){
			hebb_neuron[0][j].output = input[j];
		}
	}

	double * ask(double *input)
	{
		set_input(input);
		for(int i = 0; i< amount_of_lays; i++){
			for(int j = 0; j< size_of_lay[i]; j++){
				hebb_neuron[i][j].ask();
			}
		}

		double * result = new double[size_of_lay[amount_of_lays -1]];

		for(int k = 0; k< size_of_lay[amount_of_lays -1]; k++){
			result[k] = hebb_neuron[amount_of_lays -1][k].output;
		}
		return result;
	}

	void learn(double * input)
	{
		set_input(input);
		ask(input);

		for(int i = 1 ; i< amount_of_lays; i++){
			for( int j = 0; j<  size_of_lay[i]; j++){
				hebb_neuron[i][j].learn();
			}
		}
	}

	void learn( double * input, double * waned_out)
	{
		set_input(input);
		ask(input);

		for(int i = 0; i<  size_of_lay[ amount_of_lays -1 ]; i++){
			hebb_neuron[amount_of_lays -1 ][i].learn( waned_out[i]);
		}

		for( int j = amount_of_lays-2; j >0; j--){
			for(int k = 0; k<  size_of_lay[ j ]; k++){
				hebb_neuron[j][k].learn();
			}
		}
	}

	double get_max_mistake(double *outs, double * results, int size_of_results)
	{
		double max_actual = 0, tmp;
		for(int i = 0; i < size_of_results; i++){
			tmp = results[i] - outs[i];
			if(tmp < 0)
				tmp = -tmp;
			if(max_actual < tmp)
				max_actual = tmp;
		}
		return max_actual;
	}

	//double learn_arr

};

#endif /* HEBBNEURONCONTROLLER_H_ */
