#include "Header.h"
#include <iostream>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "Wählen sie nun den bereich in dem sie nach Primzahlen suchen wollen\n";
	cout << "Von\n"; int start; cin >> start;
	cout << "Bis\n"; int end; cin >> end;
    //Eingabe check
	if (start > end)
	{
		cout << "Der angegebender Bereich ist fehlerhaft!!!";
		return 0;
	}

	ofstream data;
	data.open("Primzahlen.txt", ios::out | ios::in);

	int counterlane = 0;
	int countprim = 0;
	float Ver;
	for (int i = start;i < end;i++)
	{
		if (Prim(i) == true)
		{
			countprim ++;
			cout << i;
			counterlane++;
			if (counterlane == 10)
			{
				cout << " \n";
				counterlane = 0;
			}
			else cout << ",";
		}
	}
	Ver = float(countprim) / float(end - start);

	cout << "\n In :";
	cout << end-start;
	cout << " Soviele Prim gefunden :";
	cout << countprim;
	cout << " Verhätnis :";
	cout << Ver;
	
	data.close();
	return 0;
}