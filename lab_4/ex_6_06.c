/*
 * Exercise 6.6
 * You don’t need to use an array to generate Fibonacci numbers. You can simply
 * use three variables: two to store the previous two Fibonacci numbers and one
 * to store the current one. Rewrite Program 6.3 so that arrays are not used.
 * Because you’re no longer using an array, you need to display each Fibonacci
 * number as you generate it.
 */

#include <stdio.h>
int main ()
{
    /* declare and initialize 3 int variables to use as storage */
    int current = 0, next = 1, afternext;

    /* to generate 15 numbers run the loop 15 times */
    int i;
    for (i = 0; i < 15; ++i )
    {
        printf("%i\n", current); /* print current number */
        /* compute and store sum of current and next number */
        afternext = current + next;
        /* shift semantics down a place for the next iteration */
        current = next;
        next = afternext;
    }
    return 0;
}
