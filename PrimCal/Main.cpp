#include "Header.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
	double duration;
	int countprim = 0;

	ifstream Datatxt;
    clock_t startTime;

    cout << "Wählen sie nun den bereich in dem sie nach Primzahlen suchen wollen\n";
	cout << "Von\n"; int start; cin >> start;
	cout << "Bis\n"; int end; cin >> end;

	startTime = clock();

    //Eingabe der start und end werte
	if (start > end)
	{
		cout << "Der angegebender Bereich ist fehlerhaft!!!";
		return 0;
	}

	//Öffen bzw erstellen einen Data.txt documents
	Datatxt.open("PrimeNum.txt");
	if (Datatxt.fail()) {
		ofstream Datatxt("PrimeNum.txt");
		Datatxt.open("PrimeNum.txt");
	}

	for (int i = start;i < end;i++)
	{
		//funktion zu überprüfung einerzal true wenn pimezahl
		if (Prim(i) == true)
		{
			countprim ++;
			cout << i;

			//Zeilen umbruch alle x primzahlen
			if ((countprim%10) == 0)
			{
				cout << " \n";
			}
			else cout << ",";
		}
	}
	//verhältnis von zahlen und primzahlen
	float Ver = float(countprim) / float(end - start);

	cout << "\n Von :";
	cout << end-start;
	cout << " Zahlen sind :";
	cout << countprim;
	cout << " Primzahlen das Verhätnis ist :";
	cout << Ver;

	duration = (clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << " Time: " << duration << '\n';
}