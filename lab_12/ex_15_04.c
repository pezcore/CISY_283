/**
 * Exercise 15.4
 *
 * Write a program that merges lines alternately from two files and writes the
 * results to stdout . If one file has fewer lines than the other, the
 * remaining lines from the larger file should simply be copied to stdout.
 */

#include <stdio.h>
#define BUFFERSIZE 1000

int main()
{
    /* allocate char buffer for storing lines */
    char buf[BUFFERSIZE];

    /* open each of the input files as read-only */
    FILE * f1 = fopen("datafiles/exercise4-letters.txt", "r");
    FILE * f2 = fopen("datafiles/exercise4-numbers.txt", "r");

    /* print lines alternatively while until both files have been exhausted */
    while (!(feof(f1) && feof(f2)))
    {
        /* for each file print the next line if it exists */
        if (fgets(buf, BUFFERSIZE, f1))
            puts(buf);
        if (fgets(buf, BUFFERSIZE, f2))
            puts(buf);
    }
    return 0;
}
