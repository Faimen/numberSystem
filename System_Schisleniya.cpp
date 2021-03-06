// System_Schisleniya.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"



int stringToInt(char *c)
{
	int n = 0;
	int i = 0;
	while (c[i]!='\0')
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			n = n * 10 + (c[i] - '0');
		}
		else
		{
			n = n * 10 + (c[i] - 'A' + 10);
		}
		i++;
	}
	/*for (int i = 0; c[i] >= '0' && c[i] <= '9'; i++)
	{
		n = n * 10 + (c[i] - '0');
	}*/
	return n;
}

int charToInt(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	else {
		return c - 'A' + 10;
	}
}

char intToChar(int c) {
	if (c >= 0 && c <= 9) {
		return c + '0';
	}
	else {
		return c + 'A' - 10;
	}
}

void intToString(char *numb, int c)
{
	int i = 0;
	while (c / 10 != 0)
	{
		numb[i++] = intToChar(c % 10);
		c = c / 10;
	}
	numb[i++] = intToChar(c);
	numb[i] = '\0';
	i--;
	int j = 0;
	char t;
	while (i > j)
	{
		t = numb[i];
		numb[i] = numb[j];
		numb[j] = t;
		i--;
		j++;
	}
	
}

char from10toN(char *numb, int step)
{
	int value = stringToInt(numb);
	char result[65] = {};
	int i = 0;
	while (value >= step)
	{
		result[i++] = intToChar(value % step);
		value /= step;
	}
	result[i] = intToChar(value);
	for (i; i >= 0; i--)
	{
		printf("%c", result[i]);
	}
	
	return 0;
}

int fromNto10(char *numb, int step)
{
	int result = 0;
	int i = 0;
	while (numb[i]!='\0')
	{
		result += charToInt(numb[i])*pow(step, strlen(numb)-i-1);
		i++;
	}
	return result;
}

int main()
{
	char numb[65];
	int bitDepth, originalBitDepth;
	printf("Input number \n");
	scanf("%s", &numb);
	printf("Input original bit depth \n");
	scanf("%d", &originalBitDepth);
	printf("Input bit depth \n");
	scanf("%d", &bitDepth);
	printf("Your numb = %s, bit depth = %d \n", numb, bitDepth);
	if (originalBitDepth != 10)
	{
		intToString(numb, fromNto10(numb, originalBitDepth));
		from10toN(numb, bitDepth);
	}
	else
	{
		from10toN(numb, bitDepth);
	}
    return 0;
}

