/**
 * Exercise 15.5
 *
 * Write a program that writes columns m through n of each line of a file to
 * stdout. Have the program accept the values of m and n from the terminal
 * window.
 */

#include <stdio.h>
#define BUFFERSIZE 1000

int main()
{
    /* prompt the user for m and n */
    int m, n;
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    printf("You have entered %d for m and %d for n\n\n", m, n);

    /* open the input file as read-only */
    FILE * infile = fopen("datafiles/exercise5.txt", "r");

    /* allocate the char buffer to store the lines */
    char buf[BUFFERSIZE];

    /* for each line in the file read it into buf */
    while (fgets(buf, BUFFERSIZE, infile))
    {
        /* start the read pointer at position m in the line */
        char * cptr = buf + m;

        /* read chars one-by-one from strin until position m passing through */
        while ((cptr < buf + n) && *cptr != '\n')
            putchar(*(cptr++));
        putchar('\n');
    }
    return 0;
}
