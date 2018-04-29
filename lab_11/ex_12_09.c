/**
 * Exercise 12.9
 *
 * Write a macro ABSOLUTE_VALUE that computes the absolute value of its
 * argument. Make certain that an expression such as ABSOLUTE_VALUE (x + delta)
 * is properly evaluated by the macro.
 */

#define ABSOLUTE_VALUE(X) ((X) < 0 ? -(X) : (X))
#include <stdio.h>

int main()
{
    int x;
    /* test the macro for both positive and negative values */
    for (x = -10; x < 11; ++x)
        printf("%2d %2d\n", x + 3, ABSOLUTE_VALUE(x + 3));
    return 0;
}
