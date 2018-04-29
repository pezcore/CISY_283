/**
 * Exercise 15.6
 *
 * Write a program that displays the contents of a file at the terminal 20
 * lines at a time. At the end of each 20 lines, have the program wait for a
 * character to be entered from the terminal. If the character is the letter q,
 * the program should stop the display of the file; any other character
 * should cause the next 20 lines from the file to be displayed.
 */

#include <stdio.h>
#define BUFFERSIZE 1000

int main()
{
    /* declare chars for user response and print-loop iterator */
    unsigned char c, i;

    /* allocate buffer to store the lines read from the input file */
    char buf[BUFFERSIZE];

    /* open the input file for read-only */
    FILE * infile = fopen("datafiles/exercise6.txt", "r");

    /* main loop */
    /* read the user's entered char */
    while (scanf("%c", &c), c != 'q')
        /* while the entered char is not q print 20 lines at a time until the
         * file runs out
         */
        for (i = 0; i < 20 && !feof(infile); ++i)
            printf("%s", fgets(buf, BUFFERSIZE, infile));
    return 0;
}
