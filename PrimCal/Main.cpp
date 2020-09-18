#include "Header.h"
#include <iostream>
#include <fstream>
#include <ctime>


using namespace std;

int main()
{
	double duration;
	int countprim = 0;
	int line_no = 0;
	string sLine;

	fstream Datatxt;
    clock_t startTime;

    cout << "Please enter a area to look for prime numbers\n";
	cout << "Starting from: "; int startNum; cin >> startNum;
	cout << "Till: "; int endNum; cin >> endNum; cout << '\n';

	startTime = clock();

    //Eingabe der start und end werte
	if (startNum > endNum)
	{
		cout << "Bad area! CUNT";
		cin;
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

	cout << "\n From: " << endNum - startNum << " numbers, are: " << countprim << " prime numbers";
	cout << "\n " << (Ver*100) <<"% are prime numbers" ;

	duration = (clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "\n The calculation took: " << duration << "s";

	Datatxt.close();
	cin;
}