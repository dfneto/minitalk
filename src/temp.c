#include <stdio.h>

int main()
{
    char a = 'A';   //0100 0001
    int mask = 128; //1000 0000
    int i;
 
    i = a & mask;   //0000 0000
    printf("%d", i);
    
    mask = mask >> 1;   //0100 0000
    i = (a) & mask; 
    printf("%d", i);
    
    mask = mask >> 1;
    i = (a) & mask; 
    printf("%d", i);

    mask = mask >> 1;
    i = (a) & mask; 
    printf("%d", i);

    mask = mask >> 1;
    i = (a) & mask; 
    printf("%d", i);

    mask = mask >> 1;
    i = (a) & mask; 
    printf("%d", i);
    
    mask = mask >> 1;
    i = (a) & mask; 
    printf("%d", i);

    mask = mask >> 1;
    i = (a) & mask; 
    printf("%d", i);
}