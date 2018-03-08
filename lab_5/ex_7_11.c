/*
 * Exercise 7.11
 * Write a function called arraySum() that takes two arguments: an integer
 * array and the number of elements in the array. Have the function return as
 * its result the sum of the elements in the array.
 */

#include <stdio.h>
#define ARRAYLEN 7

/* forward declare arraySum()*/
int arraySum(int[], int);

int main()
{

    /* initialize the array to sum */
    int arr[ARRAYLEN] = { 1, 2, 3, 4, 5, 6, 7 };

    /* print the results of the summation */
    int i;
    for (i = 0; i < ARRAYLEN - 1; ++i)
        printf("%d + ", arr[i]);

    /* call arraySum() to actually compute the sum */
    /* also dont forget to print the last array element's value */
    printf("%d = %d\n", arr[ARRAYLEN - 1], arraySum(arr, ARRAYLEN));
    return 0;

}

int arraySum(int arr[], int len)
{
    int i, x = 0;
    /* for each element add it to the output variable */
    for (i = 0; i < len; ++i)
        x += arr[i];
    return x;
}
