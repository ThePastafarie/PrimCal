#include <iostream>

bool Prim(int Numb)
{
	for (int i = 2;i <= sqrt(Numb); i+=2)
	{
		if (i == 4)i = 3;

		if ((Numb%i) == 0)
		{
			return false;
		}
		else if (Numb == 0 || Numb == 1)
		{
			return false;
		}
	}
	return true;
}