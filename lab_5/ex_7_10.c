/*
 * Exercise 7.10
 * Write a function prime() that returns 1 if its argument is a prime number
 * and returns 0 otherwise.
 */

#include <stdio.h>

/* forward declare prime() */
int prime(int);

int main()
{
    int i;
    /* print the results of prime() from 0 to 99 */
    for (i = 0; i < 100; ++i)
        printf("%3i %s\n", i, prime(i) ? "yes" : "no");
    return 0;
}

int prime(int n)
{
    /* primes cant be divisible by 2 or less than 2 */
    if ((n <= 1) || (n % 2 == 0 && n > 2))
        return 0;

    /* check the odds for divisability */
    int i;
    for (i = 3; i < n / 2; i += 2)
    {
        if (n % i == 0)
            return 0;
    }

    /* otherwise it's a prime */
    return 1;
}
