# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int printf2(const char* string, char a)//, int b, float c, char* s
{
	int i;
	for (i = 0; strlen(string) > i; i++)
	{
		if (string[i] == '%')
		{
			switch (string[i + 1])
			{
			case 'c':
				putchar(a);
				i++;
				break;
			default:
				break;
			}
			continue;
		}
		putchar(string[i]);
	}
	return 0;
}

int main()
{
	char a = 't';
	int b = 0;
	float c = 0;
	char d[100] = "abcd";

	printf2("±è¼®¹ü %c", a);

	return 0;
}