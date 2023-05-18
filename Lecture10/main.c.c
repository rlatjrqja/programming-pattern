#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int printYuhan(const char* string, int num)
{
	char ary[] = {'a'};
	//strcpy
	int i = 0;

	while (ary[i] != '%')
	{
		printf("%c",ary[i]);
		i++;
	}

	/*
	int i;
	for (i = 0; strlen(string) > i; i++)
	{
		if (string[i] == '%')
		{
			

			switch (num)
			{
			case 7:
				puts('7');
				i++;
				break;
			default:
				break;
			}
			continue;
		}
		puts(string[i]);
	}
	*/
	return 0;
}

int main()
{
	int num = 7;
	printYuhan("이은석은 %d배 멋진 남자!", num);

	return 0;
}