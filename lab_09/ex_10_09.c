/**
 * Exercise 10.9
 *
 * Rewrite the `readLine()` function from Chapter 9 so that it uses a character
 * pointer rather than an array.
 */

#include <stdio.h>

void readLine (char * buffer)
{
    int i = 0;
    while ((*(buffer + i++) = getchar())!= '\n')
        ;
    *(buffer + i - 1) = '\0';
}

int main (void)
{
    int i;
    char line[81];
    for (i = 0; i < 3; ++i)
    {
        readLine (line);
        printf("%s\n\n", line);
    }
    return 0;
}
