/*
 * HebbUsage.h
 *
 *  Created on: Nov 14, 2016
 *      Author: maria
 */

#ifndef HEBBUSAGE_H_
#define HEBBUSAGE_H_

#include"HebbNeuronController.h"

class HebbUsage
{
public:
	HebbNeuronController * hnc;
	int columns_of_data, rows_of_data;

	HebbUsage(int columns_of_data, int rows_of_data)
	{
		this->columns_of_data = columns_of_data;
		this->rows_of_data = rows_of_data;

		int * size_of_lay = new int[2];
		//size_of_lay[0]= ( columns_of_data * rows_of_data );
		size_of_lay[0]= 9;
		size_of_lay[1]= 1;

		hnc = new HebbNeuronController(2, size_of_lay);
	}

	double ask(double * input){
		double result;

		result = hnc->ask( input )[0];

		return result;
	}

	void learn_without_supervisor(double ** learn_data, int iterations){

		while( iterations > 0 ){

			for( int i = 0; i< rows_of_data; i ++){
					hnc->learn( learn_data[i]);
			}
			iterations --;
		}
	}

	void learn_with_supervisor(double ** learn_data, int iterations){

		while( iterations > 0 ){

			double * tmp_tab = new double[1];
			tmp_tab[0] = -1;

			for( int i =0; i< rows_of_data; i ++){

				hnc->learn(learn_data[i], tmp_tab);

				if( tmp_tab[0] == -1)
					tmp_tab[0] = 1;
				else
					tmp_tab[0] = -1;

			}
			iterations --;
		}
	}


};

#endif /* HEBBUSAGE_H_ */
