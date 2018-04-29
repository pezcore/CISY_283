/**
 * Exercise 10.7
 *
 * Write a pointer version of the `sort()` function from Chapter 7, "Working
 * with Functions." Be certain that pointers are exclusively used by the
 * function, including index variables in the loops.
 */

#include <stdio.h>

/**
 * Function to sort an array in place, based on "simple exchange sort
 * algorithm" from Kochan ch. 7 but uses pointers instead of indexing to access
 * array elements for comparison and swap.
 */
void sort(int * a, int size)
{
    /* declare pointers to point to the array elements of comparison */
    int *i, *j, temp;
    /* iterate through all the 2-permutations prescribed by the algorithm */
    for(i = a; i < a + size - 1; i++)
        for(j = i + 1; j < a + size; j++)
            /* use pointer dereference instead of indexing syntax */
            if(*i > *j)
            /* swap the values of the two pointed positions */
            {
                temp = *i;
                *i = *j;
                *j = temp;
            }
}

int main (void)
{
    /* copied directly from text */
    int i;
    int array[16] =
    {
        34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11
    };

    printf ("The array before the sort:\n");
    for (i = 0; i < 16; ++i)
        printf("%i ", array[i]);

    sort (array, 16);

    printf ("\n\nThe array after the sort:\n");
    for (i = 0; i < 16; ++i)
        printf ("%i ", array[i]);
    putchar('\n');
    return 0;
}
