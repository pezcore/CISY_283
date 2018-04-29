/**
 * Exercise 15.3
 * Write a program to copy one file to another, replacing all lowercase
 * characters with their uppercase equivalents.
 */

#include <stdio.h>

int main()
{
    /* open the input and output files */
    FILE * infile = fopen("datafiles/exercise3-original.txt", "r");
    FILE * outfile = fopen("datafiles/exercise3-new.txt", "w");
    char c;
    /* read chars from input until it is exhausted */
    while ((c = fgetc(infile)) != EOF)
        /* converting lower to upper is equivalent to clearing bit 0x20 */
        fputc((c >= 'a' && c <= 'z') ? c & ~0x20 : c, outfile);
    return 0;
}
