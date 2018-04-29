/**
 * Exercise 11.5
 *
 * Write a function called `bit_test()` that takes two arguments: an unsigned
 * int and a bit number n. Have the function return 1 if bit number n if it is
 * on inside the word, and 0 if it is off. Assume that bit number 0 references
 * the leftmost bit inside the integer. Also write a corresponding function
 * called `bit_set()` that takes two arguments: an unsigned int and a bit
 * number n.  Have the function return the result of turning bit n on inside
 * the integer.
 */

#include <stdio.h>
#include <limits.h>

int bit_test(unsigned int x, unsigned int n)
{
    return x & (1 << (sizeof(int) * CHAR_BIT - n - 1)) ? 1 : 0;
}

unsigned int bit_set(unsigned int x, unsigned int n)
{
    return x | (1 << (sizeof(int) * CHAR_BIT - n - 1));
}

int main()
{
    unsigned int x = 0xD8133609;

    /* test each bit in x sequentially with bit_test() */
    int i;
    printf("Printing each bit sequentially using bit_test():\n");
    for (i = 0; i < sizeof(int) * CHAR_BIT; ++i)
        printf("%d", bit_test(x, i));
    printf("\n\n");

    /* set each bit in x sequentially with bit_set() */
    printf("printing results of bit_set() for each bit until number is fully "
           "set:\n");
    for (i = 0; i < sizeof(int) * CHAR_BIT; ++i)
        printf("%X\n", x = bit_set(x, i));

    return 0;
}
