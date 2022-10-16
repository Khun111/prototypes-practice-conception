#include <stdio.h>
/**
 * main - Entry
 * Return: 0
 */
int main(void)
{
	int a = '0';

	while (a <= '9')
	{
		int b = '0';

		while (b < '9')
		{
			int c = '0';

			while (c <= '9')
			{
				int d = '0';

				while (d <= '9')
				{
					if (a < c || (b < d && a == c))
					{
						putchar(a);
						putchar(b);
						putchar(' ');
						putchar(c);
						putchar(d);
					if (!(a == '9' && b == '8'))
					{
						putchar(',');
						putchar(' ');
					}
					}
					d++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
}
