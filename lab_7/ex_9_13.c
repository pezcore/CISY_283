/**
 * Exercise 9.13
 * If c is a lowercase character, the expression
 *
 *  c – 'a' + 'A'
 *
 * produces the uppercase equivalent of c , assuming an ASCII character set.
 * Write a function called uppercase() that converts all lowercase characters
 * in a string into their uppercase equivalents.
 */

#include <stdio.h>

void uppercase(char *);

int main()
{
    char s[] = "ThiS StRinG has mixEd CasE";
    printf("Before uppercase(): \"%s\"\n", s);
    uppercase(s);
    printf("After uppercase(): \"%s\"\n", s);
    return 0;
}

void uppercase(char * s)
{
    while (*s)
    {
        if (*s >= 'a')
            *s += 'A' - 'a';
        s++;
    }
}
