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
	double **oi;

	double * input;
	int input_size;

	HebbNeuronController( int amount_of_lays , int * size_of_lay, int input_size )
	{
		this->amount_of_lays = amount_of_lays;
		this->input_size = input_size;

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
		if (oi)
		{
			for (int i = 0; i < amount_of_lays; i++)
				delete[] oi[i];
			delete [] oi;
		}
	}

	void initialize_network(){

		hebb_neuron = new HebbNeuron *[amount_of_lays];
		oi = new double *[amount_of_lays];

		for(int i = 0 ; i< amount_of_lays; i++){
				if(i == 0 ){							//warstwa zerowa
					hebb_neuron[i] = new HebbNeuron [input_size];
//					cout << "input_size " << input_size << endl;
				}
				else{									//kolejne warstwy
					hebb_neuron[i] = new HebbNeuron [size_of_lay[i]];
//					cout << "size_of_lay[" << i <<" -1] " << size_of_lay[i] << endl;
			}
		}

		for(int i = 0 ; i< amount_of_lays; i++){
			for( int j = 0; j<  size_of_lay[i]; j++){

				if(i == 0 ){							//warstwa zerowa
					hebb_neuron[i][j].init(input_size);
				}
				else{									//kolejne warstwy
					hebb_neuron[i][j].init(size_of_lay[i-1]);
				}
			}
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
		double * prev_out;
		set_input(input);

		for(int j = 0; j< size_of_lay[0]; j++){
			hebb_neuron[0][j].ask( input );
		}

		for(int i = 1; i< amount_of_lays; i++){
			prev_out = new double[ size_of_lay[i-1] ];

			for(int z = 0; z< size_of_lay[i-1]; z++){
				prev_out[z] = hebb_neuron[i-1][z].output;
			}

			for(int j = 0; j< size_of_lay[i]; j++){
				hebb_neuron[i][j].ask( prev_out );
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
		double * prev_out;

		set_input(input);
		ask(input);

		for(int i = 1 ; i< amount_of_lays; i++){
			prev_out = new double[size_of_lay[i-1]];

			for(int z = 0; z< size_of_lay[i-1]; z++){
				prev_out[z] = hebb_neuron[i-1][z].output;
			}

			for( int j = 0; j<  size_of_lay[i]; j++){
				hebb_neuron[i][j].learn( prev_out );

				for(int z = 0; z< size_of_lay[i-1]; z++){
//					cout << "\t" << z  << " "<< hebb_neuron[i][j].weight[z] << endl;
				}
			}
//			cout << endl;

		}

	}

	void learn( double * input, double * waned_out)
	{
		double * prev_out2, * prev_out;
		set_input(input);
		ask(input);

		prev_out2 = new double[size_of_lay[ amount_of_lays -2 ]];
		for(int z = 0; z< size_of_lay[  amount_of_lays -2 ]; z++){
			prev_out2[z] = hebb_neuron[ amount_of_lays -2][z].output;
		}

		for(int i = 0; i<  size_of_lay[ amount_of_lays -1 ]; i++){
			hebb_neuron[amount_of_lays -1 ][i].learn( waned_out[i], prev_out2 );
		}

		for( int j = amount_of_lays-2; j >0; j--){
			prev_out = new double[size_of_lay[j-1]];

			for(int z = 0; z< size_of_lay[j-1]; z++){
				prev_out[z] = hebb_neuron[j-1][z].output;
			}


			for(int k = 0; k<  size_of_lay[ j ]; k++){
				hebb_neuron[j][k].learn(prev_out);
			}
		}
	}

};

#endif /* HEBBNEURONCONTROLLER_H_ */
