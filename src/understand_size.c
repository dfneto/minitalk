#include <stdio.h>

//como que um char eh 1 e um 'a' são 4 e um "a" são 2?
int main()
{
    printf("%lu\n", sizeof('a')); //4
    printf("%lu\n", sizeof("a")); //2
    printf("%lu\n", sizeof(char)); //1
    printf("%lu\n", sizeof(char *)); //8
    printf("%lu\n", sizeof(int)); //4
    printf("%lu\n", sizeof("😃")); //5
    // printf("%lu\n", sizeof('😃')); // => error: character too large for enclosing character literal type
}
