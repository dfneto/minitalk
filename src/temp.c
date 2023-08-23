#include <stdio.h>

int main()
{
    char a = 'A';   
    int mask = 128; 
    int i;

    i = 0;
    while (i <= 7)
    {
        if (a & mask)
            printf("1");
        else
            printf("0");
        mask = mask >> 1;
        i++;
    }
}