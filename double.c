#include <stdio.h>
int main()
{
	int i, j;
	for (i = '0'; i <= '8'; i++)
	{
		j = '1';
		while (j <= '9')
		{
			if (j > i)
			{
				putchar(i);
				putchar(j);
				if(i != '8')
				{
					putchar(',');
					putchar(' ');
				}
			}
			j++;
		}
	}
	putchar('\n');
}
