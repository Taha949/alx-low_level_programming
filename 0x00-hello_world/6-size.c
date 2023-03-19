#include<stdio.h>
int main(void)
{
    int intType;
    float floatType;
    long longType;
    char charType;
    printf("Size of a char: %zu byt(e)\n", sizeof(charType));
    printf("Size of an int: %zu byte(s)\n", sizeof(intType));
    printf("Size of a long int: %zu byte(s)\n", sizeof(longType));
    printf("Size of float: %zu byte(s)\n", sizeof(floatType));

    return (0);
}
