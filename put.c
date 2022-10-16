#include <stdio.h>
int main()
{
    int a, b, c, d;
    int var, sec;
    for (var = 0; var <= 99; var++)
    {
        a = (var / 10);
        b = (var % 10);
        sec = 1;
        while (sec < 100)
        {
            c = (sec / 10);
            d = (sec % 10);
            if (a < c || (a == c && b < d) )
            {
                putchar( a + '0');
                putchar( b + '0');
                putchar(' ');
                putchar( c + '0');
                putchar( d + '0');
                if (b != 8)
                {
                    putchar(',');
                }
            }
            sec++;
        }
    }
}