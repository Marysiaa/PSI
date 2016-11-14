/*
 * Madaline.h
 *
 *      Author: maria
 */

#ifndef ADALINE_MLP_H_
#define ADALINE_MLP_H_

//	MULTI LINEAR PERCEPTRON - ADALINE for XOR

#include"AdalineController.h"

struct Learn_data
{
	double * input;
	double * wanted_output;
};

class Adaline_MLP
{
private:
	double err;
	AdalineController * adalineController;
	int last_lay_size;


public:
	Adaline_MLP(int amount_of_lays, int * size_of_lay, double err)
	{
		this->err = err;
		last_lay_size = size_of_lay[amount_of_lays-1];
		adalineController = new AdalineController( amount_of_lays, size_of_lay);
	}

	~Adaline_MLP()
	{
		delete adalineController;
	}

	int learn_until_learned( Learn_data * learn_data, int amount_of_data)
	{
		double max_mistake, modul_bledu;
		int amount_of_iterations = 0;
		do
		{
			amount_of_iterations ++;
			max_mistake = learn_function( 1, learn_data, amount_of_data );

			if (amount_of_iterations >= 10e4)
			{
				break;
			}

		}while( max_mistake > err );

		return amount_of_iterations;
	}

	double learn_function(int amount_of_iterations, Learn_data * learn_data, int amount_of_data )
	{
		double * output = new double[4];// = new double[ size_of_lay[ amount_of_lays-1 ] ];
		bool is_ok = false;

		for(int it=0; it< amount_of_iterations; it++ )
		{
			//cout << "iteracja: " << it << endl;

			for(int i=0; i< amount_of_data; i++ )
			{
				adalineController->put_input( learn_data[i].input );

				do
				{
					//cout << "\t\t\t petla do-while, is_ok = " << is_ok << endl;

					adalineController->learn_network( learn_data[i].wanted_output );
					output = adalineController->ask_network();

					//cout << "output : " << output [0]<< endl;

					is_ok = true;
					for(int j=0; j< last_lay_size; j++)
					{
						double modul_wyniku = modul( learn_data[i].wanted_output[j] - output[j]);

						//cout << "wanted: " << learn_data[i].wanted_output[j] << "\t z sieci: " << output[j] << endl;
						//cout << "\t\t\t\t modul_wyniku = " << modul_wyniku << endl;

						//-----------------------------------------

						if( modul_wyniku > err  )
							is_ok = false;
					}
				}while( !is_ok );
			}
		}

		double max_mistake = -1, min_mistake = 1;
		double tmp_mistake, modul_tmp_mistake;

		for(int i=0; i< amount_of_data; i++ )
		{
			for(int j=0; j< last_lay_size; j++)
			{
				tmp_mistake = learn_data[i].wanted_output[j] - output[j];
				modul_tmp_mistake = modul( tmp_mistake );

				//cout << "tmp mistake: " << tmp_mistake << endl;

				if( modul_tmp_mistake > max_mistake )
					max_mistake = modul_tmp_mistake;
				if( modul_tmp_mistake < min_mistake )
					min_mistake = modul_tmp_mistake;
			}
		}

		//cout << "max mistake:\t" << max_mistake << endl;
		//cout << "min mistake:\t" << min_mistake << endl;

		return max_mistake;
	}

	double * ask_function(double * ask_data)
	{
		double * output = new double[last_lay_size];
		adalineController->put_input( ask_data );
		output = adalineController->ask_network();
		return output;
	}

private:

	double modul(double x) {
		if (x < 0)
			return (x * (-1));
		return x;
	}

};

#endif /* ADALINE_MLP_H_ */
