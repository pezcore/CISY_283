/*
 * Exercise 4.2
 * Write a program to generate and display a table of n and n^2, for integer
 * values of n ranging from 1 to 10. Be certain to print appropriate column
 * headings.
 */

#include <stdio.h>

int main()
{
    /* print columns of n an n^2 from 1 to 10 */
    printf("n  n^2\n");
    int n;
    for (n = 1; n <= 10; ++n)
        printf("%-2d %-3d\n", n, n * n);
    return 0;
}
