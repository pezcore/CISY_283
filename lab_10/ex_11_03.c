/**
 * Exercise 11.3
 *
 * Given that the expression ~0 produces an integer that contains all 1s, write
 * a function called `int_size()` that returns the number of bits contained in
 * an int on your particular machine.
 */

#include <stdio.h>
#include <limits.h>

int int_size()
{

    unsigned int x = ~0;
    unsigned int i = 0;
    while ((x >>= 1) != 0)
        i++;
    return i + 1;
}

int main()
{
    printf("counted int width: %d\n", int_size());
    printf("True int width   : %d\n", sizeof(int) * CHAR_BIT);
    return 0;
}
