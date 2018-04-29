/**
 * Exercise 9.11
 * Extend the `strToInt()` function from Program 9.11 so that if the first
 * character of the string is a minus sign, the value that follows is taken as
 * a negative number.
 */

#include <stdio.h>

/* Function to convert a string to an integer, directly copied from text*/
int strToInt (const char string[])
{
    int i, intValue, result = 0;
    for ( i = 0; string[i] >= '0' && string[i] <= '9'; ++i )
    {
        intValue = string[i] - '0';
        result = result * 10 + intValue;
    }
    return result;
}

/* extended to handle negative numbers */
int strToIntExtended(const char string[])
{
    /* based on whether the first char is a '-' return the negative or positive
     * result. If negative result start at position 1 so the '-' is skipped.
     */
    return string[0] == '-' ? -strToInt(string + 1) : strToInt(string);
}

int main (void)
{
    printf ("%i\n", strToIntExtended("245"));
    printf ("%i\n", strToIntExtended("-100") + 25);
    printf ("%i\n", strToIntExtended("13x5"));
    return 0;
}
