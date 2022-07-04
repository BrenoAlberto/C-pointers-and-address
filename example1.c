#include <stdio.h>

int main()
{
    char a = 'a';
    char b = 'b';

    printf("&a: %p\n", &a); // &a: 0x7ffe4e809e76
    printf("&b: %p\n", &b); // &b: 0x7ffe4e809e77
}