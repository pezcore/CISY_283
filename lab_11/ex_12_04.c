/**
 * Exercise 12.4
 *
 * Define a macro MAX3 that gives the maximum of three values. Write a program
 * to test the definition.
 */

#include <stdio.h>
#define MAX(A, B) (((A) > (B)) ? (A) : (B))
#define MAX3(A, B, C) (MAX((MAX((A), (B))), (C)))

#include <stdio.h>

int main()
{
    int a, b, c;
    /* test the macro with a bunch of 3-combinations */
    for (a = -2; a < 3; ++a)
        for (b = -2; b < 3; ++b)
            for (c = -2; c < 3; ++c)
                printf("%2d %2d %2d %2d\n", a, b, c, MAX3(a, b, c));
    return 0;
}
