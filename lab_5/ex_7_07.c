/*
 * Exercise 7.7
 * Write a function that raises an integer to a positive integer power. Call
 * the function x_to_the_n() taking two integer arguments x and n. Have the
 * function return a long int, which represents the results of calculating x^n.
 */

#include<stdio.h>

long int x_to_the_n(int x, int n);

int main()
{
    /* Just call the function and print the results */
    printf("2 ^ 13 = %li\n", x_to_the_n(2, 13));
    return 0;
}

long int x_to_the_n(int x, int n)
{
    long int y = x;
    while (n-- > 1)
        y *= x;
    return y;
}
