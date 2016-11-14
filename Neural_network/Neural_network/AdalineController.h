/*
 * AdalineController.h
 *
 *      Author: maria
 */

#ifndef ADALINECONTROLLER_H_
#define ADALINECONTROLLER_H_

#include<string>
#include <sstream>

#include"Adaline.h"

using namespace std;

class AdalineController
{
private:
	Adaline ** adalines;
	int amount_of_lays;
	int * size_of_lay;
	double learn_number;

public:
	AdalineController(int amount_of_lays , int * size_of_lay)
	{
		this->amount_of_lays = amount_of_lays;
		learn_number = 0.6;

		this->size_of_lay = new int[amount_of_lays];
		for (int i = 0; i < amount_of_lays; i++)
		{
			this->size_of_lay[i] = size_of_lay[i];
		}

		initialize_network();
	}

	~AdalineController()
	{
		if (size_of_lay)
			delete [] size_of_lay;
		if (adalines)
		{
			for (int i = 0; i < amount_of_lays; i++)
				delete[] adalines[i];
			delete [] adalines;
		}
	}

private:
	void initialize_network()
	{
		Adaline * tmp_adalines_old; //, * tmp_adalines;

		adalines = new Adaline *[amount_of_lays];
		for(int i=0; i< amount_of_lays ; i++ )
		{
			Adaline * tmp_adalines= new Adaline [size_of_lay[i]];

			if( i == 0 )
			{
			}

			for(int j=0; j< size_of_lay[i] ; j++ )
			{
				if(i != 0 )
				{
					tmp_adalines[j] = *(new Adaline(size_of_lay[i-1], tmp_adalines_old));
					tmp_adalines[j].learn_number = learn_number;
				}
				else
				{
					tmp_adalines[j] = *(new Adaline());
				}
			}
			tmp_adalines_old = tmp_adalines;
			/*
			Adaline *tmp = new Adaline[size_of_lay[i]];
			for(int j=0; j< size_of_lay[i] ; j++ ){
				tmp[j] = *tmp_adalines[j];
			}*/

			adalines[i] = tmp_adalines;

		}
	}

public:
	void put_input(double * input)
	{
		for (int i = 0; i < size_of_lay[0]; i++)
		{
			adalines[0][i].output = input[i];
		}
	}

	double* ask_network()
	{
		for (int i = 1; i < amount_of_lays; i++)
		{
			for (int j = 0; j < size_of_lay[i]; j++)
			{
				adalines[i][j].ask();
			}
		}

		double* result = new double[size_of_lay[ amount_of_lays-1 ]];

		for (int i = 0; i < size_of_lay[amount_of_lays - 1]; i++)
		{
			result[i] = adalines[amount_of_lays - 1][i].output;
		}

		return result;
	}

	void learn_network(double * wanted_out)
	{
		ask_network();

		for (int i = 0; i < size_of_lay[amount_of_lays - 1]; i++)
		{
			adalines[amount_of_lays - 1][i].learn_first(wanted_out[i]);
		}

		for (int i = amount_of_lays - 2; i > 0; i--)
		{
			for (int j = 0; j < size_of_lay[i]; j++)
			{
				adalines[i][j].learn_next();
			}
		}

/*
		for (int i = 1; i < amount_of_lays; i++)
		{
			for (int j = 0; j < size_of_lay[i]; j++)
			{
				adalines[i][j].learn_next();
			}
		}
*/
	}


};

#endif /* ADALINECONTROLLER_H_ */
