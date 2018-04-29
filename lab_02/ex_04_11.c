/*
 * Exercise 4.11
 * Write a program that calculates the sum of the digits of an integer. For
 * example, the sum of the digits of the number 2155 is 2 + 1 + 5 + 5 or 13.
 * The program should accept any arbitrary integer typed in by the user.
 */

#include <stdio.h>

int main()
{
    int i;
    printf("enter an integer: ");
    scanf("%i", &i);
    int n = 0;
    while (i)
    {
        n += i % 10;
        i /= 10;
    }
    printf("%d", n);
    return 0;
}
