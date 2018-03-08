/*
 * Exercise 5.3
 * Write a program that accepts two integer values typed in by the user.
 * Display the result of dividing the first integer by the second, to
 * three-decimal-place accuracy. Remember to have the program check for
 * division by zero.
 */

#include<stdio.h>

int main()
{
    int first, second;
    printf("Enter the first number: ");
    scanf("%i", &first);
    printf("Enter the second number: ");
    scanf("%i", &second);

    if (!second)
        printf("You cant divide by zero!");
    else
    {
        double q = (double)first / second;
        printf("The quotient is %.3f", q);
    }
    return 0;
}
