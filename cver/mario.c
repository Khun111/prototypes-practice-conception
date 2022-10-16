#include <cs50.h>
#include <stdio.h>
int main (void)
{
    int n, i, j, k;
    do
    {
        n = get_int("Height: ");
    }
    while(n < 0);
    for (i = 0; i < n; i++)
    {
        for (k = n - i; k > 0; k--)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}