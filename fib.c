#include <stdio.h>

/**
 * main - finds and prints the first 98 fibonacci numbers
 * starting with 1 and 2
 * Return: Always o (Success)
 */
int main(void)
{
	unsigned long int i, f1, f2, f2d, f2m, f1d, f1m;

	f1 = 1;
	f2 = 2;

	printf("%lu", f1);

	for (i = 1; i < 91; i++)
	{
		printf(", %lu", f2);
		f2 += f1;
		f1 = f2 - f1;
	}

	f1d = f1 / 1000000000;
	f1m = f1 % 1000000000;
	f2d = f2 / 1000000000;
	f2m = f2 % 1000000000;

	for (i = 92; i < 99; ++i)
	{
		printf(", %lu", f2d + (f2m / 1000000000));
		printf("%lu", f2m % 1000000000);
		f2d += f1d;
		f1d = f2d - f1d;
		f2m += f1m;
		f1m = f2m - f1m;
	}

	printf("\n");
	return (0);
}