#include <stdio.h>

// int main()
// {
//     char a = 'A';   
//     int mask = 128; 
//     int i;

//     i = 0;
//     while (i <= 7)
//     {
//         if (a & mask)
//             printf("1");
//         else
//             printf("0");
//         mask = mask >> 1;
//         i++;
//     }
// }

int main()
{
    char a = 0;
    a: 0000 0000
    1: 0000 0001

    if (1)
        a = a | 1;

    a: 0000 0000
    a << 1;
    a: 0000 0010
    
    printf()

}
