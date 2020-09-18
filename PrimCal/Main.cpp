#include "Header.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	double duration;
	int countprim = 0;
	int line_no = 0;
	string sLine;

	fstream Datatxt;
    clock_t startTime;

    cout << "Wählen sie nun den bereich in dem sie nach Primzahlen suchen wollen\n";
	cout << "Von\n"; int startNum; cin >> startNum;
	cout << "Bis\n"; int endNum; cin >> endNum;

	startTime = clock();

    //Eingabe der start und end werte
	if (startNum > endNum)
	{
		cout << "Der angegebender Bereich ist fehlerhaft!!!";
		return 0;
	}

	//Öffen bzw erstellen einen Data.txt documents
	Datatxt.open("PrimeNum.txt", ios::out);
	if (Datatxt.fail()) {
		ofstream Datatxt("PrimeNum.txt");
		Datatxt.open("PrimeNum.txt",ios::out);
	}

	for (int i = startNum;i < endNum;i++)
	{
		//funktion zu überprüfung einerzal true wenn pimezahl
		if (Prim(i) == true)
		{
			countprim ++;

			//Ausgabe der Primzahlen und Speicherung in .txt
			cout << i;
			Datatxt << i;
			Datatxt << "\n";
			//Zeilen umbruch alle x primzahlen
			if ((countprim%10) == 0)
			{
				cout << " \n";
			}
			else cout << ",";
		}
	}
	//verhältnis von zahlen und primzahlen
	float Ver = float(countprim) / float(endNum - startNum);

	cout << "\n Von : " << endNum - startNum << " Zahlen sind : " << countprim << " Primzahlen";
	cout << "\n Das Verhätnis ist : " << Ver;

	duration = (clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "\n Benötigte Zeit in s : " << duration << '\n';

	Datatxt.close();
}