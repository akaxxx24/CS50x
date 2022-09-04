#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string key);
char rotate(char text, int key);


int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");
    int length = strlen(plaintext);
    printf("ciphertext: ");
    for (int i = 0; i < length; i++)
    {
        printf("%c", rotate(plaintext[i], k));
    }
    printf("\n");



}


bool only_digits(string key)
{
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

//ci=(pi+k)%26
//a0 b1 c2 d3 e4 ...
char rotate(char text, int key)
{
    char ans;
    int tmp;
    int cal;
    if (text >= 97 && text <= 122)
    {
        tmp = text - 'a';
        cal = (tmp + key) % 26;
        ans = (char)('a' + cal);
    }
    else if (text >= 65 && text <= 90)
    {
        tmp = text - 'A';
        cal = (tmp + key) % 26;
        ans = (char)('A' + cal);
    }
    else
    {
        ans = text;
    }
    return ans;
}
