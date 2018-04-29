/**
 * Exercise 12.3
 *
 * Define a macro MIN that gives the minimum of two values. Then write a
 * program to test the macro definition.
 */

#include <stdio.h>
#define MIN(A, B) (((A) < (B)) ? (A) : (B))

int main()
{
    int a, b;
    /* test the macro with a bunch of 2-combinations */
    for (a = -3; a < 4; ++a)
        for (b = -3; b < 4; ++b)
            printf("%2d %2d %2d\n", a, b, MIN(a, b));
    return 0;
}
