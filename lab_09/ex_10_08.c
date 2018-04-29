/**
 * Exercise 10.8
 *
 * Write a function called `sort3()` to sort three integers into ascending
 * order. (This function is not to be implemented with arrays.)
 */

#include <stdio.h>

void swap(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* sort the variables pointed to into ascending order */
void sort3(int * a, int * b, int * c)
{
    if (*a > *b)
        swap(a, b);
    if (*a > *c)
        swap(a, c);
    if (*b > *c)
        swap(b, c);
}

int main()
{
    int a = 5, b = 2, c = 10;
    sort3(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    /* again */
    a = 10, b = 5, c = 2;
    sort3(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    /* and another one, already sorted this time */
    a = 2, b = 5, c = 10;
    sort3(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    return 0;
}
