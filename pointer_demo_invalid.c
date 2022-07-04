#include <stdio.h>

int* add1Plus1();

int main()
{
    int *a = add1Plus1();
    printf("%i\n", *a);
}

int* add1Plus1()
{
    int a = 1;
    int b = a + a;
    return &b;
}