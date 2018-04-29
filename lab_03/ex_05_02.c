/*
 * Exercise 5.2
 * Write a program that asks the user to type in two integer values at the
 * terminal. Test these two numbers to determine if the first is evenly
 * divisible by the second, and then display an appropriate message at the
 * terminal.
 */

#include<stdio.h>

int main()
{
    int first, second;
    printf("Enter the first number:");
    scanf("%i", &first);
    printf("Enter the second number: ");
    scanf("%i", &second);

    printf("The first number is %sdivisible by the second.\n",
        (first % second) ? "not " : "");
    return 0;
}
