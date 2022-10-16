#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Make custom function to make sure the key is numeric
bool onlydigits(string s)
{
    for (int j = 0; j < strlen(s); j++)
    {
        if (!isdigit(s[j]))
        {
            return false;
        }
    }
    return true;
}
//Custom function to shift the plain text by the key
char rotatetext(char p, int k)
{
    char c;
    if (isalpha(p))
    {
        if (isupper(p))
        {                    
            c = (((p - 65) + k) % 26) + 65;
        }
        else
        {
            c = (((p - 97) + k) % 26) + 97;
        }
    }
    else
    {
        c = p;
    }
    return c;
}
int main(int argc, string argv[]) 
{
    //Make sure only two command line arguments are entered and that key is numeric. Otherwise, return an error message
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (!onlydigits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    { 
        //Once conditions are fulfilled, prompt user for text
        string plain = get_string("plaintext:  ");
        printf("ciphertext: ");
        int k = atoi(argv[1]);
        //Give user an output after rotating the text by the key
        for (int i = 0; i < strlen(plain); i++)
        {
            char c = rotatetext(plain[i], k);
            printf("%c", c);
        }
        printf("\n");
        return 0;
    }
}