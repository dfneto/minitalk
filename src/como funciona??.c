
//COMO QUE ESTA MIERDA FUNCIONA?!?!?! :/
#include "minitalk.h"

int main()
{
    char *a = (char *)malloc(1000000001 * 4); //1000000001 da erro de overflow
    
    long long i = 0;
    while(i < 1000000001) //com 10000000 da segfault
    {
    	a[i] = 'a';
    	i++;
    }
    a[i] = '\0';
    printf("%s\n", a);
    printf("waka waka");

}