#include <stdio.h>
int main()
{
	printf("Hello, World\n");
	printf("It worked\n");
	for (int i = '0'; i <= '9'; i++)
	{
		putchar(i);
		if (i != '9')
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return 0;
}
