/*
 * Exercise 5.4
 * Write a program that acts as a simple "printing" calculator. The program
 * should allow the user to type in expressions of the form
 *
 *     number operator
 *
 * the following operators should be recognized by the program:
 *
 * + - * / S E
 *
 * The `S` operator tells the program to set the "accumulator" to the typed-in
 * number. The `E` operator tells the program that execution is to end. The
 * arithmetic operations are performed on the contents of the accumulator with
 * the number that was keyed in acting as the second operand. The following is
 * a "sample run" showing how the program should operate:
 */

#include <stdio.h>

int main()
{
    float number, accumulator = 0;
    char op = 0;
    while (op != 'E')
    {
        scanf("%f", &number);
        scanf(" %c", &op);
        switch (op)
        {
            case '+' :
                accumulator += number;
                break;
            case '-' :
                accumulator -= number;
                break;
            case '*' :
                accumulator *= number;
                break;
            case '/' :
                if (number == 0)
                {
                    printf("You can't divide by zero\n");
                    break;
                }
                accumulator /= number;
                break;
            case 'S' :
                accumulator = number;
                break;
            case 'E' :
                break;
            default :
                printf("operator not recognized.\n");

        }
        printf("accumulator value is %f\n", accumulator);
    }
    printf("Done.\n");
    return 0;
}
