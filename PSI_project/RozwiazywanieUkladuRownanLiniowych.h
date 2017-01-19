/*
* Pieniążek Maria
*/

#ifndef ROZWIAZYWANIE_UKLADU_ROWNAN_LINIOWYCH_H
#define ROZWIAZYWANIE_UKLADU_ROWNAN_LINIOWYCH_H

#include<iostream>
using namespace std;

class RozwiazywanieUkladuRownanLiniowych {
public:
	int degree;
	double * wartosci, * wektor, * wspolczynnikiTab;
	double ** wejsciowaMacierz;


	RozwiazywanieUkladuRownanLiniowych(double ** macierzUkladu, int degree, double* wektor) {
			this->degree = degree;
			this->wejsciowaMacierz = macierzUkladu;
			this->wektor = wektor;
	}

	//metoda GAUSSA
	double* gauss() {

		//		cout << "Rozwiazywanie ulkadu rownan liniowych: \n\n\t\tmetoda GAUSSA:\n";

		double err = 1e-12;
		double* result;
		result = new double[degree];

		int szerokosc = degree + 1, wysokosc = degree;
		double ** macierz = new double *[szerokosc];

		for (int y = 0; y < szerokosc; y++) {
			macierz[y] = new double[wysokosc];
		}

		for (int y = 0; y < degree; y++) {
			for (int x = 0; x < degree; x++) {
					macierz[x][y] = wejsciowaMacierz[y][x];
			}
		}

		for (int y = 0; y < wysokosc; y++) {
			macierz[szerokosc - 1][y] = wektor[y];
		}

		/*
		cout << "macierz przed eliminacja Gaussa: " << endl;
		cout.precision(2);
		for (int y = 0; y < wysokosc; y++) {
			for (int x = 0; x < szerokosc; x++) {
				cout << macierz[x][y] << "\t";
			}
			cout << endl;
		}
		cout << endl;
		*/

		double wspolczynnik, tmp;

		for (int k = 0; k < szerokosc - 1; k++) {

			for (int wiersz = k + 1; wiersz < wysokosc; wiersz++) {
				wspolczynnik = macierz[k][wiersz] / macierz[k][k];

				for (int kolumna = 0; kolumna < szerokosc; kolumna++) {
					tmp = wspolczynnik * macierz[kolumna][k];
					if (modul(macierz[kolumna][wiersz] - tmp) < err) {
						macierz[kolumna][wiersz] = 0;
					}
					else {
						macierz[kolumna][wiersz] -= tmp;
					}
				}
			}

		}

		/*
		cout << "macierz po eliminacji Gaussa: " << endl;
	//	cout.precision(2);
		for (int y = 0; y < wysokosc; y++) {
			for (int x = 0; x < szerokosc; x++) {
				cout << macierz[x][y] << "\t";
			}
			cout << endl;
		}
		cout << endl;
		*/

		double licznik = 0, mianownik = 0, tmplicznik = 0;
		double* wyjscie = new double[wysokosc];

		//---------------------------------------------------------- wspolczynniki
		int n = wysokosc - 1;
		wyjscie[n] = macierz[szerokosc - 1][n] / macierz[n][n];

		int cResultTab = n;
		n--;
		for (; n >= 0; n--)
		{
			tmplicznik = 0;
			for (int i = wysokosc - 1; (i != n); i--)
			{
				tmplicznik += wyjscie[i] * macierz[i][n];
			}
			licznik = macierz[szerokosc - 1][n] - tmplicznik;
			mianownik = macierz[n][n];
			wyjscie[--cResultTab ] = licznik / mianownik;

		}

		for (int i = 0; i < wysokosc; i++) {
			result[i] = wyjscie[i];
		}
/*
		cout << "Temperatury: \n";
		for (int i = 0; i < wysokosc; i++) {
			cout << "net.node_tab[ " << i << " ]: " << result[i]<< endl;
		}
		cout << endl;
*/
		return result;

	}

	double modul(double x) {
		if (x < 0)
			return -x;
		return x;
	}
};

#endif // ROZWIAZYWANIE_UKLADU_ROWNAN_LINIOWYCH_H
