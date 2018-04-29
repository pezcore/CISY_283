/**
 * Exercise 10.10
 *
 * Rewrite the `compareStrings()` function from Chapter 9 to use character
 * pointers instead of arrays.
 */

#include <stdio.h>

int compareStrings(const char* s1, const char* s2)
{
    /* consume from both s1 and s1 until either null char is reached or the
     * characters differ
     */
    while (*s1 && (*s1 == *s2))
        s1++, s2++;

    /* cast to unsigned for portability and compare chars */
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

int main()
{
    /* test the function for accuracy */
    printf("%-30s %d\n", "\"this\" \"this is\"",
        compareStrings("this", "this is"));
    printf("%-30s %d\n", "\"less\" \"more\"", compareStrings("less", "more"));
    printf("%-30s %d\n", "\"more\" \"less\"", compareStrings("more", "less"));
    printf("%-30s %d\n", "\"turly equal\" \"truly equal\"",
        compareStrings("truly equal", "truly equal"));
    return 0;
}
