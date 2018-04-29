/*
 * Exercise 6.4
 * Write a program that calculates the average of an array of 10 floating-point
 * values.
 */

#include <stdio.h>

int main ()
{
    /* declare a float accumlator s, initialized to 0, and an array of 10
     * floats initialized to some random float numbers */
    float s = 0, arr[10] = {67.39, 47.28, 22.30, 87.71, 12.14, 91.31, 23.27,
                            75.20, 52.45, 98.18};

    /* calculate the sum */
    int i;
    for (i = 0; i < 10; s += arr[i++]);
    /* print the mean, (sum / 10) */
    printf("The mean is %f", s / 10.0); /* should be 57.723 */
    return 0;
}
