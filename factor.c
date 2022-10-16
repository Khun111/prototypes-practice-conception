
#include <stdio.h>
#include <math.h>
/**
 * main - prime factors
 * Return: int
 */
int main(void)
{
	long i;
	long num = 612852475143, max;
	while (num % 2 == 0)
	{
		max = 2;
		num /= 2;
	}
	for (i = 3; i < sqrt(num); i += 2)
	{
		while (num % i == 0)
		{
			max = i;
			num /= i;
		}
	}
	if (num > 2)
	{
		max = num;
	}
printf("%lu", max);
}