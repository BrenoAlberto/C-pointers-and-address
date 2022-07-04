#include <stdio.h>

int main() 
{
    char a_char = 'z';

    // Declare a pointer and initialize to address of a_char
    char *a_char_ptr = &a_char;
    // We read this backwards, for example a_chart_ptr is a pointer to a character

    // Read / Print the address in the pointer
    printf("a_char_ptr: %p\n", a_char_ptr);

    // Read the address referenced by the pointer / "dereference"
    printf("*a_char_ptr: %c\n", *a_char_ptr);

    // Write to the memory address stored in a pointer
    *a_char_ptr = 'y';
    // Read from a_char:
    printf("a_char: %c\n", a_char);
}