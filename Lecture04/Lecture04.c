#include <stdio.h>
#include <conio.h>

int main()
{
	char a;

	while(1)
	{
		if(kbhit())
		{
			a=getch();
			if(a==27)
			{
				break;
			}
		}
		printf("*");
	}
	return 0;
}
