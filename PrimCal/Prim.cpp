#include <iostream>

bool Prim(int Numb)
{	
	//1 und 0 werden von anfang an ausgeschlossen
	if (Numb == 0 || Numb == 1) { return false; }
	//göster teiler kann nur sqrt(Numb) sein.
	for (int i = 2;i <= sqrt(Numb); i+=2)
	{
		//durch zeir wird gepüft danach auf ungrade zahlen getestet
		if (i == 4)i = 3;

		//Number wird auf den teiler i getestet
		if ((Numb%i) == 0)
		{
			return false;
		}
	}
	return true;
}