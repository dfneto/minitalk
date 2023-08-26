
//COMO QUE ESTA MIERDA FUNCIONA?!?!?! :/
#include "minitalk.h"

int main()
{
    char *a = (char *)malloc(1 * 4);
    
    long long i = 0;
    while(i < 1000000)
    {
    	a[i] = 'a';
    	i++;
    }
    a[i] = '\0';
    printf("%s\n", a);
    printf("waka waka");

}