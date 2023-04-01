#include <iostream>
#include <conio.h>

int main()
{
	char a;
	while(1)
	{
		if(_kbhit())
		{
			a = _getch();
			if(a == 27)
			{
				break;
			}
		}
		std::cout << "*";
	}
	return 0;
}
