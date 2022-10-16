#include <stdio.h>
int main()
{
    int i, j, k;
    for (i = '0'; i <= '7'; i++)
    {
        for (j = '1'; j <= '8'; j++)
        {
            k = '2';
            while (k <= '9')
            {
                if (k > j && j > i)
                {
                    putchar(i);
                    putchar(j);
                    putchar(k);
                    if (i != '7')
                    {
                        putchar(',');
                        putchar(' ');
                    }
                }
                k++;
            }
        }
    }
    putchar('\n');
}