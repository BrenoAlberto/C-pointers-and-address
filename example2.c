#include <stdio.h>
#include <stdint.h>

int main()
{
    // uint16_t a = 1;
    // uint16_t b = 2;

    // printf("&a: %p\n", &a); // &a: 0x7ffd4f3137f4
    // printf("&b: %p\n", &b); // &b: 0x7ffd4f3137f6

    uint32_t c = 1;
    uint32_t d = 2;

    printf("&c: %p\n", &c); // &a: 0x7ffceaee5670
    printf("&d: %p\n", &d); // &b: 0x7ffceaee5674
}